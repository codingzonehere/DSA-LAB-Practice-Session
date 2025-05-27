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
    Remove duplicate...
*/
void removeDuplicates(Node* &head) {
    Node* tmp = head;

    while (tmp != nullptr && tmp->next != nullptr) {
        if (tmp->data == tmp->next->data) {
            // Duplicate found, remove next node
            Node* del = tmp->next;
            tmp->next = tmp->next->next;
            delete del;
        } else {
            tmp = tmp->next;
        }
    }
}

/*
    Reverse Singly Linked List........
*/
void ReverseSingly(Node* &head){
    if(head == nullptr) return;
    ReverseSingly(head->next);
    cout<<head->data<<" -> ";
}

int main() {
  
    // 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(40);
    head->next->next->next->next->next = new Node(60);

    // Delete first......
    cout<<"\nBefore reverse: ";
    traverseList(head);
    cout<<"\nAfter reverse: ";
    ReverseSingly(head);


    cout<<"\nBefore duplicate: ";
    traverseList(head);
    removeDuplicates(head);
    cout<<"After remove duplicate: ";
    traverseList(head);
    

    
    


    return 0;
}