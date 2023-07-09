#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack
{
public:
    Node* head = NULL;
    Node* tail = NULL;

    int sz = 0;

    void push(int val)
    {
        sz++;
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop()
    {
        sz--;
        Node* delNode = tail;
        tail = tail->prev;

        delete delNode;
        if (tail == NULL)
        {
            head = NULL;
        }
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if(sz == 0) return true;
        else return false;
    }

};

class myQueue
{
public:
    Node* head = NULL;
    Node* tail = NULL;

    int sz = 0;

    void push(int val)
    {
        sz++;
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop()
    {
        sz--;
        Node* delNode = head;
        head = head->next;
        delete delNode;
        if (head == NULL)
        {
            tail = NULL;
        }

    }

    int front()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if(sz == 0) return true;
        else return false;
    }

};

void insert_tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);

    if (tail == NULL)
    {
        head= newNode;
        tail= newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}



int main() {
    myStack st;
    myQueue q;


    int n, m;
    cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin>> x;

        st.push(x);
    }

    for (int i = 0; i < m; ++i) {
        int y;
        cin>>y;

        q.push(y);
    }

    if (n != m)
    {
        cout<<"NO";
    }else{
        int flag = 1;

        while(!st.empty())
        {
            if (st.top() != q.front())
            {
                flag = 0;
            }
            st.pop();
            q.pop();
        }

        if (flag == 1)
        {
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }

    return 0;
}