#include<iostream>
using namespace std;

class Node{
    public:
    
        int data;
        Node * next;

    
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

Node* takeInput(){
    Node * head = NULL;
    Node * tail = NULL;
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    while (data != -1){
        Node * newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next  = newNode;
            tail = tail -> next;
        }
        cout << "enter the data" << endl;
        cin >> data;
    }
    return head;
}

void printLL(Node * head){
    Node * temp = head;
    while(temp  != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
Node* insertNode(Node * head, int data , int pos){
    int size = 0;
    Node * temp1 = head;
    
    
    Node * newNode = new Node(data);
    int count = 0;
    Node * temp = head;
    if(pos==0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    while(count < pos-1 && temp!= NULL){
        temp = temp -> next;
        count++;
    }
    if(temp!=NULL){
        Node * a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;


    }
    return head;
    
}
int find(Node * head, int element){
    int count = 0;
    Node * temp = head;
    while(temp -> data != element && temp != NULL){
        count ++;
        temp = temp -> next;
    }
    if(temp -> data == element){
        return count;
    }
    return -1;
}
Node * deleteNode(Node * head, int i){
    int count = 0;
    Node * temp = head;
    if(i==0){
        Node * rough = temp;
        head = temp -> next;
        delete rough;
        return head;
    }
    while(count < i-1 && temp != NULL){
        count ++;
        temp = temp -> next;
    }
    if(temp!=NULL){
        Node * a = temp -> next;
        Node * b = a -> next;
        temp -> next = b;
        delete a;
    }
    return head;
}

int main(){
    Node * head = takeInput();
    int element;
    cin >> element;
    int val = find(head,element);
    cout << val << endl;
}