#include <iostream>
using namespace std;

// Node structure for DLL
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List class
class DLL {
private:
    Node* head;

public:
    DLL() { head = nullptr; }

    // Function to insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to delete a specific value
    void deleteValue(int value) {
        if (!head) return;

        Node* temp = head;

        // Traverse to find the node with the given value
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) return; // Value not found

        // If the node to delete is the head node
        if (temp == head) {
            head = temp->next;
            if (head) head->prev = nullptr;
        } else if (temp->next == nullptr) {  // If the node to delete is the last node
            temp->prev->next = nullptr;
        } else {  // If the node to delete is in the middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Function to search for the address of an element and its predecessor node
    void searchElement(int value) {
        if (!head) return;

        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Element not found.\n";
            return;
        }
        cout << "Element " << value << " found at address: " << temp << "\n";
        if (temp->prev) {
            cout << "Predecessor: " << temp->prev << "\n";
        } else {
            cout << "No predecessor (element is the head).\n";
        }
    }

    // Function to check if DLL is empty
    void isEmpty() {
        if (!head)
            cout << "DLL is empty.\n";
        else
            cout << "DLL is not empty.\n";
    }

    // Function to count the number of nodes in DLL
    void countNodes() {
        if (!head) {
            cout << "Number of nodes: 0\n";
            return;
        }

        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cout << "Number of nodes: " << count << "\n";
    }

    // Function to display elements from head to rear
    void displayHeadToRear() {
        if (!head) {
            cout << "DLL is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "DLL from Head to Rear: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Function to display elements from rear to head
    void displayRearToHead() {
        if (!head) {
            cout << "DLL is empty.\n";
            return;
        }

        Node* temp = head;
        // Traverse to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse back from last node to head
        cout << "DLL from Rear to Head: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    // Function to delete all elements
    void deleteAll() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    // Function to search for the position of the target element from the head
    void searchPositionFromHead(int value) {
        if (!head) return;

        int pos = 1;
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                cout << "Element " << value << " found at position from Head: " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found from Head.\n";
    }

    // Function to search for the position of the target element from the rear
    void searchPositionFromRear(int value) {
        if (!head) return;

        Node* temp = head;
        // Traverse to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Element " << value << " found at position from Rear: " << pos << "\n";
                return;
            }
            temp = temp->prev;
            pos++;
        }
        cout << "Element not found from Rear.\n";
    }
};

int main() {
    DLL list;

    // Inserting elements
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    // Display list
    list.displayHeadToRear();
    list.displayRearToHead();

    // Search for an element and its predecessor
    list.searchElement(20);

    // Check if DLL is empty
    list.isEmpty();

    // Count number of nodes
    list.countNodes();

    // Search position from head and rear
    list.searchPositionFromHead(30);
    list.searchPositionFromRear(10);

    // Deleting an element
    list.deleteValue(20);
    list.displayHeadToRear();

    // Deleting all elements
    list.deleteAll();
    list.isEmpty();
    return 0;
}
