#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        // Set value automatic use constructor....
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

int main(){
    Node a(10), b(15), c(20);
    // Node a,b;
    // a.val = 10;
    // b.val = 20;

    // // Link Node....
    // a.Next = &b;
    // b.Next = nullptr;
    a.next = &b;
    
    cout<<a.data<<endl;
    cout<<a.next->data<<endl;
    return 0;
}