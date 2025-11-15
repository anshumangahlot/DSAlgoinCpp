#include <iostream>
using namespace std;

//doubly linked list: create , insert beginning middle end ,
//delete first middle last , reverse and concatenation.

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class List:public Node {
    Node* listptr;
    Node* temp;
public:
    List() {
        listptr=NULL;
        temp=NULL;
    }
    void create();
    void display();
    void insert_beginning();
    void insert_middle();
    void insert_end();
    void delete_beginning();
    void delete_middle();
    void delete_end();
    void reverse();
    void concatenation(List l1, List l2);
    Node* get_head(){return listptr;}
};

void List::create() {
    int x,n;
    cout << "Enter no. of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node: ";
        cin >> x;
        Node* newnode= new Node;
        newnode->data=x;
        newnode->prev=NULL;
        newnode->next=NULL;
        if (listptr==NULL) {
            listptr=newnode;
            temp=listptr;
        }
        else {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
}

void List::display() {
    temp=listptr;
    while (temp->next!=NULL) {
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<temp->data;
}

void List::insert_beginning() {
    Node* newnode= new Node;
    int x;
    cout<<"Insert value of the node :";
    cin>>x;
    newnode->data=x;
    newnode->next=listptr;
    newnode->prev=NULL;
    if (listptr!=NULL) {
        listptr->prev=newnode;
    }
    listptr=newnode;
}

void List::insert_middle() {
    Node* newnode= new Node;
    int x,n;
    cout<<"Insert value of the node :";
    cin>>x;
    newnode->data=x;
    cout<<"enter value of the position :";
    cin>>n;
    temp=listptr;
    for (int i=0;i<n-1;i++) {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
}

void List::insert_end() {
    Node* newnode= new Node;
    int x,n;
    cout<<"Insert value of the node :";
    cin>>x;
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    temp=listptr;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void List::delete_beginning() {
    temp=listptr;
    listptr=listptr->next;
    listptr->prev=NULL;
    delete(temp);
}
void List::delete_middle() {
    int n;
    cout<<"enter value of the position :";
    cin>>n;
    temp=listptr;
    for (int i=0;i<n-1;i++) {
        temp=temp->next;
    }
    Node* q= new Node;
    q=temp;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(q);
}
void List::delete_end() {
    temp=listptr;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    Node* q = new Node;
    q=temp;
    temp->prev->next=NULL;
    temp->prev=NULL;
    delete(q);
}

void List::reverse() {
    Node* temp=listptr;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    while (temp->prev!=NULL) {
        cout<<temp->data<<"<->";
        temp=temp->prev;
    }
    cout<<temp->data;
}

void List::concatenation(List l1, List l2) {
    Node* temp1=l1.get_head();
    Node* temp2=l2.get_head();
    while (temp1->next!=NULL) {
        temp1=temp1->next;
    }
    temp1->next=temp2;
    temp2->prev=temp1;
}



int main() {
    List l1,l2;
    l1.create();
    l1.display();
    l2.create();
    l2.display();
    // l.reverse();
    // cout<<"\n";
    l1.concatenation(l1,l2);
    l1.display();
}
