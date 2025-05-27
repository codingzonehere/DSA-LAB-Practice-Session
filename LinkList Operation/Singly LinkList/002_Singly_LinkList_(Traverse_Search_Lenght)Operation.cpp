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
    Traverse all element:
*/
void traverseList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " "; // Printing data of current node
        head = head->next; // Moving to the next node
    }
    cout << endl;
}
/*
    Searching item........
*/
void searchKey(Node* head, int key) {

    Node* curr = head;
    string yes = "No";
    while (curr != NULL) {
        if (curr->data == key)
            // cout<<"Found: "<<curr->data;
            yes = "Yes";
        curr = curr->next;
    }
    cout<<yes<<endl;
}
/*
    Count Nodes..............
*/
void countNodes(Node* head){
    int counter = 0;
    while (head != nullptr)
    {
        counter++;
        head = head->next;
    }
    cout<<"Total nodes: "<<counter<<endl;
}

int main() {
  
    // 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverseList(head);
    searchKey(head, 10);
    countNodes(head);




    return 0;
}