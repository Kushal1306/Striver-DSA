class Solution {
public:
   ListNode* removeElements(ListNode* head, int target) {
    ListNode* dummy = new ListNode(); // Create a dummy node
    dummy->next = head; // Link the dummy node to the head of the list

    ListNode* curr = dummy;

    while (curr->next != NULL) {
        if (curr->next->val == target) {
            ListNode* temp = curr->next;
            curr->next = temp->next; // Update the next pointer of the current node (dummy node)
            delete temp; // Delete the current node
        } else {
            curr = curr->next;
        }
    }

    head = dummy->next; // Update the head of the list
    delete dummy; // Delete the dummy node

    return head;
}
};