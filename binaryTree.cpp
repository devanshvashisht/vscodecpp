#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template<typename T>

class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode * left;
        BinaryTreeNode * right;


        BinaryTreeNode(T data){
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~ BinaryTreeNode(){
            delete left;
            delete right;
        }
};

void printTree(BinaryTreeNode<int> * root){
    if(root == NULL){
        return ;
    }

    cout << root -> data << ":" ;
    if(root -> left != NULL){
        cout << "L" << root -> left -> data << " ";
    }
    if(root -> right != NULL){
        cout << "R" << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}
BinaryTreeNode<int> * takeInput(){
    int rootData;
    cout << "Enter the data" << endl;
    cin >> rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root -> left = leftChild;
    root -> right = rightChild;
    return root;
    
}
BinaryTreeNode<int>* takeInputlevel(){
    int rootdata;
    cout << "Enter the root data" << endl;
    cin >> rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << front -> data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front -> left = child;
            pendingNodes.push(child);
        }

        cout << "Enter the right child of " << front -> data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front -> right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int numNodes(BinaryTreeNode<int>* root){
    if(root ==NULL){
        return 0;
    }

    return 1 + numNodes(root -> left) + numNodes(root -> right);
}
// bool isNodepresent(BinaryTreeNode<int>* root,int x){
//     if(root -> data == x){
//         return true;
//     }
//     bool smallAns = isNodepresent;
// }

BinaryTreeNode<int>* buildHelper(int * inOrder, int * preOrder, int inS, int inE, int preS, int preE){
    if(inS>inE){
        return NULL;
    }

    int rooData = preOrder[preS];

    int rootIndex = -1;
    for(int i = inS;i<=inE;i++){
        if(inOrder[i]==rooData){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE= rootIndex-1;
    int lPreS = preS+1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE+1;
    int rPreE = preE;
    int rInS = rootIndex+1;
    int rInE = inE;

}


BinaryTreeNode<int>* buildTree(int * inOrder , int * preOrder, int size){
    return buildTreeHelper(inOrder, preOrder, 0 ,size -1 ,0 ,size -1);

}
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1+ max(height(root -> left), height(root -> right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root -> left) + height(root -> right);
    int option2 = diameter(root -> left);
    int option3 = diameter(root -> right);

    return max(option1, max(option2, option3));
}



/*pair <int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root -> left);
    pair<int,int> rightAns = heightDiameter(root -> right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1+ max(lh,rh);
    int diameter = max(lh+rh, max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;




}*/
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }

    return max(root -> data, max(maximum(root -> left), maximum(root ->right)));
}


int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    return min(root -> data, min(minimum(root -> left), minimum(root ->right)));
}

bool isBst(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }

    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);

    bool output = (root -> data >leftMax) && (root -> data < rightMin) && isBst(root -> left) && isBst(root -> right);
    return output;
}


class isBSTReturn{
    public:
        bool isBst;
        int minimum;
        int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBSTReturn output;
        output.isBst = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;

    }

    isBSTReturn leftOutput = isBST2(root -> left);
    isBSTReturn rightOutput = isBST2(root -> right);
    int minimum = min(root -> data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
    bool isFinal = (root -> data > leftOutput.maximum) && (root -> data < rightOutput.minimum) && leftOutput.isBst && rightOutput.isBst;

    isBSTReturn output;
    output.isBst = isFinal;
    output.minimum = minimum;
    output.maximum = maximum;
    return output;

}
bool isBst3(BinaryTreeNode<int>* root , int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root -> data < min || root -> data > max){
        return false;
    }

    bool isLeftOK = isBst3(root -> left , min, root -> data-1);
    bool isRightOK = isBst3(root -> right, root -> data, max);
    return isLeftOK && isRightOK;
}
int main(){
    BinaryTreeNode<int>* root = takeInputlevel();
    printTree(root);
    

}