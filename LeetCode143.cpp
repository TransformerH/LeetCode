void reorderList(ListNode* head) {
    if(!head || !head->next)
        return;
    ListNode *l1 = head, *l2 = head;
    while(l2->next && l2->next->next){
        l1 = l1->next;
        l2 = l2->next->next;
    }
    
    ListNode *middle = l1;
    ListNode *precurrent = l1->next;
    ListNode *current;
    while(precurrent->next){
        current = precurrent->next;
        precurrent->next = current->next;
        current->next = middle->next;
        middle->next = current;
    }
    
    ListNode *front= head;
    ListNode *back = middle->next;
    while (front != middle) {
        middle->next = back->next;
        back->next = front->next;
        front->next = back;
        front = back->next;
        back = middle->next;
    }
}