#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node (int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};

struct MyStack
{
    int sz;
    node *head;
    MyStack()
    {
        cout << "\nAn empty stack is created\n";
        head=NULL;
        sz=0;
    }
    
    void push()
    {
        cout << "\nEnter -1 to stop \nEnter values to push in stack : \n";
        int x=0,count=0;
        node *temp;
        while (x!=-1)
        {
            cin >> x;
            if (x!=-1)
            {
                temp=new node (x);
                if (head==NULL)
                {
                    head=temp;
                }
                else
                {
                    temp->next=head;
                    head->prev=temp;
                    head=temp;
                }
                sz++;
                count++;
            }
        }
        cout <<"\n"<< count << " Values pushed in stack\n";
    }

    void pop()
    {
        if (head==NULL)
        {
            cout << "\nStack is empty\n";
            return;
        }
        else if (head->next==NULL)
        {
            delete (head);
            head=NULL;
            sz--;
            cout << "\nDeletion from stack is completed\n";
            return;
        }
        node *temp=head->next;
        delete (head);
        temp->prev=NULL;
        head=temp;
        sz--;
        cout << "\nDeletion from stack is completed\n";
    }

    void size()
    {
        if (sz==0)
            cout << "\nStack is empty\n";
        else
            cout << "\nSize of stack is "<< sz <<"\n";
    }

    void isEmpty()
    {
        if (head==NULL)
            cout << "\nStack is empty\n";
        else
            cout << "\nStack is not empty\n";
    }

    void peek()
    {
        if (head==NULL)
            cout << "\nStack is empty\n";
        else
            cout << "\nPeek value of stack is "<< head->data <<"\n";
    }

    void middleelement()
    {
        node *temp=head;
        if (head==NULL)
        {
            cout << "\nStack is empty\n";
            return;
        }
        for (int i=0;i<(sz/2);i++)
            temp=temp->next;
        
        cout << "\nMiddle element of stack is "<< temp->data <<"\n";
    }

    void printstack()
    {
        node *temp=head;
        if (head==NULL)
        {
            cout << "\nStack is empty\n";
            return;
        }
        cout << "\nCurrent stack is : \n";
        while (temp!=NULL)
        {
            cout << temp->data <<" ";
            temp=temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    MyStack s;
    int n=0;
    while (n!=8)
    {
        cout << "\n1. Push into the stack \n2. Pop from the stack";
        cout << "\n3. Peek value of the stack \n4. Size of the stack";
        cout << "\n5. Check weather stack is empty or not";
        cout << "\n6. Middle element of the stack \n7. Print the stack";
        cout << "\n8. Exit \n\nEnter your choice : ";

        cin >> n;
        switch (n)
        {
            case 1:
            {
                s.push();
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
                s.middleelement();
                break;
            }
            case 7:
            {
                s.printstack();
                break;
            }
            case 8:
            {
                cout << "\nAll executions are completed\n";
                break;
            }
            default:
            {
                cout << "\nInvalid input\n";
                break;
            }
        }
    }
    return 0;
}