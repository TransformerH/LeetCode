  int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    int shortest = 0;
    stack<TreeNode*> level;
    level.push(root);
    while(!level.empty()){
        shortest++;
        stack<TreeNode*> temp;
        while(!level.empty()){
            TreeNode *current = level.top();
            level.pop();
            if(!current->left && !current->right)
                return shortest;
            if(current->left)
                temp.push(current->left);
            if(current->right)
                temp.push(current->right);
        }
        level = temp;
    }
    
    return shortest;
}