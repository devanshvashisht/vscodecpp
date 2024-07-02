#include<iostream>
using namespace std;


class Stack{

    public:
        int *arr;
        int top;
        int size;

    Stack(int size){
        this -> size= size;
        arr= new int[size];
        top = -1;
    }

    void push(int key){
        if (size-top>1){
            top ++;
            arr[top] = key;

        }else {
            cout << "Stack overflow";
        }
    }

    void pop(){
        if (top >=0){
            top--;
        }else {
            cout << "Stack underflow";
        }
    }

    int peek(){
        if (top>=0){
            return arr[top];
        }else {
            cout << "Stack is empty";
        }
        
    }

    bool isEmpty(){
        if (top ==-1){
            return true;

        }else{
            return false;
        }
    }
   
};


int main(){
    Stack st(5);


    st.push(10);
    st.push(20);
    st.pop();
    st.push(43);
    cout << st.peek();

}