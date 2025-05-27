#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // Display elements of circular linked list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }

    // Count total nodes
    int count() {
        if (!head) return 0;
        int cnt = 0;
        Node* temp = head;
        do {
            cnt++;
            temp = temp->next;
        } while (temp != head);
        return cnt;
    }

    // Search for element
    bool search(int val) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Insert node at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Insert node at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete first occurrence of a value
    void deleteValue(int val) {
        if (!head) return;

        // If head needs to be deleted
        if (head->data == val) {
            // If only one node
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            // More than one node, find last node
            Node* last = head;
            while (last->next != head)
                last = last->next;

            Node* toDelete = head;
            head = head->next;
            last->next = head;
            delete toDelete;
            return;
        }

        // Delete non-head node
        Node* curr = head;
        while (curr->next != head && curr->next->data != val)
            curr = curr->next;

        if (curr->next->data == val) {
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
        }
    }

    // Reverse circular linked list
    void reverse() {
        if (!head || head->next == head) return;

        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode;
        Node* first = head;

        do {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        } while (curr != head);

        // Fix the last node
        first->next = prev;
        head = prev;
    }

    // Remove duplicates from sorted circular list
    void removeDuplicates() {
        if (!head || head->next == head) return;

        Node* curr = head;
        do {
            if (curr->data == curr->next->data) {
                Node* dup = curr->next;
                curr->next = dup->next;
                delete dup;
            } else {
                curr = curr->next;
            }
        } while (curr->next != head);
    }

    // Find N-th node from end using one traversal
    Node* nthFromEnd(int n) {
        if (!head) return nullptr;

        Node* fast = head;
        Node* slow = head;
        int length = 1;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
            if (fast == head) {  // if n > length, return nullptr
                if (i == n - 1)
                    return nullptr;
            }
            length++;
        }

        while (fast != head) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    // Check if circular list is palindrome
    bool isPalindrome() {
        if (!head || head->next == head) return true;

        // Convert circular list to linear temporarily
        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = nullptr;  // break circularity

        // Check palindrome using normal singly linked list approach
        bool result = isLinearPalindrome(head);

        // Restore circularity
        tail->next = head;

        return result;
    }

    // Helper for palindrome check on linear linked list
    bool isLinearPalindrome(Node* start) {
        Node* slow = start;
        Node* fast = start;

        // Find mid
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node* secondHalf = reverseList(slow);

        // Compare first and second halves
        Node* firstHalf = start;
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

        // Restore the list
        reverseList(secondHalf);

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
    CircularLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Circular List elements: ";
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
