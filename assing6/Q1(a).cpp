// Program: Menu driven program for Circular Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// function prototypes
void insertAtBeginning(Node* &head, int val);
void insertAtEnd(Node* &head, int val);
void insertAfter(Node* &head, int key, int val);
void insertBefore(Node* &head, int key, int val);
void deleteByValue(Node* &head, int key);
Node* searchNode(Node* head, int key);
void display(Node* head);

int main() {
    Node *head = NULL;
    int choice, val, key;

    do {
        cout << "\n=== Circular Linked List Menu ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node by value\n";
        cout << "6. Search for a node\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(head, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(head, val);
            break;
        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            insertAfter(head, key, val);
            break;
        case 4:
            cout << "Enter key (before which to insert): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            insertBefore(head, key, val);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteByValue(head, key);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            if (searchNode(head, key) != NULL)
                cout << "Node with value " << key << " found.\n";
            else
                cout << "Node with value " << key << " not found.\n";
            break;
        case 7:
            display(head);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

void insertAtBeginning(Node* &head, int val) {
    Node *temp = new Node;
    temp->data = val;

    if (head == NULL) {
        head = temp;
        head->next = head;
    } else {
        Node *last = head;
        while (last->next != head)
            last = last->next;

        temp->next = head;
        last->next = temp;
        head = temp;
    }
    cout << "Inserted " << val << " at beginning.\n";
}

void insertAtEnd(Node* &head, int val) {
    Node *temp = new Node;
    temp->data = val;

    if (head == NULL) {
        head = temp;
        head->next = head;
    } else {
        Node *last = head;
        while (last->next != head)
            last = last->next;

        last->next = temp;
        temp->next = head;
    }
    cout << "Inserted " << val << " at end.\n";
}

Node* searchNode(Node* head, int key) {
    if (head == NULL)
        return NULL;

    Node *p = head;
    do {
        if (p->data == key)
            return p;
        p = p->next;
    } while (p != head);

    return NULL;
}

void insertAfter(Node* &head, int key, int val) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *pos = searchNode(head, key);
    if (pos == NULL) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    Node *temp = new Node;
    temp->data = val;
    temp->next = pos->next;
    pos->next = temp;
    cout << "Inserted " << val << " after " << key << ".\n";
}

void insertBefore(Node* &head, int key, int val) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // If key is at head, insertion before head means new head
    if (head->data == key) {
        insertAtBeginning(head, val);
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    Node *temp = new Node;
    temp->data = val;
    temp->next = curr;
    prev->next = temp;
    cout << "Inserted " << val << " before " << key << ".\n";
}

void deleteByValue(Node* &head, int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Only one node
    if (head->next == head && head->data == key) {
        delete head;
        head = NULL;
        cout << "Deleted node " << key << ".\n";
        return;
    }

    // If head node is to be deleted and there are multiple nodes
    if (head->data == key) {
        Node *last = head;
        while (last->next != head)
            last = last->next;

        Node *temp = head;
        head = head->next;
        last->next = head;
        delete temp;
        cout << "Deleted node " << key << ".\n";
        return;
    }

    // Delete from middle or last
    Node *prev = head;
    Node *curr = head->next;
    while (curr != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Deleted node " << key << ".\n";
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Circular Linked List: ";
    Node *p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << "\n";
}
