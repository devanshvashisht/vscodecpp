#include<iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;
    Node (int data){
        this -> data= data;
        this -> left = NULL;
        this -> right = NULL;

    }     

};

Node* insertKey(Node *root, int val){

    if (root == NULL){
        return new Node(val);
    }
    if (val < root ->data){
        root -> left = insertKey(root -> left, val);
    } else if (val > root-> data){
        root -> right = insertKey(root -> right, val);
    }
    return root;
}


Node* searchBST(Node* root,int key){
    if (root ==NULL){
        cout << "Tree is empty";
    } else if (root ->data == key){
        return root;
    }
}

int main(){
    Node* root = NULL;
    insertKey(root,5);
    insertKey(root,1);
    insertKey(root,3);
    return 0;
}