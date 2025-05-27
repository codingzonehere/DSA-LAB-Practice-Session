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
        cout << head->data << " "; // Printing data of current node
        head = head->next; // Moving to the next node
    }
    cout << endl;
}
/*
    Insertion in Singly Linked List........
*/
void insertFirst(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
/*
    Insert Node Last..............
*/
void insertLast(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
/*
    Insertion at a Specific Position of the Singly Linked List.........
*/
void insertAnyPos(Node* &head, int pos, int data){
    Node* newNode = new Node(data);
    Node* tmp = head;
    for (int i = 0; i <= pos-1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
}
int main() {
  
    // 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverseList(head);
    insertFirst(head, 5000);
    insertLast(head, 10000);
    traverseList(head);


    return 0;
}