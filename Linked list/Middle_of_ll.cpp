class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        while(head != NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = length(head);
        int ans = len/2;

        ListNode* temp = head;
        int cnt = 0;
        while(cnt < ans)
        {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};