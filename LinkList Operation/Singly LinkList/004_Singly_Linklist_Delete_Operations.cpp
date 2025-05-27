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
    Delete first in Singly Linked List........
*/
void deleteFirst(Node* &head){
    Node* tmp = head;
    head = head->next;
    delete tmp;
}
/*
    Delete Node Last..............
*/
void deleteLast(Node* &head){
    Node* tmp = head;
    while(tmp->next->next != nullptr){
        tmp = tmp->next;
    }
    delete (tmp->next);
    tmp->next = NULL;
}
/*
    Delete at a Specific Position of the Singly Linked List.........
*/
void deleteAnyPos(Node* &head, int pos){
    Node* prev;
    Node* temp = head;

    // Case if linked list is empty
    if (temp == NULL)
        cout<<head<<endl;

    // Case 1: Head is to be deleted
    if (pos == 1) {
        head = temp->next;
        free(temp);
        cout<<head;
    }

    // Case 2: Node to be deleted is in middle. Traverse till given position
    for (int i = 1; i != pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    // If given position is not present
    else {
        cout << "Data not present\n";
    }
}
void deleteOccuranceGivenVal(Node* head, int val){
    if (!head) return;

    if (head->data == val) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}
int main() {
  
    // 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    // Delete first......
    cout<<"\nBefore deleting first: ";
    traverseList(head);
    deleteFirst(head);
    cout<<"After deleting first: ";
    traverseList(head);

    // Delete last............
    cout<<"\nBefore deleting last: ";
    traverseList(head);
    deleteLast(head);
    cout<<"After deleting last: ";
    traverseList(head);

    // Delete any pos....
    cout<<"\nBefore deleting any position: ";
    traverseList(head);
    deleteAnyPos(head, 5);
    cout<<"After deleting any position: ";
    traverseList(head);

    // Delete occurance given position....
    cout<<"\nBefore deleting: ";
    traverseList(head);
    deleteOccuranceGivenVal(head, 40);
    cout<<"\nAfter deleting occurance given value: ";
    traverseList(head);
    


    return 0;
}