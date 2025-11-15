#include <iostream>
using namespace std;

//circular linked list: create ,
//insert beginning middle end , delete first middle last ,
//reverse and concatenation.

class Node{
public:
    int data;
    Node* next;
};

class List:public Node {
    Node *listptr,*temp;
public:
    List(){
        listptr=NULL;
        temp=NULL;
    }
    void create();
    void display();
    void insert_start();
    void insert_middle();
    void insert_last();
    void delete_start();
    void delete_last();
    void delete_middle();
    void reverse();
    void concat(List l1,List l2);
    Node* get_head(){return listptr;}
};

void List::create() {
    int x;int n;
    cout<<"Enter no. of nodes";
    cin>>n;

    for (int i=0;i<n;i++) {
        cout<<"Enter value for node";
        cin>>x;
        Node* newnode = new Node;
        newnode->data=x;
        newnode->next=NULL;
        if (listptr==NULL) {
            listptr=newnode;
            temp=newnode;
            newnode->next=listptr;
        }
        else {
            temp->next=newnode;
            newnode->next=listptr;
            temp=newnode;
        }
    }
}

void List::display() {
    temp=listptr;
    while (temp->next!=listptr) {
        cout<< temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data << "->";
    cout<< listptr->data << endl;
}

void List::insert_start() {
    //insert at start and point last one to newnode.
    int x;
    Node * newNode=new Node;
    cout<<"Enter value of node";
    cin>>x;
    newNode->data=x;
    newNode->next=listptr;
    temp=listptr;
    while (temp->next != listptr) {
        temp=temp->next;
    }
    temp->next=newNode;
    listptr=newNode;
}
void List::insert_middle() {
    //same as sll
    int x,p,i=0;
    Node* newNode= new Node;
    cout<<"Enter value of node";
    cin>>x;
    newNode->data=x;
    newNode->next=NULL;
    cout<<"Enter position ";
    cin>>p;
    temp=listptr;
    while (i<p-1) {
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void List::insert_last() {
    //insert at last and point to listptr.
    int x;
    Node* newnode=new Node;
    cout<<"enter value of node";
    cin>>x;
    newnode->data=x;
    newnode->next=NULL;
    Node* temp= listptr;
    while (temp->next!=listptr) {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=listptr;
}


void List::delete_start() {
    Node* temp=listptr;
    while (temp->next!=listptr) {
        temp=temp->next;
    }
    temp->next=NULL;
    Node* q = listptr;
    listptr=listptr->next;
    delete(q);
    temp->next=listptr;
}

void List::delete_middle() {
    int x;
    int i=0;
    cout<<"Enter position to delete";
    cin>>x;
    Node* q=new Node;
    temp=listptr;
    while (i<=x-1) {
        temp=temp->next;
        i++;
    }
    q=temp->next;
    temp->next=temp->next->next;
    delete(q);
}
void List::delete_last() {
    Node* temp=listptr;
    while (temp->next->next!=NULL) {
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=listptr;
}

void List::reverse() {
    //cycle break.
    //reverse.
    //cycle again made.
    if (listptr==NULL || listptr->next==listptr) return;

    Node* oldlistptr=listptr;
    Node* temp=listptr;
    while (temp->next!=listptr) {
        temp=temp->next;
    }
    temp->next=NULL;

    Node* back=NULL;
    Node* curr=listptr;
    Node* nextt= NULL;
    while(curr!=NULL) {
        nextt=curr->next;
        curr->next=back;
        back=curr;
        curr=nextt;
    }
    listptr=back;

    oldlistptr->next=listptr;
}


void List::concat(List l1, List l2) {
    Node* temp1=l1.get_head();
    Node* listptr1=l1.get_head();
    Node* temp2=l2.get_head();
    Node* listptr2=l2.get_head();
    while (temp1->next!=listptr1) {
        temp1=temp1->next;
    }
    temp1->next=listptr2;
    while (temp2->next!=listptr2) {
        temp2=temp2->next;
    }
    temp2->next=listptr1;
}

int main() {
    List l1;
    List l2;
    l1.create();
    l1.display();
    l1.reverse();
    // l2.create();
    // l2.display();
    // l1.concat(l1,l2);
    l1.display();
}
