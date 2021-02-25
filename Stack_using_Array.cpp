#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    int cap;
    int *arr;
    int top;
    MyStack (int x)
    {
        cap=x;
        arr= new int [x];
        top=-1;
    }

    void push (int x)
    {
        if (top==(cap-1))
        {
            cout << "\nStack is full insertion not possible\n";
            return;
        }
        cout << "\nInsertion complete\n";
        top++;
        arr[top]=x;
    }

    void pop ()
    {
        if (top==-1)
        {
            cout << "\nStack is empty deletion not possible\n";
            return;
        }
        int res=arr [top];
        cout << "\nDeletion complete element "<< res <<" is deleted\n";
        top--;
    }

    void peek ()
    {
        if (top==-1)
        {
            cout << "\nStack is empty\n";
            return;
        }
        cout << "\nTop value of stack is "<< arr[top] <<"\n";
    }

    void size ()
    {
        cout << "\nSize of stack is "<< (top+1) <<"\n";
    }
    
    void isEmpty ()
    {
        if (top==-1)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack is not empty\n";
    }
};

int main ()
{
    int n=0,temp;
    cout << "\nInput size of stack : ";
    cin >> temp;
    MyStack s(temp);
    cout << "\nStack of size "<< temp <<" is created\n";
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