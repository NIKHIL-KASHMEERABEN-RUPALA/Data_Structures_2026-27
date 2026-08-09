import React, { useState, useRef } from 'react';
import { TreeNode } from './types';
import { insert, generateSameTreeSteps, sameTree } from './bst';
import TreeVisualizer from './TreeVisualizer';

export default function App() {
  const [tree1Input, setTree1Input] = useState('5 3 7 2 4 6 8');
  const [tree2Input, setTree2Input] = useState('5 3 7 2 4 6 8');
  const [root1, setRoot1] = useState<TreeNode | null>(null);
  const [root2, setRoot2] = useState<TreeNode | null>(null);
  const [highlight1, setHighlight1] = useState<Set<string>>(new Set());
  const [highlight2, setHighlight2] = useState<Set<string>>(new Set());
  const [status, setStatus] = useState('Enter nodes for both trees and click "Build Trees"');
  const [isAnimating, setIsAnimating] = useState(false);
  const [result, setResult] = useState<boolean | null>(null);
  const [log, setLog] = useState<string[]>([]);
  const cancelRef = useRef(false);

  const sleep = (ms: number) => new Promise((r) => setTimeout(r, ms));

  const buildTrees = async () => {
    cancelRef.current = true;
    await sleep(50);
    cancelRef.current = false;

    setIsAnimating(true);
    setResult(null);
    setLog([]);
    setHighlight1(new Set());
    setHighlight2(new Set());

    // Parse inputs
    const keys1 = tree1Input
      .trim()
      .split(/[\s,]+/)
      .filter(Boolean)
      .map(Number)
      .filter((n) => !isNaN(n));
    const keys2 = tree2Input
      .trim()
      .split(/[\s,]+/)
      .filter(Boolean)
      .map(Number)
      .filter((n) => !isNaN(n));

    // Build tree 1 with animation
    let r1: TreeNode | null = null;
    setStatus('Building Tree 1...');
    for (const key of keys1) {
      if (cancelRef.current) return;
      r1 = insert(r1, key);
      setRoot1({ ...r1 }); // force re-render
      setLog((prev) => [...prev, `Inserted ${key} into Tree 1`]);
      await sleep(600);
    }

    // Build tree 2 with animation
    let r2: TreeNode | null = null;
    setStatus('Building Tree 2...');
    for (const key of keys2) {
      if (cancelRef.current) return;
      r2 = insert(r2, key);
      setRoot2({ ...r2 });
      setLog((prev) => [...prev, `Inserted ${key} into Tree 2`]);
      await sleep(600);
    }

    setRoot1(r1);
    setRoot2(r2);
    setStatus('Trees built. Click "Compare Trees" to run sameTree()');
    setIsAnimating(false);
  };

  const compareTrees = async () => {
    if (!root1 && !root2) {
      setStatus('Build the trees first!');
      return;
    }

    cancelRef.current = true;
    await sleep(50);
    cancelRef.current = false;

    setIsAnimating(true);
    setResult(null);
    setLog([]);
    setHighlight1(new Set());
    setHighlight2(new Set());
    setStatus('Running sameTree() recursively...');

    const steps = generateSameTreeSteps(root1, root2);

    for (const step of steps) {
      if (cancelRef.current) return;

      const h1 = new Set<string>();
      const h2 = new Set<string>();
      if (step.node1Id) h1.add(step.node1Id);
      if (step.node2Id) h2.add(step.node2Id);

      setHighlight1(h1);
      setHighlight2(h2);
      setLog((prev) => [...prev, step.message]);
      setStatus(step.message);

      await sleep(1100);
    }

    // Final result
    const finalSame = sameTree(root1, root2);
    setResult(finalSame);
    setStatus(finalSame ? '✅ Given trees are same' : '❌ Given trees are not same');
    setLog((prev) => [...prev, finalSame ? 'Final Result: Trees are SAME' : 'Final Result: Trees are NOT same']);
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
    setStatus('Enter nodes for both trees and click "Build Trees"');
    setResult(null);
    setLog([]);
    setIsAnimating(false);
  };

  return (
    <div style={{ maxWidth: 1100, margin: '0 auto' }}>
      <h1 style={{ textAlign: 'center', marginBottom: 8, fontSize: 28, color: '#38bdf8' }}>
        BST Same Tree Animation
      </h1>
      <p style={{ textAlign: 'center', color: '#94a3b8', marginBottom: 24 }}>
        Visualizes the exact logic of your C code (insert + sameTree)
      </p>

      {/* Controls */}
      <div className="card" style={{ marginBottom: 24 }}>
        <div style={{ display: 'flex', gap: 16, flexWrap: 'wrap', marginBottom: 16 }}>
          <div style={{ flex: 1, minWidth: 260 }}>
            <label style={{ display: 'block', marginBottom: 6, color: '#94a3b8' }}>
              Tree 1 nodes (space separated)
            </label>
            <input
              style={{ width: '100%' }}
              value={tree1Input}
              onChange={(e) => setTree1Input(e.target.value)}
              disabled={isAnimating}
              placeholder="e.g. 5 3 7 2 4 6 8"
            />
          </div>
          <div style={{ flex: 1, minWidth: 260 }}>
            <label style={{ display: 'block', marginBottom: 6, color: '#94a3b8' }}>
              Tree 2 nodes (space separated)
            </label>
            <input
              style={{ width: '100%' }}
              value={tree2Input}
              onChange={(e) => setTree2Input(e.target.value)}
              disabled={isAnimating}
              placeholder="e.g. 5 3 7 2 4 6 8"
            />
          </div>
        </div>

        <div style={{ display: 'flex', gap: 12, flexWrap: 'wrap' }}>
          <button
            onClick={buildTrees}
            disabled={isAnimating}
            style={{ background: '#0ea5e9', color: '#0f172a' }}
          >
            1. Build Trees
          </button>
          <button
            onClick={compareTrees}
            disabled={isAnimating || (!root1 && !root2)}
            style={{ background: '#22c55e', color: '#0f172a' }}
          >
            2. Compare (sameTree)
          </button>
          <button
            onClick={reset}
            style={{ background: '#64748b', color: 'white' }}
          >
            Reset
          </button>
        </div>
      </div>

      {/* Status */}
      <div
        className="card"
        style={{
          marginBottom: 20,
          background: result === true ? '#14532d' : result === false ? '#7f1d1d' : '#1e293b',
          borderColor: result === true ? '#22c55e' : result === false ? '#ef4444' : '#334155',
        }}
      >
        <strong style={{ fontSize: 16 }}>{status}</strong>
      </div>

      {/* Trees side by side */}
      <div style={{ display: 'flex', gap: 20, flexWrap: 'wrap', justifyContent: 'center', marginBottom: 24 }}>
        <TreeVisualizer
          root={root1}
          highlightIds={highlight1}
          title="Tree 1 (root1)"
          width={480}
          height={340}
        />
        <TreeVisualizer
          root={root2}
          highlightIds={highlight2}
          title="Tree 2 (root2)"
          width={480}
          height={340}
        />
      </div>

      {/* Animation Log */}
      <div className="card">
        <h3 style={{ marginBottom: 12, color: '#94a3b8' }}>Animation Log (sameTree recursion)</h3>
        <div
          style={{
            maxHeight: 220,
            overflowY: 'auto',
            fontFamily: 'monospace',
            fontSize: 13,
            lineHeight: 1.6,
          }}
        >
          {log.length === 0 && <div style={{ color: '#64748b' }}>No steps yet...</div>}
          {log.map((line, i) => (
            <div key={i} style={{ color: i === log.length - 1 ? '#fbbf24' : '#cbd5e1' }}>
              → {line}
            </div>
          ))}
        </div>
      </div>

      {/* Explanation */}
      <div className="card" style={{ marginTop: 24, fontSize: 14, color: '#94a3b8' }}>
        <h3 style={{ color: '#e2e8f0', marginBottom: 10 }}>How it matches your C code</h3>
        <ul style={{ paddingLeft: 20, lineHeight: 1.7 }}>
          <li><code>newNode()</code> → creates node with key + left/right = null</li>
          <li><code>insert()</code> → recursive insertion (duplicates ignored)</li>
          <li><code>sameTree()</code> → recursive comparison of structure + values</li>
          <li>Yellow glow = currently compared nodes during recursion</li>
        </ul>
      </div>
    </div>
  );
}