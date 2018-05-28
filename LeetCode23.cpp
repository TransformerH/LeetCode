// time limited - merge sort
   ListNode* pointers(ListNode *list1, ListNode *list2){
    ListNode *pre = NULL;
    ListNode *res = new ListNode(0);
    pre = res;
    while(list1 && list2){
        if(list1->val < list2->val){
            res->next = new ListNode(list1->val);
            res = res->next;
            list1 = list1->next;
        } else if(list1->val > list2->val){
            res->next = new ListNode(list2->val);
            res = res->next;
            list2 = list2->next;
        } else {
            res->next = new ListNode(list1->val);
            res = res->next;
            res->next = new ListNode(list2->val);
            res = res->next;
            list1 = list1->next;
            list2 = list2->next;
        }
    }
    while(list1){
        res->next = new ListNode(list1->val);
        res = res->next;
        list1 = list1->next;
    }
    while(list2){
        res->next = new ListNode(list2->val);
        res = res->next;
        list2 = list2->next;
    }
    return pre->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0)
        return NULL;
    ListNode *res = lists[0];
    for(int i = 0; i < lists.size() - 1; i++){
        res = pointers(res, lists[i+1]);
    }
    
    return res;
}

// solution  merge sort recursion
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    if(list1->val < list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0)
        return NULL;
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    
    return lists.front();
}
