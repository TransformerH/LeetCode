/*
 没做出来，好气哦 :(
 按照高票的思想码了一遍，顺便添加理解和注释
 */

/*
 inorder的特点：
 当前数字的左subList中的数字都是当前数字左子树上的 => 当前数字左subList中的数字遍历完 等于 左子树完成
 */

/*
 preorder的特点：
 当前数字左侧subList中的，是当前数字的父节点或父节点的leftNode，已经加入到nodeStack中了
*/

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || inorder.size() == 0)
        return NULL;
    int pre = 0; // preorder 的index
    int in = 0;  // inorder 的 index
    int lr = 0;  // leftSubtree: 0 or rightSubtree: 1
    stack<TreeNode*> nodeStack; // 遍历过的preorder的node
    
    TreeNode *root = new TreeNode(preorder[0]);
    TreeNode *curNode = root;
    pre++;
    nodeStack.push(root);
    
    while(pre < preorder.size()){
        if(!nodeStack.empty() && nodeStack.top()->val == inorder[in]){
            curNode = nodeStack.top();
            nodeStack.pop();
            lr = 1;
            in++;
        } else {
            if(lr == 0){
                curNode->left = new TreeNode(preorder[pre]);
                curNode = curNode->left;
                nodeStack.push(curNode);
                pre++;
            } else {
                lr = 0;
                curNode->right = new TreeNode(preorder[pre]);
                curNode = curNode->right;
                nodeStack.push(curNode);
                pre++;
            }
        }
    }
    
    return root;
}