import React, { useMemo } from 'react';
import { TreeNode } from './types';

interface Props {
  root: TreeNode | null;
  highlightIds?: Set<string>;
  title: string;
  width?: number;
  height?: number;
}

function layoutTree(root: TreeNode | null, width: number, height: number) {
  if (!root) return new Map<string, { x: number; y: number }>();

  const positions = new Map<string, { x: number; y: number }>();
  const levelGap = 90;
  const nodeGap = 70;

  function countLeaves(node: TreeNode | null): number {
    if (!node) return 1;
    if (!node.left && !node.right) return 1;
    return countLeaves(node.left) + countLeaves(node.right);
  }

  function place(node: TreeNode | null, depth: number, left: number, right: number) {
    if (!node) return;
    const x = (left + right) / 2;
    const y = 50 + depth * levelGap;
    positions.set(node.id, { x, y });

    const leftCount = countLeaves(node.left);
    const rightCount = countLeaves(node.right);
    const total = leftCount + rightCount;

    if (node.left) {
      const mid = left + (right - left) * (leftCount / total);
      place(node.left, depth + 1, left, mid);
    }
    if (node.right) {
      const mid = left + (right - left) * (leftCount / total);
      place(node.right, depth + 1, mid, right);
    }
  }

  place(root, 0, 40, width - 40);
  return positions;
}

export default function TreeVisualizer({
  root,
  highlightIds = new Set(),
  title,
  width = 480,
  height = 360,
}: Props) {
  const positions = useMemo(() => layoutTree(root, width, height), [root, width, height]);

  const edges: { x1: number; y1: number; x2: number; y2: number }[] = [];
  const nodes: { id: string; key: number; x: number; y: number }[] = [];

  function traverse(node: TreeNode | null) {
    if (!node) return;
    const pos = positions.get(node.id)!;
    nodes.push({ id: node.id, key: node.key, x: pos.x, y: pos.y });

    if (node.left) {
      const childPos = positions.get(node.left.id)!;
      edges.push({ x1: pos.x, y1: pos.y, x2: childPos.x, y2: childPos.y });
      traverse(node.left);
    }
    if (node.right) {
      const childPos = positions.get(node.right.id)!;
      edges.push({ x1: pos.x, y1: pos.y, x2: childPos.x, y2: childPos.y });
      traverse(node.right);
    }
  }

  traverse(root);

  return (
    <div className="card" style={{ width }}>
      <h3 style={{ marginBottom: 12, color: '#38bdf8', fontSize: 16 }}>{title}</h3>
      <svg width={width - 40} height={height} style={{ display: 'block', margin: '0 auto' }}>
        {/* edges */}
        {edges.map((e, i) => (
          <line
            key={i}
            x1={e.x1}
            y1={e.y1}
            x2={e.x2}
            y2={e.y2}
            stroke="#64748b"
            strokeWidth={2}
          />
        ))}

        {/* nodes */}
        {nodes.map((n) => {
          const isHighlighted = highlightIds.has(n.id);
          return (
            <g key={n.id}>
              <circle
                cx={n.x}
                cy={n.y}
                r={22}
                fill={isHighlighted ? '#f59e0b' : '#0ea5e9'}
                stroke={isHighlighted ? '#fbbf24' : '#38bdf8'}
                strokeWidth={isHighlighted ? 4 : 2}
                style={{
                  transition: 'all 0.3s ease',
                  filter: isHighlighted ? 'drop-shadow(0 0 8px #f59e0b)' : 'none',
                }}
              />
              <text
                x={n.x}
                y={n.y + 5}
                textAnchor="middle"
                fill="#0f172a"
                fontWeight="700"
                fontSize="14"
              >
                {n.key}
              </text>
            </g>
          );
        })}
      </svg>
    </div>
  );
}