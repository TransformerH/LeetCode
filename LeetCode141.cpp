 bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *quicker = head, *slower = head;
        while(quicker->next && quicker->next->next ){
            quicker = quicker->next->next;
            slower = slower->next;
            if(quicker == slower)
                return true;
        }
        return false;
    }