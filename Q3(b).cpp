#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int findSize(Node *head) {
    if (head == NULL)
        return 0;

    int count = 0;
    Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    Node *n1 = new Node{5, NULL};
    Node *n2 = new Node{15, NULL};
    Node *n3 = new Node{25, NULL};

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    cout << "Size of Circular Linked List = " << findSize(n1);
    return 0;
}
