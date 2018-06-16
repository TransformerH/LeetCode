// LC92
ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode *prehead = new ListNode(0);
    prehead->next = head;
    n -= m;
    ListNode *pretemp = prehead;
    while(--m)
        pretemp = pretemp->next;
    ListNode *start = pretemp->next;
    while(n--){
        ListNode *next = start->next;
        start->next = next->next;
        next->next = pretemp->next;
        pretemp->next = next;
    }
    return prehead->next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int len = 0;
    ListNode *prehead = new ListNode(0);
    prehead->next = head;
    ListNode *pre = prehead;
    ListNode *temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    int group = len / k;
    for(int i = 0; i < group; i++){
        pre->next = reverseBetween(pre->next, 1+i*k, k*(i+1));
    }
    return  prehead->next;
}