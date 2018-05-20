void connect(TreeLinkNode *root) {
    while(root){
        TreeLinkNode *temp = root;
        while(temp){
            TreeLinkNode* nextTemp = NULL;
            TreeLinkNode* rootNext = temp->next;
            while(rootNext){
                if(rootNext->left){
                    nextTemp = rootNext->left;
                    break;
                }
                else if(rootNext->right){
                    nextTemp = rootNext->right;
                    break;
                }
                else
                    rootNext = rootNext->next;
            }
            if(temp->left){
                if(temp->right)
                    temp->left->next = temp->right;
                else
                    temp->left->next = nextTemp;
            }
            if(temp->right){
                temp->right->next = nextTemp;
            }
            temp = temp->next;
        }
         while(root){
            if(root->left){
                root = root->left;
                break;
            }
            if(root->right){
                root = root->right;
                break;
            }
            root = root->next;
        }
    }
}

