 int getMax(TreeNode* root, int& maxLen){
        if(!root)
            return 0;
        int left = getMax(root->left, maxLen);
        int right = getMax(root->right, maxLen);
        maxLen = max(maxLen, left+right);
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getMax(root, res);
        return res;
    }