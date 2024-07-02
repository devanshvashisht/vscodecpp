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

class Stack{
    Node * head;
    int size;

    public:
        Stack(){
            head = NULL;
            size = 0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return (head == NULL);
        }

        void push(int element){
            Node * newNode = new Node(element);
            if(head==NULL){
                head = newNode;
                
            }else{
                newNode -> next = head;
                head = newNode;
                
            }
            size++;
        }

        int pop(){
            if(head==NULL){
                return 0;
            }
            Node * temp = head;
            head = head -> next;
            size--;
            return temp -> data;
            
        }
        int top(){
            return head -> data;
        }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    cout << s.getSize() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;
}