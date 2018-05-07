// original method
void connect(TreeLinkNode *root) {
    if(!root)
        return;
    vector<TreeLinkNode*> floor;
    floor.push_back(root);
    
    while(!floor.empty()){
        TreeLinkNode* left = NULL;
        vector<TreeLinkNode*> curFloor;
        while(!floor.empty()){
            TreeLinkNode* curNode = floor[0];
            floor.erase(floor.begin());
            if(left)
                left->next = curNode;
            left = curNode;
            if(curNode->left)
                curFloor.push_back(curNode->left);
            if(curNode->right)
                curFloor.push_back(curNode->right);
        }
        floor = curFloor;
    }
}

// Most votes Cpp solution
void connect(TreeLinkNode *root) {
    if(!root)
        return;
    while(root->left){
        TreeLinkNode *temp = root;
        while(temp){
            temp->left->next = temp->right;
            if(temp->next)
                temp->right->next = temp->next->left;
            temp = temp->next;
        }
        root = root->left;
    }
}
