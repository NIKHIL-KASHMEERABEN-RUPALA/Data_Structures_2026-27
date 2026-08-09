import React, { useMemo } from 'react';
import { motion, AnimatePresence } from 'framer-motion';
import { TreeNode } from './types';

interface Props {
  root: TreeNode | null;
  highlightIds?: Set<string>;
  pathIds?: Set<string>;
  title: string;
  width?: number;
  height?: number;
}

function layout(root: TreeNode | null, width: number) {
  const pos = new Map<string, { x: number; y: number }>();
  if (!root) return pos;

  const levelGap = 92;

  function leafCount(n: TreeNode | null): number {
    if (!n) return 1;
    if (!n.left && !n.right) return 1;
    return leafCount(n.left) + leafCount(n.right);
  }

  function place(n: TreeNode | null, depth: number, left: number, right: number) {
    if (!n) return;
    const x = (left + right) / 2;
    const y = 48 + depth * levelGap;
    pos.set(n.id, { x, y });

    const lc = leafCount(n.left);
    const rc = leafCount(n.right);
    const total = lc + rc || 1;

    if (n.left) {
      const mid = left + ((right - left) * lc) / total;
      place(n.left, depth + 1, left, mid);
    }
    if (n.right) {
      const mid = left + ((right - left) * lc) / total;
      place(n.right, depth + 1, mid, right);
    }
  }

  place(root, 0, 36, width - 36);
  return pos;
}

export default function TreeVisualizer({
  root,
  highlightIds = new Set(),
  pathIds = new Set(),
  title,
  width = 460,
  height = 380,
}: Props) {
  const positions = useMemo(() => layout(root, width), [root, width]);

  const edges: { id: string; x1: number; y1: number; x2: number; y2: number }[] = [];
  const nodes: { id: string; key: number; x: number; y: number }[] = [];

  function walk(n: TreeNode | null) {
    if (!n) return;
    const p = positions.get(n.id)!;
    nodes.push({ id: n.id, key: n.key, x: p.x, y: p.y });

    if (n.left) {
      const c = positions.get(n.left.id)!;
      edges.push({ id: `${n.id}-L`, x1: p.x, y1: p.y, x2: c.x, y2: c.y });
      walk(n.left);
    }
    if (n.right) {
      const c = positions.get(n.right.id)!;
      edges.push({ id: `${n.id}-R`, x1: p.x, y1: p.y, x2: c.x, y2: c.y });
      walk(n.right);
    }
  }
  walk(root);

  return (
    <div className="glass" style={{ width, padding: '18px 14px 10px', position: 'relative' }}>
      <div
        style={{
          position: 'absolute',
          top: 14,
          left: 18,
          fontSize: 13,
          fontWeight: 600,
          color: 'var(--muted)',
          letterSpacing: '0.04em',
          textTransform: 'uppercase',
        }}
      >
        {title}
      </div>

      <svg width={width - 28} height={height} style={{ display: 'block', margin: '28px auto 0' }}>
        <defs>
          <filter id="glow">
            <feGaussianBlur stdDeviation="3.5" result="coloredBlur" />
            <feMerge>
              <feMergeNode in="coloredBlur" />
              <feMergeNode in="SourceGraphic" />
            </feMerge>
          </filter>
          <linearGradient id="edgeGrad" x1="0%" y1="0%" x2="0%" y2="100%">
            <stop offset="0%" stopColor="#64748b" />
            <stop offset="100%" stopColor="#334155" />
          </linearGradient>
        </defs>

        {/* Edges */}
        <AnimatePresence>
          {edges.map((e) => (
            <motion.line
              key={e.id}
              x1={e.x1}
              y1={e.y1}
              x2={e.x2}
              y2={e.y2}
              stroke="url(#edgeGrad)"
              strokeWidth={2.2}
              strokeLinecap="round"
              initial={{ pathLength: 0, opacity: 0 }}
              animate={{ pathLength: 1, opacity: 1 }}
              exit={{ opacity: 0 }}
              transition={{ duration: 0.45, ease: 'easeOut' }}
            />
          ))}
        </AnimatePresence>

        {/* Nodes */}
        <AnimatePresence>
          {nodes.map((n) => {
            const isHighlight = highlightIds.has(n.id);
            const isPath = pathIds.has(n.id);
            const isActive = isHighlight || isPath;

            return (
              <motion.g
                key={n.id}
                initial={{ scale: 0, opacity: 0 }}
                animate={{ scale: 1, opacity: 1 }}
                exit={{ scale: 0, opacity: 0 }}
                transition={{ type: 'spring', stiffness: 380, damping: 22 }}
              >
                {/* Outer ring for path / highlight */}
                {(isPath || isHighlight) && (
                  <motion.circle
                    cx={n.x}
                    cy={n.y}
                    r={28}
                    fill="none"
                    stroke={isHighlight ? '#fbbf24' : '#22d3ee'}
                    strokeWidth={2}
                    initial={{ scale: 0.6, opacity: 0 }}
                    animate={{ scale: 1.15, opacity: [0.7, 0.2, 0.7] }}
                    transition={{
                      opacity: { repeat: Infinity, duration: 1.4 },
                      scale: { duration: 0.35 },
                    }}
                  />
                )}

                <circle
                  cx={n.x}
                  cy={n.y}
                  r={23}
                  fill={isHighlight ? '#f59e0b' : isPath ? '#0891b2' : '#0e7490'}
                  stroke={isHighlight ? '#fde68a' : isPath ? '#67e8f9' : '#22d3ee'}
                  strokeWidth={isActive ? 3 : 2}
                  filter={isActive ? 'url(#glow)' : undefined}
                  style={{ transition: 'fill 0.3s, stroke 0.3s' }}
                />

                <text
                  x={n.x}
                  y={n.y + 5}
                  textAnchor="middle"
                  fill="#020617"
                  fontWeight="700"
                  fontSize="15"
                  style={{ pointerEvents: 'none' }}
                >
                  {n.key}
                </text>
              </motion.g>
            );
          })}
        </AnimatePresence>
      </svg>
    </div>
  );
}