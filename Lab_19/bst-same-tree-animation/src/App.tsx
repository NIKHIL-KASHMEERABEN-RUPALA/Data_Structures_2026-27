import React, { useState, useRef, useCallback } from 'react';
import { motion, AnimatePresence } from 'framer-motion';
import { TreeNode } from './types';
import {
  insert,
  generateSameTreeSteps,
  sameTree,
  resetIds,
  getInsertPath,
} from './bst';
import TreeVisualizer from './TreeVisualizer';

const PRESETS = [
  { name: 'Identical', t1: '5 3 7 2 4 6 8', t2: '5 3 7 2 4 6 8' },
  { name: 'Different value', t1: '5 3 7', t2: '5 3 8' },
  { name: 'Different structure', t1: '10 5 15', t2: '10 5 15 12' },
  { name: 'Skewed left', t1: '5 4 3 2 1', t2: '5 4 3 2 1' },
  { name: 'Empty vs Non-empty', t1: '', t2: '1 2 3' },
];

export default function App() {
  const [tree1Input, setTree1Input] = useState(PRESETS[0].t1);
  const [tree2Input, setTree2Input] = useState(PRESETS[0].t2);
  const [root1, setRoot1] = useState<TreeNode | null>(null);
  const [root2, setRoot2] = useState<TreeNode | null>(null);
  const [highlight1, setHighlight1] = useState<Set<string>>(new Set());
  const [highlight2, setHighlight2] = useState<Set<string>>(new Set());
  const [path1, setPath1] = useState<Set<string>>(new Set());
  const [path2, setPath2] = useState<Set<string>>(new Set());
  const [status, setStatus] = useState('Ready — choose a preset or enter custom nodes');
  const [isAnimating, setIsAnimating] = useState(false);
  const [isPaused, setIsPaused] = useState(false);
  const [result, setResult] = useState<boolean | null>(null);
  const [log, setLog] = useState<{ msg: string; type: 'info' | 'ok' | 'fail' | 'step' }[]>([]);
  const [speed, setSpeed] = useState(700); // ms
  const [phase, setPhase] = useState<'idle' | 'building' | 'comparing' | 'done'>('idle');

  const cancelRef = useRef(false);
  const pauseResolve = useRef<(() => void) | null>(null);

  const sleep = useCallback(
    (ms: number) =>
      new Promise<void>((resolve) => {
        const check = () => {
          if (cancelRef.current) {
            resolve();
            return;
          }
          if (isPaused) {
            pauseResolve.current = resolve;
            return;
          }
          setTimeout(resolve, ms);
        };
        check();
      }),
    [isPaused]
  );

  // Resume helper
  React.useEffect(() => {
    if (!isPaused && pauseResolve.current) {
      pauseResolve.current();
      pauseResolve.current = null;
    }
  }, [isPaused]);

  const addLog = (msg: string, type: 'info' | 'ok' | 'fail' | 'step' = 'info') => {
    setLog((prev) => [...prev, { msg, type }]);
  };

  const parseKeys = (str: string) =>
    str
      .trim()
      .split(/[\s,]+/)
      .filter(Boolean)
      .map(Number)
      .filter((n) => !isNaN(n));

  const buildTrees = async () => {
    cancelRef.current = true;
    await new Promise((r) => setTimeout(r, 40));
    cancelRef.current = false;

    resetIds();
    setIsAnimating(true);
    setIsPaused(false);
    setResult(null);
    setLog([]);
    setHighlight1(new Set());
    setHighlight2(new Set());
    setPath1(new Set());
    setPath2(new Set());
    setPhase('building');
    setRoot1(null);
    setRoot2(null);

    const keys1 = parseKeys(tree1Input);
    const keys2 = parseKeys(tree2Input);

    // Build Tree 1
    let r1: TreeNode | null = null;
    setStatus('Building Tree 1…');
    for (const key of keys1) {
      if (cancelRef.current) return;

      const path = getInsertPath(r1, key);
      setPath1(new Set(path));
      addLog(`Insert ${key} into Tree 1`, 'step');

      r1 = insert(r1, key);
      setRoot1(structuredClone(r1));
      await sleep(speed);

      setPath1(new Set());
      await sleep(speed * 0.35);
    }

    // Build Tree 2
    let r2: TreeNode | null = null;
    setStatus('Building Tree 2…');
    for (const key of keys2) {
      if (cancelRef.current) return;

      const path = getInsertPath(r2, key);
      setPath2(new Set(path));
      addLog(`Insert ${key} into Tree 2`, 'step');

      r2 = insert(r2, key);
      setRoot2(structuredClone(r2));
      await sleep(speed);

      setPath2(new Set());
      await sleep(speed * 0.35);
    }

    setRoot1(r1);
    setRoot2(r2);
    setStatus('Trees ready. Click “Compare” to run sameTree()');
    setPhase('idle');
    setIsAnimating(false);
    addLog('Both trees constructed', 'ok');
  };

  const compareTrees = async () => {
    if (phase === 'building') return;

    cancelRef.current = true;
    await new Promise((r) => setTimeout(r, 40));
    cancelRef.current = false;

    setIsAnimating(true);
    setIsPaused(false);
    setResult(null);
    setLog([]);
    setHighlight1(new Set());
    setHighlight2(new Set());
    setPath1(new Set());
    setPath2(new Set());
    setPhase('comparing');
    setStatus('Executing sameTree() recursion…');

    const steps = generateSameTreeSteps(root1, root2);

    for (const step of steps) {
      if (cancelRef.current) return;

      const h1 = new Set<string>();
      const h2 = new Set<string>();
      if (step.node1Id) h1.add(step.node1Id);
      if (step.node2Id) h2.add(step.node2Id);

      setHighlight1(h1);
      setHighlight2(h2);

      const logType = step.result === false ? 'fail' : step.result === true ? 'ok' : 'step';
      addLog(step.message, logType);
      setStatus(step.message);

      await sleep(speed * 1.35);
    }

    const final = sameTree(root1, root2);
    setResult(final);
    setPhase('done');
    setStatus(final ? 'Given trees are same' : 'Given trees are not same');
    addLog(final ? 'Final → Trees are IDENTICAL' : 'Final → Trees are DIFFERENT', final ? 'ok' : 'fail');
    setHighlight1(new Set());
    setHighlight2(new Set());
    setIsAnimating(false);
  };

  const reset = () => {
    cancelRef.current = true;
    setRoot1(null);
    setRoot2(null);
    setHighlight1(new Set());
    setHighlight2(new Set());
    setPath1(new Set());
    setPath2(new Set());
    setStatus('Ready — choose a preset or enter custom nodes');
    setResult(null);
    setLog([]);
    setPhase('idle');
    setIsAnimating(false);
    setIsPaused(false);
  };

  const applyPreset = (p: (typeof PRESETS)[0]) => {
    if (isAnimating) return;
    setTree1Input(p.t1);
    setTree2Input(p.t2);
    reset();
  };

  return (
    <div style={{ maxWidth: 1180, margin: '0 auto', padding: '28px 20px 60px' }}>
      {/* Header */}
      <header style={{ textAlign: 'center', marginBottom: 36 }}>
        <motion.h1
          initial={{ opacity: 0, y: -12 }}
          animate={{ opacity: 1, y: 0 }}
          style={{
            fontSize: 'clamp(1.8rem, 4vw, 2.6rem)',
            fontWeight: 800,
            background: 'linear-gradient(135deg, #22d3ee, #34d399)',
            WebkitBackgroundClip: 'text',
            WebkitTextFillColor: 'transparent',
            letterSpacing: '-0.03em',
          }}
        >
          BST Same Tree Visualizer
        </motion.h1>
        <p style={{ color: 'var(--muted)', marginTop: 8, fontSize: 15 }}>
          Professional animation of recursive insert + sameTree comparison
        </p>
      </header>

      {/* Controls */}
      <div className="glass" style={{ padding: 24, marginBottom: 24 }}>
        <div
          style={{
            display: 'grid',
            gridTemplateColumns: 'repeat(auto-fit, minmax(260px, 1fr))',
            gap: 16,
            marginBottom: 20,
          }}
        >
          <div>
            <label style={{ display: 'block', fontSize: 12, color: 'var(--muted)', marginBottom: 6, fontWeight: 500 }}>
              TREE 1 NODES
            </label>
            <input
              value={tree1Input}
              onChange={(e) => setTree1Input(e.target.value)}
              disabled={isAnimating}
              placeholder="e.g. 5 3 7 2 4 6 8"
            />
          </div>
          <div>
            <label style={{ display: 'block', fontSize: 12, color: 'var(--muted)', marginBottom: 6, fontWeight: 500 }}>
              TREE 2 NODES
            </label>
            <input
              value={tree2Input}
              onChange={(e) => setTree2Input(e.target.value)}
              disabled={isAnimating}
              placeholder="e.g. 5 3 7 2 4 6 8"
            />
          </div>
        </div>

        {/* Presets */}
        <div style={{ display: 'flex', flexWrap: 'wrap', gap: 8, marginBottom: 20 }}>
          {PRESETS.map((p) => (
            <button
              key={p.name}
              onClick={() => applyPreset(p)}
              disabled={isAnimating}
              style={{
                background: 'rgba(34, 211, 238, 0.1)',
                color: 'var(--accent)',
                border: '1px solid rgba(34, 211, 238, 0.25)',
                padding: '7px 14px',
                fontSize: 13,
              }}
            >
              {p.name}
            </button>
          ))}
        </div>

        {/* Action buttons + speed */}
        <div style={{ display: 'flex', flexWrap: 'wrap', gap: 12, alignItems: 'center' }}>
          <button
            onClick={buildTrees}
            disabled={isAnimating}
            style={{
              background: 'linear-gradient(135deg, #0891b2, #0e7490)',
              color: 'white',
              padding: '12px 22px',
            }}
          >
            ▶ Build Trees
          </button>

          <button
            onClick={compareTrees}
            disabled={isAnimating || phase === 'building'}
            style={{
              background: 'linear-gradient(135deg, #059669, #047857)',
              color: 'white',
              padding: '12px 22px',
            }}
          >
            ⚡ Compare (sameTree)
          </button>

          {isAnimating && (
            <button
              onClick={() => setIsPaused((p) => !p)}
              style={{
                background: 'rgba(251, 191, 36, 0.15)',
                color: 'var(--warn)',
                border: '1px solid rgba(251, 191, 36, 0.3)',
                padding: '12px 18px',
              }}
            >
              {isPaused ? '▶ Resume' : '⏸ Pause'}
            </button>
          )}

          <button
            onClick={reset}
            style={{
              background: 'rgba(148, 163, 184, 0.12)',
              color: 'var(--muted)',
              padding: '12px 18px',
            }}
          >
            Reset
          </button>

          <div style={{ marginLeft: 'auto', display: 'flex', alignItems: 'center', gap: 10 }}>
            <span style={{ fontSize: 13, color: 'var(--muted)' }}>Speed</span>
            <input
              type="range"
              min={250}
              max={1400}
              step={50}
              value={1650 - speed}
              onChange={(e) => setSpeed(1650 - Number(e.target.value))}
              style={{ width: 110, padding: 0 }}
              disabled={isAnimating}
            />
          </div>
        </div>
      </div>

      {/* Status banner */}
      <AnimatePresence mode="wait">
        <motion.div
          key={status + String(result)}
          initial={{ opacity: 0, y: 8 }}
          animate={{ opacity: 1, y: 0 }}
          exit={{ opacity: 0 }}
          className="glass"
          style={{
            padding: '16px 22px',
            marginBottom: 24,
            borderColor:
              result === true
                ? 'rgba(52, 211, 153, 0.4)'
                : result === false
                ? 'rgba(248, 113, 113, 0.4)'
                : 'var(--border)',
            background:
              result === true
                ? 'rgba(6, 78, 59, 0.4)'
                : result === false
                ? 'rgba(127, 29, 29, 0.35)'
                : 'var(--card)',
            display: 'flex',
            alignItems: 'center',
            gap: 12,
          }}
        >
          <span style={{ fontSize: 20 }}>
            {result === true ? '✅' : result === false ? '❌' : phase === 'comparing' ? '🔍' : 'ℹ️'}
          </span>
          <span style={{ fontWeight: 600, fontSize: 15 }}>{status}</span>
        </motion.div>
      </AnimatePresence>

      {/* Trees */}
      <div
        style={{
          display: 'flex',
          gap: 20,
          flexWrap: 'wrap',
          justifyContent: 'center',
          marginBottom: 28,
        }}
      >
        <TreeVisualizer
          root={root1}
          highlightIds={highlight1}
          pathIds={path1}
          title="Tree 1"
          width={520}
          height={360}
        />
        <TreeVisualizer
          root={root2}
          highlightIds={highlight2}
          pathIds={path2}
          title="Tree 2"
          width={520}
          height={360}
        />
      </div>

      {/* Log + Algorithm panel */}
      <div
        style={{
          display: 'grid',
          gridTemplateColumns: 'repeat(auto-fit, minmax(320px, 1fr))',
          gap: 20,
        }}
      >
        {/* Live Log */}
        <div className="glass" style={{ padding: 20 }}>
          <h3
            style={{
              fontSize: 13,
              fontWeight: 600,
              color: 'var(--muted)',
              letterSpacing: '0.05em',
              marginBottom: 14,
              textTransform: 'uppercase',
            }}
          >
            Animation Log
          </h3>
          <div
            className="mono"
            style={{
              maxHeight: 260,
              overflowY: 'auto',
              fontSize: 12.5,
              lineHeight: 1.7,
              display: 'flex',
              flexDirection: 'column',
              gap: 4,
            }}
          >
            {log.length === 0 && (
              <div style={{ color: 'var(--muted)' }}>Waiting for animation…</div>
            )}
            {log.map((entry, i) => (
              <motion.div
                key={i}
                initial={{ opacity: 0, x: -8 }}
                animate={{ opacity: 1, x: 0 }}
                style={{
                  color:
                    entry.type === 'ok'
                      ? 'var(--accent2)'
                      : entry.type === 'fail'
                      ? 'var(--danger)'
                      : entry.type === 'step'
                      ? 'var(--warn)'
                      : 'var(--text)',
                }}
              >
                <span style={{ opacity: 0.5, marginRight: 6 }}>→</span>
                {entry.msg}
              </motion.div>
            ))}
          </div>
        </div>

        {/* Algorithm reference */}
        <div className="glass" style={{ padding: 20 }}>
          <h3
            style={{
              fontSize: 13,
              fontWeight: 600,
              color: 'var(--muted)',
              letterSpacing: '0.05em',
              marginBottom: 14,
              textTransform: 'uppercase',
            }}
          >
            sameTree Logic (your C code)
          </h3>
          <pre
            className="mono"
            style={{
              fontSize: 12,
              lineHeight: 1.65,
              color: '#a5b4fc',
              whiteSpace: 'pre-wrap',
            }}
          >{`int sameTree(Node* a, Node* b) {
  if (!a && !b) return 1;          // both NULL
  if (!a || !b) return 0;          // one NULL
  if (a->key != b->key) return 0;  // value differ

  return sameTree(a->left,  b->left)
      && sameTree(a->right, b->right);
}`}</pre>
          <p style={{ marginTop: 14, fontSize: 13, color: 'var(--muted)', lineHeight: 1.6 }}>
            Yellow glow = currently compared nodes<br />
            Cyan trail = insertion path being followed
          </p>
        </div>
      </div>
    </div>
  );
}