void getLeftLeaves(TreeNode* root, int& sum){
    if(!root)
        return;
    if(root->left && !root->left->left && !root->left->right)
        sum += root->left->val;
    getLeftLeaves(root->left, sum);
    getLeftLeaves(root->right, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    getLeftLeaves(root, sum);
    return sum;
}