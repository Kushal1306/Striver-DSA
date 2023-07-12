 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
//         assuming list1->val is smaller
        ListNode *small = list1;
        ListNode *large = list2;
//         assigning small to whichever is smaller
        if(list1->val > list2->val)
            swap(small, large);
        ListNode *head = small;
        while(small != NULL && large != NULL)
        {
            ListNode *temp =NULL;
            while(small != NULL && small->val <= large->val)
            { 
                temp = small;
                small = small->next;
            }
            temp->next = large;
            swap(small, large);
        }
        return head;
    }
