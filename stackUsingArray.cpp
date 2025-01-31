#include<iostream>
using namespace std;
template <typename T>

class Stack{
    T * data;
    int nextIndex;
    int capacity;

    public:
        Stack(){
            data = new T[5]; 
            nextIndex = 0;
            capacity = 5;
        }


        int size(){
            return nextIndex;
        }

        bool isEmpty(){
            return nextIndex == 0;
        }

        void push(T element){
            if(nextIndex==capacity){
                T * newData = new T[2 * capacity];
                for(int i=0;i<capacity;i++){
                    newData[i] = data[i];

                }
                capacity *= 2;
                delete [] data;
                data = newData;

            }
            data[nextIndex] = element;
            nextIndex++;
        }

        T pop(){
            if(isEmpty()){
                cout << "Stack underflow" << endl;
                return 0; 
            }
            nextIndex--;
            return data[nextIndex];

        }

        T top(){
            if(isEmpty()){
                cout << "Stack empty" << endl;
                return 0;
            }
            return data[nextIndex-1];
        }
};


int main(){
    
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    cout << s.size() << endl;
    s.push(111);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
}