void preBT(TreeNode* root, vector<TreeNode*>& preList){
    if(!root)
        return;
    preList.push_back(root);
    preBT(root->left, preList);
    preBT(root->right,preList);
}

void flatten(TreeNode* root) {
    if(!root)
        return;
    vector<TreeNode*> preList;
    preBT(root, preList);
    preList.erase(preList.begin());
    TreeNode *temp = root;
    while(!preList.empty()){
        temp->left = NULL;
        temp->right = *preList.begin();
        preList.erase(preList.begin());
        temp = temp->right;
    }
}