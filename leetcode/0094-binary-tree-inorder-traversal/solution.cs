public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        List<int> result = new List<int>();

        while (root != null || stack.Count() > 0) {
            while (root != null) {
                stack.Push(root);
                root = root.left;
            }
            root = stack.Pop();
            result.Add(root.val);
            root = root.right;
        }
        return result;        
    }
}