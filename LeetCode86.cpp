// two-pointers
ListNode* partition(ListNode* head, int x) {
    ListNode *right = new ListNode(0);
    ListNode *prehead = new ListNode(0);
    prehead->next = head;
    ListNode *temp = prehead;
    ListNode *tempRight = right;
    while(temp->next){
        if(temp->next->val >= x){
            tempRight->next = new ListNode(temp->next->val);
            tempRight = tempRight->next;
            ListNode *next = temp->next->next;
            temp->next = next;
        }else
            temp = temp->next;
    }
    temp->next = right->next;
    return prehead->next;
}