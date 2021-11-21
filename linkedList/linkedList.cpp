#include <iostream>
using namespace std;

#include "Node.cpp"


Node* takeInput(){
    int data = 0;
    cin >> data ;
    Node* head = NULL ;
    Node* tail = NULL ;
    while(data != -1){
        Node *newNode = new Node(data) ;
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
        }else{
            tail->next = newNode ;
            tail = newNode ;
        }
        cin >> data ;
    }

    return head ;
}

void print(Node *head){
    Node *temp = head ;
    while(temp != NULL){
        cout<< temp -> data <<" " ;
        temp = temp->next ;
    }
}



int main(){
    // Node n1(10) ; //statically
    // Node *head = n1 ;

    // Node n2(100) ;

    // n1.next = &n2 ;

    Node *head = takeInput();
    print(head) ;





}
