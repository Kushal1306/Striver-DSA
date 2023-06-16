

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


/*deleteing xth node of the linked list*/
Node* deleteNode(Node* head, int x)
{
    if (head == nullptr)
        return nullptr;

    if (x == 1) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < x - 1) {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr && temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    return head;
}
