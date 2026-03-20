#include <iostream>
using namespace std;
class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node(int val) {
        data=val;
        left=right=NULL;
    }
    friend class bst;
};

class bst {
    Node* root;
    void preorder(Node* currentnode);
    void inorder(Node* currentnode);
    void postorder(Node* currentnode);
    Node* search(Node* currentroot,int val);
public:
    bst() {
        root=NULL;
    }
    void create();
    void Preorder();
    void Inorder();
    void Postorder();
    void Search(int val);
    void delete_root();
    void delete_leaf();
    void delete_middle();
    Node* insert(Node* root, int key) ;
    Node* minValueNode(Node* node);
    void deleteNode(int key);
};
void bst::create() {
    Node* temp;Node* newnode;
    int x;
    char ans='y';
    do {
        cout<<"Enter node to be inserted: ";
        cin>>x;
        Node* newnode=new Node(x);

        if (root==NULL) {
            root=newnode;
        }
        else {
            temp=root;
            while (true) {
                if (x<temp->data) {
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
        }
        cout<<"Any other numbers: (y/n)";
        cin>>ans;
    }while (ans=='y'||ans=='Y');
}

Node* bst::insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}
Node* bst::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void bst::Preorder() {
    preorder(root);
}
void bst::preorder(Node* currentnode) {
    if (currentnode==NULL) return;
    cout<<currentnode->data<<" ";
    preorder(currentnode->left);
    preorder(currentnode->right);
}

void bst::Inorder() {
    inorder(root);
}

void bst::inorder(Node* currentnode) {
    if (currentnode==NULL) return;
    inorder(currentnode->left);
    cout<<currentnode->data<<" ";
    inorder(currentnode->right);
}
void bst::Postorder() {
    postorder(root);
}
void bst::postorder(Node* currentnode) {
    if (currentnode==NULL) return;
    postorder(currentnode->left);
    postorder(currentnode->right);
    cout<<currentnode->data<<" ";
}
void bst::Search(int val) {
    Node* x=search(root,val);
    cout<<search(root,val)->data;
    if (x!=NULL) {
        cout<<"Value found!";
    }
    else {
        cout<<"Value not found";
    }
}
Node* bst::search(Node* currentroot,int val) {
    if (currentroot!=NULL) {
        if (currentroot->data==val) return currentroot;
        else if (currentroot->data<val) return search(currentroot->right,val);
        else {
            return search(currentroot->left,val);
        }
    }
    return NULL;
}

void bst::deleteNode(int n) {
    Node *temp = root, *parent = NULL, *father, *r, *son;

    while (temp != NULL && temp->data != n) {
        parent = temp;
        if (n < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp == NULL) {
        cout << "Number not found";
        return;
    }

    if (temp->left == NULL) {
        r = temp->right;
    }
    // Case 2: Only left child
    else if (temp->right == NULL) {
        r = temp->left;
    }
    else {
        father = temp;
        r = temp->right;
        son = r->left;
        while (son != NULL) {
            father = r;
            r = son;
            son = r->left;
        }
        if (father != temp) {
            father->left = r->right;
            r->right = temp->right;
        }
        r->left = temp->left;
    }

    if (parent == NULL) {
        root = r;
    } else {
        if (temp == parent->left)
            parent->left = r;
        else
            parent->right = r;
    }

    delete temp;
}

int main() {
    bst b;
    int choice;
    do {
        cout<<"------Menu-----";
        cout<<"Select a option: 1) Create bst , 2) Preorder Traversal ,3) Postorder Traversal"
              "\n,4) Inorder Traversal ,5) Search node , 6) Delete node or 7)Exit";
        cin>>choice;
        switch (choice) {
            case 1:
                b.create();
            break;
            case 2:
                b.Preorder();
            cout<<"\n";
            break;
            case 3:
                b.Inorder();
            cout<<"\n";
            break;
            case 4:
                b.Postorder();
            cout<<"\n";
            break;
            case 5:
                int searchVal;
                cout<<"Input value to be searched:";
                cin>>searchVal;
                b.Search(searchVal);
                break;
            case 6:
                cout<<"Input value to be deleted";
                int delVal;
                cin>>delVal;
                b.deleteNode(delVal);
            break;
            case 7:
                cout<<"Exiting...";
            break;
        }
    }while (choice!=7);
    return 0;
}
