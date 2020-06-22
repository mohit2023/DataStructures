#include<iostream>
class TrieNode{
public:
    char data;
    TrieNode **children;
    bool isEnd;

    TrieNode(char data='\0'){
        this-> data=data;
        isEnd=false;
        children= new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }

    ~TrieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
        delete[] children;
    }
};
