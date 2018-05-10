int countNodes(TreeNode* root) {
    if(!root)
        return 0;
    TreeNode *left = root;
    TreeNode *right = root;
    int leftCount = 0;
    int rightCount = 0;
    while(left){
        leftCount++;
        left = left->left;
    }
    while(right){
        rightCount++;
        right = right->right;
    }
    if(leftCount == rightCount)
        return pow(2, leftCount) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
