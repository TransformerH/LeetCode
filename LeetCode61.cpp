 ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int len = 1;
        ListNode* newhead = head;
        ListNode* rear = head;
        while(rear->next){
            len++;
            rear = rear->next;
        }
        rear->next = head;
        // 多个circle
        if(k %= len){
            for(int i = 0; i < len-k; i++){
                rear = rear->next;
            }
        }
        // 还是原先的head时
        newhead = rear->next;
        rear->next = NULL;
        return newhead;
    }