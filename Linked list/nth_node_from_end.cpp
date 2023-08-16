 int getNthFromLast(Node *head, int n)
    {
           // Your code here
            Node* dummy = new Node(-1); // Providing a default value for the dummy node
        dummy->next = head;
        Node* slow = dummy;
        Node* fast = dummy;

        // Move 'fast' pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            if (fast == nullptr) {
                // If 'fast' pointer reaches the end, n is greater than the number of nodes in the linked list
                return -1;
            }
            fast = fast->next;
        }

        // Move both pointers until 'fast' pointer reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 'slow' points to the n+1-th node from the end, so the n-th node from the end will be 'slow->next'
        return slow->next->data;
    }