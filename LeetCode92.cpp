ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *prehead = new ListNode(0);
    prehead->next = head;
    n -= m;
    ListNode *pre = prehead;
    while(--m) pre = pre->next;
    ListNode *start = pre->next; // Reversing the list start from this node.
    while(n--){
        ListNode *next = start->next;
        start->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    
    return prehead->next;
}