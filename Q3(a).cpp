#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

int findSize(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node *n1 = new Node{10, NULL, NULL};
    Node *n2 = new Node{20, NULL, NULL};
    Node *n3 = new Node{30, NULL, NULL};

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    cout << "Size of Doubly Linked List = " << findSize(n1);
    return 0;
}
