#include <iostream>
using namespace std;
class Node{
    public:
    char c;
    Node* next;
    Node* prev;
    Node(char a){
        c=a;
        next=prev=nullptr;
    }
};
Node* array_to_linked_list(char* c,int n){
    Node* head=new Node(c[0]);
    Node* curr=head;
    for(int i=1;i<n;i++){
        Node* t=new Node(c[i]);
        curr->next=t;
        t->prev=curr;
        curr=curr->next;
    }
    return head;
}
bool Palindrome(Node* head){
    if(head==nullptr || head->next==nullptr) return true;
    Node* left=head;
    Node* right=head;
    int count=0;
    while(right->next!=nullptr){
        right=right->next;
        count++;
    }
    count++;
    for(int i=0;i<count/2;i++){
        if(right->c!=left->c){
            return false;
        }
        right=right->prev;
        left=left->next;
    }
    return true;
}
int main() {
    char c[]="MALAYALAM";
    Node* head=array_to_linked_list(c,9);
    cout<<Palindrome(head)<<endl;
    return 0;

}