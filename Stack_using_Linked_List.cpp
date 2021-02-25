#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node (int x)
    {
        data=x;
        next=NULL;
    }
};

struct MyStack
{
    node *head;
    int sz;
    MyStack ()
    {
        head=NULL;
        sz=0;
    }

    void push (int x)
    {
        node *temp=new node (x);
        if (head==NULL)
        {
            sz++;
            head=temp;
            return;
        }
        temp->next=head;
        head=temp;
        sz++;
        cout << "\nInsertion complete\n";
    }

    void pop()
    {
        if (head==NULL)
        {
            cout << "\nStack is empty deletion not possible\n";
            return;
        }
        int res=head->data;
        node *temp=head;
        head=head->next;
        delete (temp);
        sz--;
        cout << "\nDeletion completed\n" << res <<" is deleted\n";
    }

    void peek()
    {
        cout << "\nTop element of stack is "<< head->data <<"\n";
    }

    void size()
    {
        cout << "\nSize of stack is "<< sz <<"\n";
    }

    void isEmpty()
    {
        if (head==NULL)
        {
            cout << "\nStack is empty\n";
            return;
        }
        cout << "\nStack is not empty\n";
    }
};

int main()
{
    MyStack s;
    cout << "\nStack is created\n";
    int n=0,temp;
    while (n!=6)
    {
        cout << "\n1. Insert in a stack \n2. Delete in a stack \n3. Find top element of stack ";
        cout << "\n4. Find size of stack \n5. Find if stack is empty \n6. Exit\n";
        cin >> n;
        switch (n)
        {
            case 1:
            {
                cout << "\nInput value to insert : ";
                cin >> temp;
                cout << "\n";
                s.push (temp);
                break;
            }
            case 2:
            {
                s.pop();
                break;
            }
            case 3:
            {
                s.peek();
                break;
            }
            case 4:
            {
                s.size();
                break;
            }
            case 5:
            {
                s.isEmpty();
                break;
            }
            case 6:
            {
                cout << "\nAll execution is complete\n";
                break;
            }
        }
    }
    return 0;
}