//Source file for making a Todo list 
#include<iostream>

using namespace std;
class Node{
public:
    string content;
    Node *next;
};
int main(){
    Node *head = new Node();
    return 0 ;
}

void push(Node*head_ref){
    while(head_ref->next != NULL){
        head_ref = head_ref->next;
    }
    Node *new_node = new Node();
    head_ref->next = new_node;
    new_node->next = NULL;
    cout<<"Enter the task to be added \n";
    cin>>new_node->content;
}
