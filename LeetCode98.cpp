 //BST : leftChild < root < rightChild
 bool isValidBST(TreeNode* root) {
    if(!root)
        return true;
    stack<TreeNode*> nodeStack;
    TreeNode *pre = NULL;
    while(root || !nodeStack.empty()){
        while(root){
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        if(pre && root->val <= pre->val)
            return false;
        pre = root;
        root = root->right;
    }
    return true;
}