#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>

class TreeNode{
    public:

        T data;
        vector <TreeNode<T> *> children;
        // vector to store the address of all the child nodes
        TreeNode(T data){
            this -> data = data;

        }

        ~TreeNode(){
            for(int i=0;i<children.size();i++){
                delete children[i];
            }
        }

};

TreeNode<int>* takeInput(){
    cout << "Enter the data" << endl;
    int rootData;
    cin >> rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter the number of children of " <<rootData<< endl;
    cin >> n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=takeInput();
        root -> children.push_back(child);
    } 
    return root;

}

TreeNode<int> *takeInputLevel(){
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front -> data << endl;
        int numChild;
        cin >> numChild;
        for(int i=0;i< numChild;i++){
            int childData;
            cout << "Enter the " << i << "th child of " << front -> data << endl;
            cin >> childData;
            TreeNode <int>* child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);


        }
    }
    return root;
}

void printAtlevelk(TreeNode<int>* root, int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
        cout << root -> data <<endl;
        return ;
    }
    for(int i=0;i<root -> children.size();i++){
        printAtlevelk(root -> children[i],k-1);
    }
}
void printTreeLevel(TreeNode<int>* root){
    
    queue<TreeNode<int>*> child;
    child.push(root);
    while(child.size()!=0){

        TreeNode<int>* front = child.front();
        child.pop();
        cout << front -> data << ":" ;
        for(int i=0;i<front -> children.size();i++){
            cout << front -> children[i]-> data << ",";
            child.push(front -> children[i]);

        }
        cout << endl;
    }

    
}
void preOrder(TreeNode<int>* root){
    if(root ==NULL){
        return ;
    }
    cout << root -> data << " ";
    for(int i=0;i< root -> children.size();i++){
        preOrder(root ->children[i]);
    }
}

void deletetree(TreeNode<int>* root){
    for(int i=0;i< root -> children.size();i++){
        deletetree(root -> children[i]);
    }
    delete root ;
}
void printTree(TreeNode<int>* root){

    if(root == NULL){
        return ;
    }
    cout << root -> data << ":";
    for(int i=0;i<root -> children.size();i++){
        cout << root -> children[i] -> data << "," ;
    }
    cout << endl;
    for(int i=0;i<root -> children.size();i++){
        printTree(root -> children[i]);
    }
}
int countNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i=0;i<root ->children.size()-1;i++){
        ans += countNodes(root -> children[i]);
    }
    return ans;
}
    
void inOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    inOrder(root -> left);
    cout << root -> data <<" " << endl;
    inOrder(root -> right);
}
int main(){
    /*
    TreeNode<int> * root = new TreeNode<int>(1);
    TreeNode<int> * node1 = new TreeNode<int>(2);
    TreeNode<int> * node2 = new TreeNode<int>(3);
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    */
    TreeNode<int> * root = takeInputLevel();
    preOrder(root);
    delete root;
}