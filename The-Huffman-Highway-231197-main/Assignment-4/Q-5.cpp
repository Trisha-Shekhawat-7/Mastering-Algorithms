#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
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

    string s , min_string , temp ;  
    cout<<"Enter the string : " ; 
    cin>>s ; 
    int len = s.size() ; 
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
    const int rotation = 1 ;

    min_string = s ; 

    for(char ch : s){
        Node* newNode = new Node(ch);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    for(int k = 1 ; k<len ; k++){
        rotate( &head , rotation) ; 
        Node * curr = head ; 
        temp.clear();
        while(curr){
            temp += curr->data ; 
            curr = curr->next ; 
        }
        min_string = min(temp , min_string ) ;
    } 
    cout<<"Lexicographically smallest string among all possible rotations of "<<s<<" is :"<<min_string ;
    return 0;
}
