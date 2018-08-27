   void depth(TreeNode* root, int& maxDepth, int curDepth){
    if(!root){
        maxDepth = max(maxDepth, curDepth);
        return;
    }
  
    curDepth++;
    depth(root->left, maxDepth, curDepth);
    depth(root->right, maxDepth, curDepth);
}

int maxDepth(TreeNode* root) {
    int maxDepth = 0;
    int curDepth = 0;
    
    depth(root, maxDepth, curDepth);
    return maxDepth;
}