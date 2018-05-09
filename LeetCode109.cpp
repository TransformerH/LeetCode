vector<int> convertList(ListNode* head){
    vector<int> list;
    while(head){
        list.push_back(head->val);
        head = head->next;
    }
    return list;
}

TreeNode* buildSubTree(vector<int>& list, int start, int end){
    if(start > end)
        return NULL;
    int middle = (start + end) / 2;
    TreeNode* root = new TreeNode(list[middle]);
    root->left = buildSubTree(list, start, middle - 1);
    root->right = buildSubTree(list, middle + 1, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(!head)
        return NULL;
    vector<int> list = convertList(head);
    int len = (int)list.size();
    return buildSubTree(list, 0, len - 1);
}