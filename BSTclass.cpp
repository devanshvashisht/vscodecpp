#include<iostream>
using namespace std;
class BinaryTreeNode{
    public:
        int data;
        BinaryTreeNode * left;
        BinaryTreeNode * right;


        BinaryTreeNode(int data){
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~ BinaryTreeNode(){
            delete left;
            delete right;
        }
};
class BST{
    BinaryTreeNode * root;

    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    private:

        bool hasDatahelper(int data, BinaryTreeNode* node ){
            if(node==NULL){
                return false;
            }
            if(node -> data == data){
                return true;
            }else if(node -> data < data){
                return hasDatahelper(data, node -> left);
            }else{
                return hasDatahelper(data, node -> right);
            }
        }    
    private:
        BinaryTreeNode * insert(int data, BinaryTreeNode* node){
            if(node==NULL){
                BinaryTreeNode* newNode = new BinaryTreeNode(data);
                return newNode;
            }

            if(data < node -> data){
                node -> left= insert(data, root -> left);
            }else{
                node -> right = insert(data, root -> right);
            }
            return node;
        
        };r


        BinaryTreeNode* delete(int data, BinaryTreeNode* node){
            if(node==NULL){
                return NULL;
            }

            if(data > node -> data){
                node -> right = deleteData(data, node -> right);
            }else if(data < node -> data){
                node -> left = deleteData(data, node -> left);
            }else{
                if(node -> left == NULL && node -> right == NULL){
                    delete node;
                    return NULL;
                }else if(node -> left == NULL){
                    BinaryTreeNode* temp = root->right;d
                    delete Node;
                    return temp;
                }else if(node -> right == NULL){
                    BinaryTreeNode* temp = root -> left;
                    delete Node;
                    return temp;
                }else{
                    BinaryTreeNode* minNode = node ->right;
                    while(minNode-> left!= NULL){
                        minNode = minNode -> left;
                    }
                    int rightMin = minNode -> data;
                    node -> data = rightMin;
                    node -> right = deleteData(rightMin,node -> right );
                    return node;
                }
            }
        }
        
    
    public:
        void insert(int data){
            this -> root = insert(data, this -> root);

        }

        void deleteData(int data){

        }

        bool hasData(int data){
            return hasDatahelper(data, root);
        }

};