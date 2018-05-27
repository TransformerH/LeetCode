ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *rehead = head;
    ListNode *quick = head;
    ListNode *slow = head;
    int count = 0;
    while(quick){
        quick = quick->next;
        count++;
        if(quick){
            count++;
            quick = quick->next;
            slow = slow->next;
        }
    }
    count -= n;
    if(count == 0)
        return rehead->next;
    while(--count){
        head = head->next;
    }
    ListNode *next = head->next;
    head->next = next->next;
    return rehead;
}