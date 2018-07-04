// DSF
// ATTENTION: THE VALUE OF A NODE MAY BE A MINUS
 int recursive(TreeNode *root, int& res){
    if(!root)
        return 0;
    int left = max(recursive(root->left, res), 0);
    int right = max(recursive(root->right, res), 0);
    res = max(res, root->val + left + right);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    recursive(root, res);
    return res;
}