/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        Node* temp=head;
        int count=1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
            
        }
        return count;
    
    }
};
    