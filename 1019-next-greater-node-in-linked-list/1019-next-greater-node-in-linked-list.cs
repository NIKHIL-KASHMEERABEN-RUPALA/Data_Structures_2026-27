/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public int[] NextLargerNodes(ListNode head) {
        List<int> values = new List<int>();
        ListNode curr = head;
        while(curr!=null){
            values.Add(curr.val);
            curr = curr.next;
        }
        int n = values.Count;
        int[] result = new int[n];
        Stack<int> stack = new Stack<int>();
        for(int i = 0 ; i < n ; i++){
            while(stack.Count>0 && values[i]>values[stack.Peek()]){
                int index = stack.Pop();
                result[index] = values[i];
            }
            stack.Push(i);
        }
        return result;
    }
}