//Source file for making a Todo list 
//Header Files
#include<iostream>

using namespace std;

//Class Definitions
class Node{
public:
    string content;
    Node *next;
};

//Function Prototyping
void push(Node*);
void show(Node*);
void menu();

//Main Function
int main(){
    int choice ;
    Node *head = new Node();  //Creating head node and allocating space in heap
    while(true){
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:
                push(head);
                break;
            case 3:
                show(head);
                break;
            case 4 :
                exit(0);
            default:
                cout<<"Invalid Choice entered ";
                break;
        }
    }
    cin.get();
    return 0 ;
}

//Function for adding a Node 
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

//Function for showing the list
void show(Node *head_ref){
    while(head_ref != NULL){
        cout<<head_ref->content;

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