export interface TreeNode {
  key: number;
  left: TreeNode | null;
  right: TreeNode | null;
  id: string;
}

export interface CompareStep {
  type: 'compare';
  node1Id: string | null;
  node2Id: string | null;
  result: boolean | null;
  message: string;
  depth: number;
}