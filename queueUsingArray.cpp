#include<iostream>
using namespace std;

class Queue{
    
    int * data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

        Queue(int s){
            data = new int[s];
            nextIndex = 0;
            firstIndex = -1;
            size = 0;
            capacity = s;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }

        void enqueue(int element){
            if(size==capacity){
                int * newData = new int[2* capacity];
                int j=0;
                for(int i= firstIndex ; i< capacity;i++){
                    newData[j] = data[i];
                    j++;
                }
                for(int i = 0; i< firstIndex;i++){
                    newData[j]=data[i];
                    j++;
                }
                delete [] data;
                data = newData;
                firstIndex = 0;
                nextIndex = capacity;
                capacity *= 2;
                  
            }
            data[nextIndex] = element;
            nextIndex = (nextIndex+1) % capacity;
            if(firstIndex==-1){
                firstIndex++;
            }
            size++;
        }

        int front(){
            if(firstIndex==-1){
                cout << "Queue is empty" << endl;
                return 0;
            }
            return data[firstIndex];
        }

        int dequeue(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return 0;
            }
            int ans = data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            if(size==0){
                firstIndex = -1;
                nextIndex = 0;

            }
            return ans; 
        }
};

int main(){
    Queue q(7);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    cout << q.getSize()<<endl;
    cout << q.front()<<endl;
    q.enqueue(40);
    q.dequeue();
    q.enqueue(60);
    cout << q.getSize ()<<endl;
    cout << q.front()<<endl;
    
}