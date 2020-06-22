#include "BSTNode.cpp"
using namespace std;
typedef int T;

class bst{
    BTNode<T>* root;

    bool help_search(BTNode<T>* root,T data){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        return help_search(root->left,data) || help_search(root->right,data);
    }

    BTNode<T>* help_insert(BTNode<T>* root,T data){
        if(root==NULL){
            root=new BTNode<T>(data);
            return root;
        }
        if(root->data>data){
            root->left=help_insert(root->left,data);
        }
        else{
            root->right=help_insert(root->right,data);
        }
        return root;
    }

    BTNode<T>* help_remove(BTNode<T>* root,T data){
        if(root==NULL){
            return root;
        }
        if(root->data==data){
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL){
                BTNode<T>* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                BTNode<T>* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else{
                if(root->right->left==NULL){
                    root->data=root->right->data;
                    BTNode<T>* temp=root->right->right;
                    root->right->right=NULL;
                    delete root->right;
                    root->right=temp;
                    return root;
                }
                else{
                    BTNode<T>* node=root->right;
                    BTNode<T>* nextnode=root->right->left;
                    while(nextnode->left!=NULL){
                        node=nextnode;
                        nextnode=node->left;
                    }
                    root->data=nextnode->data;
                    node->left=nextnode->right;
                    nextnode->right=NULL;
                    delete nextnode;
                    return root;
                }
            }
        }
        else{
            if(root->data>data){
                root->left=help_remove(root->left,data);
            }
            else{
                root->right=help_remove(root->right,data);
            }
            return root;
        }

    }

    void help_print(BTNode<T>* root){
        if(root==NULL){
            return;
        }
        cout<<"Node: "<<root->data;
        if(root->left!=NULL){
            cout<<" , Left Child: "<<root->left->data;
        }
        if(root->right!=NULL){
            cout<<" , Right Child: "<<root->right->data;
        }
        cout<<'\n';
        help_print(root->left);
        help_print(root->right);
    }

public:
    bst(){
        root=NULL;
    }
    ~bst(){
        delete root;
    }

    bool search(T data){
        return help_search(root,data);
    }

    void insert(T data){
        root=help_insert(root,data);
    }

    void remove(T data){
        root=help_remove(root,data);
    }

    void print(){
        help_print(root);
    }
};
