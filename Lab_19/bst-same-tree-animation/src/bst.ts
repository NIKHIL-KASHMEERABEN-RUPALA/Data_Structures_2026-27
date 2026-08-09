import { TreeNode } from './types';

let idCounter = 0;
const nextId = () => `n${++idCounter}`;

export function newNode(item: number): TreeNode {
  return {
    key: item,
    left: null,
    right: null,
    id: nextId(),
  };
}

export function insert(node: TreeNode | null, key: number): TreeNode {
  if (node === null) return newNode(key);
  if (node.key === key) return node; // duplicate ignore

  if (node.key < key) {
    node.right = insert(node.right, key);
  } else {
    node.left = insert(node.left, key);
  }
  return node;
}

export function sameTree(
  root1: TreeNode | null,
  root2: TreeNode | null
): boolean {
  if (root1 === null && root2 === null) return true;
  if (root1 === null || root2 === null) return false;
  if (root1.key !== root2.key) return false;
  return sameTree(root1.left, root2.left) && sameTree(root1.right, root2.right);
}

// For animation we generate steps
export function generateSameTreeSteps(
  root1: TreeNode | null,
  root2: TreeNode | null
): { type: 'compare'; node1Id: string | null; node2Id: string | null; result: boolean | null; message: string }[] {
  const steps: any[] = [];

  function helper(n1: TreeNode | null, n2: TreeNode | null): boolean {
    if (n1 === null && n2 === null) {
      steps.push({
        type: 'compare',
        node1Id: null,
        node2Id: null,
        result: true,
        message: 'Both NULL → identical at this position',
      });
      return true;
    }
    if (n1 === null || n2 === null) {
      steps.push({
        type: 'compare',
        node1Id: n1?.id ?? null,
        node2Id: n2?.id ?? null,
        result: false,
        message: 'One is NULL, other is not → trees differ',
      });
      return false;
    }
    if (n1.key !== n2.key) {
      steps.push({
        type: 'compare',
        node1Id: n1.id,
        node2Id: n2.id,
        result: false,
        message: `Keys differ: ${n1.key} ≠ ${n2.key}`,
      });
      return false;
    }

    steps.push({
      type: 'compare',
      node1Id: n1.id,
      node2Id: n2.id,
      result: null,
      message: `Comparing nodes ${n1.key} == ${n2.key} → checking subtrees...`,
    });

    const leftSame = helper(n1.left, n2.left);
    if (!leftSame) return false;

    const rightSame = helper(n1.right, n2.right);
    return rightSame;
  }

  helper(root1, root2);
  return steps;
}