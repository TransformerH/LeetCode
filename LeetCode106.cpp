 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* build(vector<int>& inorder,int is, int ie, vector<int>& postorder, int ps, int pe){
        if(ps > pe)
            return nullptr;
        int pos = 0;
        TreeNode *node = new TreeNode(postorder[pe]);
        for(int i = is; i <= ie; i++){
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = build(inorder, is, pos-1, postorder, ps, ps+pos-is-1);
        node->right = build(inorder, pos+1, ie, postorder, pe+pos-ie, pe-1);
        return node;
    }