#include<cstring>
#include<iostream>
using namespace std;

template <typename V>
class mapNode{
    public:
        string key;
        V value;
        mapNode* next;

        mapNode(string key, V value){
            this -> key = key;
            this -> value = value;
            this -> next = NULL;
        }
};

class ourMap{
    mapNode<V>** buckets;
    int size;
    int numbuckets;


    public:
        ourMap(){
            count = 0;
            numbuckets = 5;
            buckets = new mapNode<V>* [numbuckets];
            for(int i=0;i<numbuckets;i++){
                buckets[i] = NULL;
            }
        }

        ~ourMap(){
            for(int i=0;i<numbuckets;i++){
                delete buckets[i];
            }
            delete [] buckets;
        }

        int size(){
            return count;
        }

        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head -> key == key){
                    return head -> value;
                }
                head = head -> next;
            }
            return 0;

        }

    private:
        int getBucketIndex(string key){
            int hashCode;
            int currentCoeff = 1;
            for(int i=key.length()-1;i>=0;i--){
                hashCode+= key[i] * currentCoeff;
                hashCode%= numbuckets;
                currentCoeff*=37;
                currentCoeff%=numbuckets;


            }
            return hashCode % numbuckets;

        }

            
    public:
        void insert(string key, V value){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = buckets[bucketIndex];
            while(head!=NULL){
                if(head -> key == key){
                    head -> value = value;
                    return;

                }
                head = head -> next;

            }
            head = buckets[bucketIndex];
            mapNode<V>* node = new mapNode<V>(key, value);
            node -> next = head;
            buckets[bucketIndex] = node;
            count++;
        }

        V remove(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = buckets[bucketIndex];
            mapNode<V>* prev = NULL;
            while(head!=NULL){
                if(head -> key == key){
                    if(prev==NULL){
                        buckets[bucketIndex] = head -> next;
                    }else{
                        prev -> next = head -> next;
                    }
                    V value = head -> value;
                    head -> next = NULL;
                    delete head;
                    count --;
                    return value;

                    
                }
                
                prev = head;
                head = head -> next;
            }

            return 0;
        }

};
