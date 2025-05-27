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
    nthFromEnd......
*/
void nthFromEnd(Node* &head, int n) {
    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        if (!fast) cout<<"-1"; // if n is bigger than length
        fast = fast->next;
    }

    // Move both one step at a time
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    cout<<slow->data<<endl;
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
    nthFromEnd(head, 3);



    

    
    


    return 0;
}