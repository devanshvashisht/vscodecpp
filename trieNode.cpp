#include<iostream>
#include<cstring>
using namespace std;

class TrieNode{
    public:

        char data;
        TrieNode ** children;
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            children = new TrieNode*[26];
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;

        }

};

class Trie{
    TrieNode* root;

    public:
        Trie(){
            root = new TrieNode('\0');
        }

        void insertWord(TrieNode* root,string word){
            if(word.size()==0){
                root -> isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root ->children[index]!=NULL){
                child = root -> children[index];
            }else{
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            insertWord(child,word.substr(1));

        }

        void insertWord(string word){
            insertWord(root, word);
        }

        bool search(TrieNode* root , string word){
            if(word.size()==0){
                return root -> isTerminal;
            }
            
            int index = word[0]-'a';
            if(root -> children[index]!=NULL){
                return search(root -> children[index], word.substr(1));
            }else{
                return false;
            }


        }
        bool searchWord(string word){
            if(word.size()==0){
                return false;
            }
            return search(root, word);

        }

        bool remove(TrieNode* root, string word){
            if(word.size()==0){
                root -> isTerminal = false;
                return;
            }
            TrieNode* child;
            int index = word[0]- 'a';
            if(root -> children[index] != NULL){
                child = root -> children[index];
            }else{
                return;
            }
            remove(child,word.substr(0));

        }

        bool remove(string word){
            remove(root, word);
        }
};

int main(){
    Trie t;
    
}