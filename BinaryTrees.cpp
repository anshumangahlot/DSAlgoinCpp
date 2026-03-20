#include <iostream>
using namespace std;

//binary tree
class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node(int val) {
        data=val;
        left=right=NULL;
    }
    friend class Tree;
};

class Tree{
    Node* root;
    void preorder(Node* currentnode);
    void inorder(Node* currentnode);
    void postorder(Node* currentnode);
    public:
    Tree() {
        root=NULL;
    }
    void create();
    void Preorder();
    void Inorder();
    void Postorder();
};

void Tree::create() {
    Node* temp;Node* newnode;
    int x;
    char ans;
    char choice = 'y';
    do {
        cout<<"enter the element to be attached";
        cin>>x;
        newnode=new Node(x);
        if (root==NULL) {
            root=newnode;
        }
        else {
            temp=root;
            while (true) {
                cout<<"left of right (l/r) of %d: "<<temp->data;
                cin>>ans;
                if (ans=='l') {
                    if (temp->left==NULL) {
                        temp->left=newnode;
                        break;
                    }
                    else {
                        temp=temp->left;
                    }
                }
                else {
                    if (temp->right==NULL) {
                        temp->right=newnode;
                        break;
                    }
                    else {
                        temp=temp->right;
                    }
                }
            }
            cout<<"any other nodes(y/n):";
            cin>>choice;
        }
    }while (choice=='y'||choice=='Y');
}

void Tree::Preorder() {
    preorder(root);
}
void Tree::preorder(Node* currentnode) {
    if (currentnode==NULL) return;
    cout<<currentnode->data<<" ";
    preorder(currentnode->left);
    preorder(currentnode->right);
}
void Tree::Inorder() {
    inorder(root);
}
void Tree::inorder(Node* currentnode) {
    if (currentnode==NULL) return;
    inorder(currentnode->left);
    cout<<currentnode->data<<" ";
    inorder(currentnode->right);
}
void Tree::Postorder() {
    postorder(root);
}
void Tree::postorder(Node* currentnode) {
    if (currentnode==NULL) return;
    postorder(currentnode->left);
    postorder(currentnode->right);
    cout<<currentnode->data<<" ";
}

int main() {
    Tree t;
    t.create();
    t.Preorder();
    cout<<" "<<endl;
    t.Inorder();
    cout<<" "<<endl;
    t.Postorder();
    cout<<" "<<endl;
}
