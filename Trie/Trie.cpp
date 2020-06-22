#include "TrieNode.cpp"
#include<string>
using namespace std;

class Trie{
    TrieNode* root;
    void help_insert(string word,TrieNode* root){
        if(word.size() == 0){
            root->isEnd=true;

            return;
        }
        int index=word[0]-'a';
        if(root->children[index] == NULL){
            root->children[index]=new TrieNode(word[0]);
        }
        help_insert(word.substr(1),root->children[index]);

    }
    bool help_search(string word,TrieNode* root){
        if(word.size() == 0){

            return root->isEnd;
        }
        int index=word[0]-'a';
        if(root->children[index] == NULL){

            return false;
        }

        return help_search(word.substr(1),root->children[index]);
    }

    void help_remove(string word ,TrieNode* root){
        if(word.size() == 0){
            root->isEnd=false;
            return;
        }

        int index=word[0]-'a';

        if(root->children[index]==NULL){
           return;
        }

        help_remove(word.substr(1),root->children[index]);

        if(root->children[index]->isEnd==false){
            for(int i=0;i<26;i++){
                if(root->children[index]->children[i]!=NULL){
                    return;
                }
            }
        }

        delete root->children[index];
        root->children[index]=NULL;

    }
public:
    Trie(){
        root=new TrieNode();
    }
    ~Trie(){
        delete root;
    }

    void insert(string word){
        if(word.size() == 0){
            root->isEnd=true;

            return;
        }
        help_insert(word,root);
    }

    bool search(string word){
        if(word.size() == 0){

            return root->isEnd;
        }
        return help_search(word,root);
    }

    void remove(string word){
        if(word.size() == 0){
            root->isEnd=false;
            return;
        }
        help_remove(word,root);
    }
};
