import { TreeNode, CompareStep } from './types';

let idCounter = 0;
const nextId = () => `n${++idCounter}`;

export function resetIds() {
  idCounter = 0;
}

export function newNode(item: number): TreeNode {
  return { key: item, left: null, right: null, id: nextId() };
}

export function insert(node: TreeNode | null, key: number): TreeNode {
  if (node === null) return newNode(key);
  if (node.key === key) return node;
  if (node.key < key) {
    node.right = insert(node.right, key);
  } else {
    node.left = insert(node.left, key);
  }
  return node;
}

export function sameTree(root1: TreeNode | null, root2: TreeNode | null): boolean {
  if (root1 === null && root2 === null) return true;
  if (root1 === null || root2 === null) return false;
  if (root1.key !== root2.key) return false;
  return sameTree(root1.left, root2.left) && sameTree(root1.right, root2.right);
}

export function generateSameTreeSteps(
  root1: TreeNode | null,
  root2: TreeNode | null
): CompareStep[] {
  const steps: CompareStep[] = [];

  function helper(n1: TreeNode | null, n2: TreeNode | null, depth: number): boolean {
    if (n1 === null && n2 === null) {
      steps.push({
        type: 'compare',
        node1Id: null,
        node2Id: null,
        result: true,
        message: `Both NULL → match (depth ${depth})`,
        depth,
      });
      return true;
    }

    if (n1 === null || n2 === null) {
      steps.push({
        type: 'compare',
        node1Id: n1?.id ?? null,
        node2Id: n2?.id ?? null,
        result: false,
        message: `Structure mismatch — one side is NULL (depth ${depth})`,
        depth,
      });
      return false;
    }

    if (n1.key !== n2.key) {
      steps.push({
        type: 'compare',
        node1Id: n1.id,
        node2Id: n2.id,
        result: false,
        message: `Value mismatch: ${n1.key} ≠ ${n2.key}`,
        depth,
      });
      return false;
    }

    steps.push({
      type: 'compare',
      node1Id: n1.id,
      node2Id: n2.id,
      result: null,
      message: `Keys match (${n1.key}) → checking left & right subtrees`,
      depth,
    });

    const leftOk = helper(n1.left, n2.left, depth + 1);
    if (!leftOk) return false;

    return helper(n1.right, n2.right, depth + 1);
  }

  helper(root1, root2, 0);
  return steps;
}

/** Returns the path of node ids from root to the insertion point */
export function getInsertPath(root: TreeNode | null, key: number): string[] {
  const path: string[] = [];
  let curr = root;
  while (curr) {
    path.push(curr.id);
    if (curr.key === key) break;
    curr = curr.key < key ? curr.right : curr.left;
  }
  return path;
}