#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data=x;
        next=NULL;
    }
};

class StackLL {
    Node* top;
public:
    StackLL() {
        top=NULL;
    }

    bool isEmpty() {
        return top==NULL;
    }

    void push(int x) {
        Node* newnode=new Node(x);
        newnode->next=top;
        top=newnode;
    }

    void pop() {
        if (isEmpty()) {
            cout<<"stack underflow";
            return;
        }
        Node* temp=top;
        int val=temp->data;
        top=top->next;
        delete(temp);
    }

    int peek() {
        if (isEmpty()) {
            cout<<"Stack is empty";
            return -1;
        }
        return top->data;
    }

    void display() {
        cout<<"stack(top to bottom):";
        Node* temp=top;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

class QueueLL {
    Node* front;
    Node* rear;
public:
    QueueLL() {
        front=rear=NULL;
    }
    bool isEmpty() {
        return front==NULL;
    }

    void enqueue(int x) {
        Node* newnode=new Node(x);
        if (rear==NULL) {
            front=rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=newnode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"queue underflow";
            return;
        }
        Node* temp=front;
        front=front->next;
        if (front==NULL) {
            rear=NULL;
        }
        delete temp;
    }

    int getFront() {
        if (isEmpty()) {
            cout<<"Queue is empty";
            return -1;
        }
        return front->data;
    }
};

int main() {
    StackLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();

    cout << "\n";

    QueueLL q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element: " << q.getFront() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.getFront() << endl;
    return 0;
}
