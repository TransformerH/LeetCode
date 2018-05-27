ListNode* deleteDuplicates(ListNode* head) {
    ListNode *prehead = new ListNode(0);
    prehead->next = head;
    
    ListNode *pre = prehead;
    ListNode *start = pre->next;
    while(start){
        while(start->next && start->next->val == start->val){
            cout << "dup: " << start->val << " " << start->next->val << endl;
            start = start->next;
            pre->next = start->next;
        }
      
        if(pre->next && pre->next->val == start->val)
            pre = start;
        start = start->next;
        
    }
    
    return prehead->next;
}