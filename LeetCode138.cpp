// without hashtable
 RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *phead, *pnext;
    phead = head;
    while(phead){
        pnext = phead->next;
        RandomListNode *copy = new RandomListNode(phead->label);
        phead->next = copy;
        copy->next = pnext;
        phead = pnext;
    }
    
    phead = head;
    while(phead){
        if(phead->random)
            // phead->random->next, not phead->random
            phead->next->random = phead->random->next;
        phead = phead->next->next;
    }
    
    RandomListNode *pret = new RandomListNode(0);
    RandomListNode *ptemp = pret;
    phead = head;
    while(phead){
        pnext = phead->next;
        
        ptemp->next = pnext;
        ptemp = pnext;
        
        phead->next = pnext->next;
        phead = pnext->next;
    }
    
    return pret->next;
}

// using hashtable
 RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *copy = new RandomListNode(1);
    RandomListNode *pcopy = copy, *phead = head;
    map<RandomListNode*, RandomListNode*> oc;
    
    while (phead) {
        pcopy->next = new RandomListNode(phead->label);
        oc[phead] = pcopy->next;
        pcopy = pcopy->next;
        phead = phead->next;
    }
    
    pcopy = copy;
    phead = head;
    
    pcopy = pcopy->next;
    while (phead && pcopy) {
        if(phead->random)
            pcopy->random = oc[phead->random];
        phead = phead->next;
        pcopy = pcopy->next;
    }
    
    return copy->next;
}