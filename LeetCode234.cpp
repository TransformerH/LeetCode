  bool isPalindrome(ListNode* head) {
    if(!head)
        return true;
    vector<int> list;
    while(head){
        list.push_back(head->val);
        head = head->next;
    }
    int front = 0;
    int rear = (int)list.size()-1;
    while (front <= rear) {
        if(list[front] != list[rear])
            return false;
        front++;
        rear--;
    }
    return true;
}