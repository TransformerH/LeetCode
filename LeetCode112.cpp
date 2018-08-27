  bool calsum(TreeNode* root, int cursum, int sum){
    if(!(root->left || root->right))
        return cursum + root->val == sum;
    cursum += root->val;
       cout << cursum << endl;
    return (root->left && calsum(root->left, cursum, sum))|| (root->right && calsum(root->right, cursum, sum));
    
}

bool hasPathSum(TreeNode* root, int sum) {
    if(!root)
        return false;
    int cursum = 0;
    return calsum(root, cursum, sum);
}