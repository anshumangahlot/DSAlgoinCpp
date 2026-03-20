#include <iostream>
using namespace std;

class g_node {
public:
    int vertex;
    int data;//weight
    g_node* next;

    g_node(int n=0) {
        data=0;
        vertex=n;
        next=nullptr;
    }
};

class g_list{
    g_node* temp;g_node* array[100];
    int n;
    int visited[100];
public:
    g_list(int nov) {
        n=nov;
        for (int j=0;j<n;j++) {
            array[j]=nullptr;
        }
    }

    void create();
    void display();

    void dfsIterative();
    void dfsRecursive();
    void recDFS(int v);

    void bfsIterative();
    void bfsRecursive();
    void recBfs(queue<int> &q);

    void insertVertex();
    void deleteVertex(int v);

    void prims();
};

void g_list::create() {
    g_node* newnode;
    int x,ans;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<"is there edge btw vertex"<<
                i+1<<"and"<<j+1<<"?(1/0)";
            cin>>ans;
            if (ans==1) {
                newnode=new g_node(j+1);
                cout<<"enter data: ";
                cin>>x;
                newnode->data=x;
                newnode->next=nullptr;

                if (array[i]==nullptr) {
                    array[i]=newnode;
                    temp=newnode;
                }
                else {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}

void g_list::display() {
    for (int i=0;i<n;i++) {
        cout<<"vertex "<<i+1;
        temp=array[i];
        while (temp!=nullptr) {
            cout<<"-> v"<<temp->vertex<<"="<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
}

void g_list::recDFS(int v) {
    visited[v-1]=1;
    cout<<"v "<< v<<" ";
    temp=array[v-1];
    // cout<<temp->data;
    while (temp!=nullptr) {
        int adj=temp->vertex;
        if (!visited[adj-1]) {
            recDFS(adj);
        }
        temp=temp->next;
    }
}

void g_list::dfsRecursive() {
    for (int i=0;i<n;i++) visited[i]=0;
    int start;
    cout<<"enter starting vertex(1 to n):";
    cin>>start;
    cout<<"\nrecursive dfs traversal:";
    recDFS(start);
    cout<<endl;
}

void g_list::dfsIterative() {
    int visited[100]={0};
    stack<int> s;
    int start;
    cout<<"enter vertex to start:(1 to n)";
    cin>>start;

    s.push(start);
    visited[start-1]=1;

    cout<<"iterative dfs traversal: ";
    while (!s.empty()) {
        int v=s.top();
        s.pop();
        cout<<"v"<<v<<" ";
        temp=array[v-1];
        while (temp!=nullptr) {
            int adj=temp->vertex;
            if (!visited[adj-1]) {
                visited[adj-1]=1;
                s.push(adj);
            }
            temp=temp->next;
        }
    }
    cout<<endl;
}

void g_list::bfsIterative() {
    int visited[100]={0};
    queue<int> q;
    int start;
    cout<<"enter vertex to start bfs(1 to n)";
    cin>>start;

    q.push(start);
    visited[start-1]=1;
    while (!q.empty()) {
        int v=q.front();
        q.pop();
        cout<<"v"<<v<<" ";
        temp=array[v-1];
        while (temp!=nullptr) {
            int adj=temp->vertex;
            if (!visited[adj-1]) {
                visited[adj-1]=1;
                q.push(adj);
            }
            temp=temp->next;
        }
    }
    cout<<endl;
}

void g_list::recBfs(queue<int> &q) {
    if (q.empty()) return;
    int v=q.front();
    q.pop();
    cout<<"v"<<v<<" ";
    temp=array[v-1];
    while (temp!=nullptr) {
        int adj=temp->vertex;
        if (!visited[adj-1]) {
            visited[adj-1]=1;
            q.push(adj);
        }
        temp=temp->next;
    }
    recBfs(q);
}

void g_list::bfsRecursive() {
    visited[100]={0};
    int start;
    cout<<"Enter starting vertex for bfs(1 to n)";
    cin>>start;

    queue<int> q;
    q.push(start);
    visited[start-1]=1;
    cout<<"recursive bfs traversal: ";
    recBfs(q);
    cout<<endl;
}



int main() {
    int n;
    cout<<"no. of vertices:";
    cin>>n;
    g_list g(n);
    g.create();
    g.display();

}
