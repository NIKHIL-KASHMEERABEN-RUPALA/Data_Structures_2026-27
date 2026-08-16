/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class BSTIterator {

    private readonly Stack<TreeNode> _stack;

    public BSTIterator(TreeNode root) {
        _stack = new Stack<TreeNode>();
        PushAllLeft(root);
    }
    
    public int Next() {
        TreeNode curr = _stack.Pop();
        if(curr.right!=null){
            PushAllLeft(curr.right);
        }
        return curr.val;
    }
    
    public bool HasNext() {
        return _stack.Count >0;
    }
    private void PushAllLeft(TreeNode node){
        while(node!=null){
            _stack.Push(node);
            node = node.left;
        }
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */