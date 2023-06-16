///Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasCycle = false;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        
        if (!hasCycle)
            return NULL;
        
        // Move slow pointer to the head
        slow = head;
        
        // Move both pointers at the same pace until they meet
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow; // or fast, both will point to the start of the cycle
    }
};
