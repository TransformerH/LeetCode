 ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *newhead = new ListNode(0);
    newhead->next = new ListNode(head->val);
    head = head->next;
    ListNode *tnewhead;
    while (head) {
        tnewhead = newhead;
        while(tnewhead && tnewhead->next && tnewhead->next->val < head->val){
            tnewhead = tnewhead->next;
        }
        ListNode *node = new ListNode(head->val);
        node->next = tnewhead->next;
        tnewhead->next = node;
        head = head->next;
    }
    
    return newhead->next;
}