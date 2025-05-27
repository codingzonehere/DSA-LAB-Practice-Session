#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteValue(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                if (temp == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    void removeDuplicates() {
        if (!head) return;
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                Node* dup = curr->next;
                curr->next = dup->next;
                if (dup->next) dup->next->prev = curr;
                else tail = curr;
                delete dup;
            } else {
                curr = curr->next;
            }
        }
    }

    Node* nthFromEnd(int n) {
        Node* fast = head;
        Node* slow = head;
        for (int i = 0; i < n; i++) {
            if (!fast) return nullptr;
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = tail;
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList doublyObj;

    doublyObj.insertAtEnd(1);
    doublyObj.insertAtEnd(2);
    doublyObj.insertAtEnd(2);
    doublyObj.insertAtEnd(3);
    doublyObj.insertAtEnd(4);

    cout << "List elements: ";
    doublyObj.display();

    cout << "Total nodes: " << doublyObj.count() << "\n";

    cout << "Searching for 3: " << (doublyObj.search(3) ? "Found" : "Not found") << "\n";
    cout << "Searching for 5: " << (doublyObj.search(5) ? "Found" : "Not found") << "\n";

    doublyObj.insertAtBeginning(0);
    cout << "After inserting 0 at beginning: ";
    doublyObj.display();

    doublyObj.deleteValue(2);
    cout << "After deleting first occurrence of 2: ";
    doublyObj.display();

    doublyObj.removeDuplicates();
    cout << "After removing duplicates: ";
    doublyObj.display();

    cout << "Reversing list...\n";
    doublyObj.reverse();
    doublyObj.display();

    int n = 3;
    Node* nthNode = doublyObj.nthFromEnd(n);
    if (nthNode)
        cout << n << "-th node from end: " << nthNode->data << "\n";
    else
        cout << "List has fewer than " << n << " nodes.\n";

    cout << "Is list palindrome? " << (doublyObj.isPalindrome() ? "Yes" : "No") << "\n";

    return 0;
}
