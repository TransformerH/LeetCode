vector<vector<int>> zigzagLevelOrder(TreeNode* root) {      
    vector<vector<int>> res;
     if(!root)
         return res;
    bool leftToRight = false;
    stack<TreeNode*> level;
    level.push(root);
    vector<int> rootLevel;
    rootLevel.push_back(root->val);
    res.push_back(rootLevel);
    while(!level.empty()){
        stack<TreeNode*> currentLevel;
        vector<int> levelValue;
        while(!level.empty()){
            TreeNode *node = level.top();
            level.pop();
            if(leftToRight){
                if(node->left){
                    currentLevel.push(node->left);
                    levelValue.push_back(node->left->val);
                }
                if(node->right){
                    currentLevel.push(node->right);
                    levelValue.push_back(node->right->val);
                }
            }else {
                if(node->right){
                    currentLevel.push(node->right);
                    levelValue.push_back(node->right->val);
                }
                if(node->left){
                    currentLevel.push(node->left);
                    levelValue.push_back(node->left->val);
                }
            }
        }
        if(levelValue.size() != 0)
            res.push_back(levelValue);
        level = currentLevel;
        leftToRight = !leftToRight;
    }
    
    return res;
}

