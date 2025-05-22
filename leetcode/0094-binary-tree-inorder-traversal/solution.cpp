class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }

            root = stack.top();
            stack.pop();
            result.push_back(root -> val);
            root = root -> right;
        }
        return result;        
    }
};