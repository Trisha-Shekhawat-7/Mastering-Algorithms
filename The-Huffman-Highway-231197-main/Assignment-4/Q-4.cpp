#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void rotate(Node** head_ptr, int k) 
{ 
    //If k is 0 , already rotateed 
    if (k == 0) 
        return; 
  
    Node* curr = *head_ptr; 
  
    //Reach the (k-1)th node 
    int cnt = 1; 
    while (cnt< k && curr != NULL) { 
        curr= curr->next; 
        cnt++; 
    } 
  
    //If length of linked list < k , we cannot rotate it 
    if (curr == NULL) 
        return; 
  
    Node* kthNode = curr; 
  
    while (curr->next != NULL) 
        curr = curr->next; 
  
    //We  link the first k elements to the last element of the link list 
    curr->next = *head_ptr; 
    *head_ptr= kthNode->next; 
    kthNode->next = NULL; 
}

void printList( struct Node * head){
    while(head){
        cout<<head->data<<" " ; 
        head = head->next ;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x , length , k; 
    cout<<"Enter the size of your linked list : " ; 
    cin>>length ; 
    cout<<"\nEnter the length by which you want to rotate the list : " ;
    cin>>k ;
    cout<<"\nEnter the numbers of your linked list : " ; 
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
    

    while(length -- ){
        cin>>x ; 
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    rotate(&head , k ) ; 
    cout<<"Your linked list rotated by "<<k<<" spaces is : " ; 
    printList(head) ;
    return 0;
}
