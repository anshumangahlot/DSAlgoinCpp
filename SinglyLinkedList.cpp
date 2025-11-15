#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class List{
    Node *listptr,*temp;
    public:
    List(){
        listptr=NULL;
        temp=NULL;
    }
    void create();
    void display();

    void insert_start();
    void insert_last();
    void insert_intermediate();
    void insert_afterspecific();

    void delete_start();
    void delete_last();
    void delete_intermediate();
    void delete_afterspecific();

    void reverse();
    void concat();
    void merge();

    Node* get_head() { return listptr; }
};

void List::create(){
    int x;int n;string j;
    cout<<"Enter no. of nodes";
    cin>>n;

    for (int i=0;i<n;i++) {
        cout<<"Enter value for node";
        // getline(cin,j);;
        cin>>x;
        Node* newNode = new Node;
        newNode->data=x;
        newNode->next=NULL;

        if (listptr == NULL) {
            listptr=newNode;
            temp=newNode;
        }
        else {
            temp->next=newNode;
            temp=newNode;
        }
    }
}
void List::display(){
    temp=listptr;
    while (temp->next!=NULL) {
        cout<< temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}

void List::insert_start() {
    int x;
    Node * newNode=new Node;
    cout<<"Enter value of node";
    cin>>x;
    newNode->data=x;
    newNode->next=listptr;
    listptr=newNode;
}

void List::insert_intermediate() {
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
    int x;
    Node * newNode=new Node;
    cin>>x;
    newNode->data=x;
    newNode->next=NULL;
    temp=listptr;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

void List::insert_afterspecific() {
    int x, val;
    cout << "Enter the value of the new node to insert: ";
    cin >> x;
    cout << "Enter the value of the node after which to insert: ";
    cin >> val;

    Node* current = listptr;
    while (current != NULL && current->data != val) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Node with value " << val << " not found in the list." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = current->next;
    current->next = newNode;
}

void List::delete_start() {
    temp=listptr;
    listptr=listptr->next;
    delete(temp);
}

void List::delete_last() {
    temp=listptr;
    while (temp->next->next != NULL) {
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
}

void List::delete_intermediate() {
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

void List::delete_afterspecific() {
    int x;
    cout<<"Enter Node";
    cin>>x;
    temp=listptr;
    Node* q=new Node;
    while (temp->next->data != x) {
        temp=temp->next;
    }
    q=temp->next;
    temp->next = temp->next->next;
    delete(q);
}

void List::reverse() {
    Node* back= nullptr;
    Node* curr= listptr;
    Node* next= nullptr;
    while (curr!=nullptr) {
        next=curr->next;
        curr->next=back;
        back=curr;
        curr=next;
    }
    listptr=back;
}

void List::concat() {
    List l2;
    l2.create();
    cout<<"Second linkedlist: ";
    l2.display();
    Node* listptr2=l2.get_head();

    temp=listptr;
    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    temp->next=listptr2;

    temp=listptr;
    cout<<"\nConcatenated linkedlist: ";
    while (temp->next!=NULL) {
        cout<< temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;

}
void List::merge() {
    List l2;
    cout << "Create second list to merge: ";
    l2.create();

    cout<<"Second linkedlist: ";
    l2.display();

    Node* current = listptr;
    if (current == nullptr) {
        listptr = l2.get_head();
        l2.listptr = nullptr;
        return;
    }

    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = l2.get_head();
    l2.listptr = nullptr;

    Node* head = listptr;
    Node* i, *j;
    int temp_data;

    for (i = head; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                temp_data = i->data;
                i->data = j->data;
                j->data = temp_data;
            }
        }
    }

    temp=listptr;
    cout<<"\nMerged linkedlist: ";
    while (temp->next!=NULL) {
        cout<< temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    List l;
    int p=14,ch;
    while(p==14){
        cout<<"\n Enter Choice: \n1) create \n2) display \n3) insert (start) "
              "\n4) insert (intermediate)  \n5)insert (last) \n6) delete (start) "
              "\n7)delete (last) \n8)delete (intermediate) \n9)delete (after specific)\n"
              "10)Reverse\n11)concat\n12)merge\n13)insert after specific";
        cin>>ch;
        switch(ch){
            case 1:
                l.create();
            break;
            case 2:
                l.display();
            break;
            case 3:
                l.insert_start();
            break;
            case 4:
                l.insert_intermediate();
            break;
            case 5:
                l.insert_last();
            break;
            case 6:
                l.delete_start();
            break;
            case 7:
                l.delete_last();
            break;
            case 8:
                l.delete_intermediate();
            break;
            case 9:
                l.delete_afterspecific();
            break;
            case 10:
                l.reverse();
            break;
            case 11:
                cout<<"First linkedlist: ";
            l.display();
            l.concat();
            break;
            case 12:
                cout<<"First linkedlist: ";
            l.display();
            l.merge();
            break;
            case 13:
                l.insert_afterspecific();
            break;
        }
        cout<<"\n\nPRESS 14 TO CONTINUE: ";
        cin>>p;
    }
    return 0;
}
