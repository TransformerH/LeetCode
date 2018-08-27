  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> level;
    level.push(root);
    int res = 0;
    while(!level.empty()){
        res = level.front()->val;
        int size = (int)level.size();
        for(int i = 0; i < size; i++){
            TreeNode* top = level.front();
            level.pop();
            if(top->left)
                level.push(top->left);
            if(top->right)
                level.push(top->right);
        }     
    }
    return res;
}