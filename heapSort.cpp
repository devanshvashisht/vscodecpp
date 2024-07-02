#include<iostream>
#include<vector>
using namespace std;

void heapSortinPlace(int pq[], int n){
    for(int i=0;i<n;i++){
        while(childIndex>0){
                int parentIndex = (childIndex-1)/2;
                if(pq[childIndex]<pq[parentIndex]){
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp; 
                }else{
                    break;
                }
                childIndex = parentIndex;

            }
    }

    int size = n;
    while(size>1){
    int temp = pq[0];
    pq[0] = pq[size-1];
    pq[size-1] = temp;
    size--;

    int parentIndex = 0;
    int leftChildIndex = 2*parentIndex+1 ;
    int rightChildIndex = 2*parentIndex+2 ;
            while(leftChildIndex<size){
                int minIndex = parentIndex;
                if(pq[minIndex]>pq[leftChildIndex]){
                    minIndex = leftChildIndex;
                }
                if(rightChildIndex<size  && pq[rightChildIndex] < pq[minIndex]){
                    minIndex = rightChildIndex;
                }

                if(minIndex == parentIndex){
                    break;
                }

                int temp = pq[minIndex];
                pq[minIndex] = pq[parentIndex];
                pq[parentIndex] = temp;

                parentIndex = minIndex;
                leftChildIndex = 2 * parentIndex +1;
                rightChildIndex = 2 * parentIndex +2;
                
            }


        }
}    

