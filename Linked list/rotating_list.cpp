class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int length = 1;
        ListNode* tail = head;

        // Find the length of the list and the tail node
        while (tail->next != NULL) {
            tail = tail->next;
            length++;
        } 

        // Adjust the value of k to the effective number of rotations
        k = k % length;
        if (k == 0)
            return head;

        // Connect the tail node to the head node to form a circular list
        tail->next = head;

        // Find the new tail node and break the circular list at the appropriate position
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // Update the head node and break the link at the new tail node
        head = newTail->next;
        newTail->next = NULL;

        return head;
    }
};
