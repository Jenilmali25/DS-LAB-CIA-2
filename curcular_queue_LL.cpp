#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Circular Doubly Linked List class
class CDLL {
private:
    Node* head;

public:
    CDLL() { head = nullptr; }

    // Function to insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = last;
            last->next = newNode;
        }
    }

    // Function to delete a specific value
    void deleteValue(int value) {
        if (!head) return;

        Node* temp = head;

        // Find the node to delete
        while (temp && temp->data != value) {
            temp = temp->next;
            if (temp == head) return; // Value not found
        }

        if (temp->next == temp) {
            head = nullptr; // If it's the only node
        } else {
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            if (temp == head) head = nextNode;
        }
        delete temp;
    }

    // Function to search for the address of an element and its predecessor node
    void searchElement(int value) {
        if (!head) return;

        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
            if (temp == head) {
                cout << "Element not found.\n";
                return;
            }
        }
        cout << "Element " << value << " found at address: " << temp << "\n";
        cout << "Predecessor: " << temp->prev << "\n";
    }

    // Function to check if CDLL is empty
    void isEmpty() {
        if (!head)
            cout << "CDLL is empty.\n";
        else
            cout << "CDLL is not empty.\n";
    }

    // Function to count the number of nodes in CDLL
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
            if (temp == head) break;
        }
        cout << "Number of nodes: " << count << "\n";
    }

    // Function to display elements from head to rear
    void displayHeadToRear() {
        if (!head) {
            cout << "CDLL is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "CDLL from Head to Rear: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "\n";
    }

    // Function to display elements from rear to head
    void displayRearToHead() {
        if (!head) {
            cout << "CDLL is empty.\n";
            return;
        }

        Node* temp = head->prev;
        cout << "CDLL from Rear to Head: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
            if (temp == head->prev) break;
        }
        cout << "\n";
    }

    // Function to delete all elements
    void deleteAll() {
        if (!head) return;
        
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
            if (current == head) break;
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
            if (temp == head) break;
        }
        cout << "Element not found from Head.\n";
    }

    // Function to search for the position of the target element from the rear
    void searchPositionFromRear(int value) {
        if (!head) return;

        int pos = 1;
        Node* temp = head->prev;
        while (temp) {
            if (temp->data == value) {
                cout << "Element " << value << " found at position from Rear: " << pos << "\n";
                return;
            }
            temp = temp->prev;
            pos++;
            if (temp == head->prev) break;
        }
        cout << "Element not found from Rear.\n";
    }
};

int main() {
    CDLL list;

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

    // Check if CDLL is empty
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
