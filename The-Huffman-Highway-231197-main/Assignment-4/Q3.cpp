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

struct Node *reverseList(const struct Node *head) {
    struct Node *prev = nullptr;
    struct Node *current = const_cast<struct Node *>(head);
    struct Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool areIdentical(struct Node *head1, struct Node *head2) {
    struct Node *iterator1 = head1;
    struct Node *iterator2 = head2;

    while (iterator1 && iterator2) {
        if (iterator1->data != iterator2->data)
            return false;
        iterator1 = iterator1->next;
        iterator2 = iterator2->next;
    }

    return (iterator1 == nullptr && iterator2 == nullptr);
}

bool isPalindrome(struct Node *head) {
    struct Node *copyHead = nullptr;
    struct Node *copyTail = nullptr;
    const struct Node *curr = head;

    while (curr != nullptr) {
        struct Node *newNode = new struct Node(curr->data);
        if (copyHead == nullptr) {
            copyHead = copyTail = newNode;
        } else {
            copyTail->next = newNode;
            copyTail = newNode;
        }
        curr = curr->next;
    }

    struct Node *rev_list = reverseList(copyHead);

    bool result = areIdentical(const_cast<struct Node *>(head), rev_list);

    while (copyHead != nullptr) {
        struct Node *temp = copyHead;
        copyHead = copyHead->next;
        delete temp;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cout << "Enter the string you want to test for palindrome: ";
    cin >> s;
    cout << endl;

    struct Node *head = nullptr;
    struct Node *tail = nullptr;
    

    for (char ch : s) {
        Node* newNode = new Node(ch);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

  
    if (isPalindrome(head))
        cout << "The string is a palindrome.\n";
    else
        cout << "The string is not a palindrome.\n";


    return 0;
}
