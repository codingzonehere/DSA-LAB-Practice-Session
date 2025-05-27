#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    // Display elements
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Count total nodes
    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Search for an element
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Insert node at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert node at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete first occurrence of a value
    void deleteValue(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    // Remove duplicates from sorted list
    void removeDuplicates() {
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                Node* dup = curr->next;
                curr->next = dup->next;
                delete dup;
            } else {
                curr = curr->next;
            }
        }
    }

    // Find N-th node from end using one traversal
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

    // Check if list is palindrome
    bool isPalindrome() {
        if (!head || !head->next) return true;

        // Find middle (slow and fast pointer)
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node* secondHalf = reverseList(slow->next);

        // Compare two halves
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

        // Restore second half
        slow->next = reverseList(secondHalf);

        return palindrome;
    }

    // Helper function to reverse a list and return new head
    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* curr = node;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "List elements: ";
    list.display();

    cout << "Total nodes: " << list.count() << "\n";

    cout << "Search for 3: " << (list.search(3) ? "Found" : "Not found") << "\n";
    cout << "Search for 5: " << (list.search(5) ? "Found" : "Not found") << "\n";

    list.insertAtBeginning(0);
    cout << "After inserting 0 at beginning: ";
    list.display();

    list.deleteValue(2);
    cout << "After deleting first occurrence of 2: ";
    list.display();

    list.removeDuplicates();
    cout << "After removing duplicates: ";
    list.display();

    cout << "Reversing list...\n";
    list.reverse();
    list.display();

    int n = 3;
    Node* nthNode = list.nthFromEnd(n);
    if (nthNode)
        cout << n << "-th node from end: " << nthNode->data << "\n";
    else
        cout << "List has fewer than " << n << " nodes.\n";

    cout << "Is list palindrome? " << (list.isPalindrome() ? "Yes" : "No") << "\n";

    return 0;
}
