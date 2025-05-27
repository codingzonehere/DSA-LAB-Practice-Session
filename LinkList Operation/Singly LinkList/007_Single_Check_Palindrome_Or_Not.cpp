#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int new_data) {
            this->data = new_data;
            this->next = nullptr;
    }
};

/*
    Traverse all element.................
*/
void traverseList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " "; // Printing data of tmp node
        head = head->next; // Moving to the next node
    }
    cout << endl;
}

/*
    Reverse.........
*/
Node* ReverseSingly(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Check if linked list is palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = ReverseSingly(slow->next);

    Node* firstHalf = head;
    Node* tempSecond = secondHalf;
    bool palindrome = true;

    while (tempSecond) {
        if (firstHalf->data != tempSecond->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    slow->next = ReverseSingly(secondHalf);

    return palindrome;
}
int main() {
  
    // 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(40);
    head->next->next->next->next->next = new Node(60);


    cout<<"\nBefore linklist: ";
    traverseList(head);
    cout<<"\nAfter nth: ";
    if (isPalindrome(head))
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is NOT a palindrome.\n";

    traverseList(head);

    return 0;
}