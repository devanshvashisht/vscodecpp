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

class Queue{
    Node * head;
    Node * tail;
    int size;

    public:
        Queue(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return head == NULL;
        }

        void enqueue(int data){
            Node * newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                size++;
            }else{
                tail -> next = newNode;
                tail = tail -> next;
                size++;
            }
        }

        int dequeue(){
            if(head==NULL){
                cout << "stack is empty" << endl;
                return 0;
            }else{
                Node * a = head;
                head = head -> next;
            
                size--;
                return a -> data;
            }
        }

        int front(){
            if(head==NULL){
                return 0;
            }else{
                return head -> data;
            }
        }
};