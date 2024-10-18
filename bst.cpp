#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

void insert(node*& root, int x){
    node* t = new node(x);
    if(root==NULL){
        root=t;
        return;
    }
    if(t->data<root->data){
        insert(root->left, x);
    }
    else{
        insert(root->right, x);
    }
}

node* findmin(node* root){
    while(root!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}

node* deletee(node* root, int x){
    if(root==NULL)return root;
    if(x<root->data)
        root->left=deletee(root->left, x);
    else if(x>root->data){
        root->right=deletee(root->right, x);
    }
    else{
        if(root->left==NULL){
            node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right==NULL){
            node* t = root->left;
            delete root;
            return t;
        }
        node* t = findmin(root->right);
        root->data=t->data;
        root->right=deletee(root->right, t->data);
    }
    return root;

}

void search(node* root, int x){
    if(root==NULL){cout<<"Element Not found"<<endl;return;}
    if(root->data==x)
        cout<<"Element found!!"<<endl;
    else if(x<root->data)
        search(root->left, x);
    
    else
        search(root->right, x);
}

void larg(node* root){
    if(root==NULL){
        cout<<"no element"<<endl;
        return;
    }
    while(root->right!=NULL)
        root=root->right;
    cout<<"MAX: "<<root->data<<endl;
    
}

void pre(node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

int main(){
    node* root=NULL;
    for(int i=1; i<10; i++){
        insert(root, i);
    }
    root = deletee(root, 7);
    pre(root);

    // Search for different keys
    search(root, 11);  // Key found
    search(root, 9);  // Key not found

    larg(root);
    return 0;
}