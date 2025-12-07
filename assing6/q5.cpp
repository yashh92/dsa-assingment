#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* add_last(Node* h, int x)
{
    Node* t = new Node;
    t->val = x;
    if(!h)
    {
        t->next = nullptr;
        return t;
    }
    Node* c = h;
    while(c->next)
    {
        c = c->next;
    }
    c->next = t;
    t->next = nullptr;
    return h;
}

bool is_circular(Node* h)
{
    if(!h)
    {
        return false;
    }
    Node* c = h->next;
    while(c && c != h)
    {
        c = c->next;
    }
    return c == h;
}

int main()
{
    int n, x;
    Node* h = nullptr;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        h = add_last(h, x);
    }

    cout << (is_circular(h) ? "True" : "False");
}