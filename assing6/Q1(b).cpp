// Program: Menu driven program for Doubly Linked List
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

// function prototypes
void insertAtBeginning(DNode* &head, int val);
void insertAtEnd(DNode* &head, int val);
void insertAfter(DNode* &head, int key, int val);
void insertBefore(DNode* &head, int key, int val);
void deleteByValue(DNode* &head, int key);
DNode* searchNode(DNode* head, int key);
void display(DNode* head);

int main() {
    DNode *head = NULL;
    int choice, val, key;

    do {
        cout << "\n=== Doubly Linked List Menu ===\n";
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

void insertAtBeginning(DNode* &head, int val) {
    DNode *temp = new DNode;
    temp->data = val;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    cout << "Inserted " << val << " at beginning.\n";
}

void insertAtEnd(DNode* &head, int val) {
    DNode *temp = new DNode;
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
    } else {
        DNode *p = head;
        while (p->next != NULL)
            p = p->next;

        p->next = temp;
        temp->prev = p;
    }
    cout << "Inserted " << val << " at end.\n";
}

DNode* searchNode(DNode* head, int key) {
    DNode *p = head;
    while (p != NULL) {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

void insertAfter(DNode* &head, int key, int val) {
    DNode *pos = searchNode(head, key);
    if (pos == NULL) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    DNode *temp = new DNode;
    temp->data = val;
    temp->next = pos->next;
    temp->prev = pos;

    if (pos->next != NULL)
        pos->next->prev = temp;

    pos->next = temp;
    cout << "Inserted " << val << " after " << key << ".\n";
}

void insertBefore(DNode* &head, int key, int val) {
    DNode *pos = searchNode(head, key);
    if (pos == NULL) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    if (pos == head) {
        insertAtBeginning(head, val);
        return;
    }

    DNode *temp = new DNode;
    temp->data = val;
    temp->prev = pos->prev;
    temp->next = pos;

    pos->prev->next = temp;
    pos->prev = temp;
    cout << "Inserted " << val << " before " << key << ".\n";
}

void deleteByValue(DNode* &head, int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    DNode *curr = head;
    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    else
        head = curr->next; // deleting head

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    delete curr;
    cout << "Deleted node " << key << ".\n";
}

void display(DNode* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Doubly Linked List: ";
    DNode *p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
