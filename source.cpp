//Source file for making a Todo list 
//Header Files
#include<iostream>

using namespace std;

//Class Definitions
class Node{
public:
    int index ;
    string content;
    string status ;
    Node *next;
    Node(){
        index = 0 ; 
        next =  NULL ;
        content = "NILL";
        status = "NOT DEFINED";
    }
};

//Function Prototyping
void push(Node*);
void show(Node*);
void menu();
void deletenode(Node *, int );

//Main Function
int main(){
    int choice ;
    Node *head = new Node();  //Creating head node and allocating space in heap
    head->content = "First Node";
    head->index = 1 ;
    head->next = NULL;
    push(head);
    push(head);
    push(head);
    show(head);
    int index ;
    cout<<"Enter the index number of which task to be deleted\n";
    cin>>index;
    if(index == 1){
        head =head->next;
        Node *headref = head ;
        while(headref != NULL){
            headref->index--;
            headref = headref->next;
        }
        free(headref);
    }
    else
        deletenode(head, index);
    show(head);
    cin.get();
    return 0 ;
}

//Function for adding a Node 
void push(Node*head_ref){
    static int count = 2 ; 
    while(head_ref->next != NULL){
        head_ref = head_ref->next;
    }
    Node *new_node = new Node();
    head_ref->next = new_node;
    new_node->next = NULL;
    cout<<"Enter the task to be added \n";
    cin>>new_node->content;
    new_node ->index = count ; 
    count++;
}

//Function for showing the list
void show(Node *head_ref){
    while(head_ref != NULL){
        cout<<"Node No . "<<head_ref->index<<" "<<head_ref->content<<"\n";

        head_ref = head_ref->next;
    }
}

//Function for showing Menu
void menu(){
    cout<<"1. Add a Task \n"
        <<"2. Delete a Task \n"
        <<"3. Show all Tasks\n"
        <<"4. To exit ";
}

//Function for deleting a task
void deletenode(Node *head, int index){
    Node *prev ;
    while(head->index != index){
        prev = head;
        head = head->next ;
    }
    prev->next = head->next;
    if(head->next != NULL)
        head = head->next ;
    while(head ->next != NULL){
        head->index--;
        head = head->next;
    }
}