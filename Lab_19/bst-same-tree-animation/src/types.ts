export interface TreeNode {
  key: number;
  left: TreeNode | null;
  right: TreeNode | null;
  id: string; // unique id for animation
  x?: number;
  y?: number;
}

export type AnimationStep =
  | { type: 'insert'; tree: 1 | 2; key: number; path: string[] }
  | { type: 'compare'; node1Id: string | null; node2Id: string | null; result: boolean | null; message: string }
  | { type: 'result'; same: boolean };