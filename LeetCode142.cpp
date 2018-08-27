ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *first = head, *second = head;
        bool hasCircle = false;
        while(first && second){
            first = first->next;
            if(!second->next)
                return NULL;
            second = second->next->next;
            if(first == second){
                hasCircle = true;
                break;
            }
        }
        if(!hasCircle)
            return NULL;
        first = head;
        while(first != second){
            first = first->next;
            second = second->next;
        }
        
        return first;
    }