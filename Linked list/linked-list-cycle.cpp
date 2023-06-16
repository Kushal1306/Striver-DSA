class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
        return false;
        ListNode* fast=head;
        ListNode* slow=head;
        bool exist=false;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
           {
               exist=true;
               break;

           }
        }
        return exist;


    }
};
