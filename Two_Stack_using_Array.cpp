#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    int cap;
    int *arr;
    int top1;
    int top2;
    MyStack (int x)
    {
        cap=x;
        arr=new int[x];
        top1=-1;
        top2=x;
    }

    void push1()
    {
        int temp;
        if (top1<top2-1)
        {
            cout << "\nInput value to insert in 1st stack : ";
            cin >> temp;
            top1++;
            arr[top1]=temp;
            cout << "\nInsertion in 1st stack completed\n";
        }
        else
        {
            cout << "\nStack 1 is full\n";
        }
    }

    void push2()
    {
        int temp;
        if (top1<top2-1)
        {
            cout << "\nInput value to insert in 2nd stack : ";
            cin >> temp;
            top2--;
            arr[top2]=temp;
            cout << "\nInsertion in 2nd stack completed\n";
        }
        else
        {
            cout << "\nStack 2 is full\n";
        }
    }

    void pop1()
    {
        if (top1==-1)
        {
            cout << "\nStack 1 is empty\n";
        }
        else
        {
            int temp=arr[top1];
            top1--;
            cout << "\n" << temp << " is popped from the stack 1\n";
        }
    }

    void pop2()
    {
        if (top2==cap)
        {
            cout << "\nStack 2 is empty\n";
        }
        else
        {
            int temp=arr[top2];
            top2++;
            cout << "\n" << temp << " is popped from the stack 2\n";
        }
    }
};

int main()
{
    int n,temp=0;
    cout << "\nInput the size of array : \n";
    cin >> n;
    MyStack s(n);
    cout <<"\nAn empty Stack is created\n";
    while (temp!=5)
    {
        cout << "\n1. Push in stack 1 \n2. Pop from stack 1";
        cout << "\n3. Push in stack 2 \n4. Pop from stack 2 \n5. Exit\n";
        cin >> temp;
        cout << "\n";
        switch (temp)
        {
            case 1:
            {
                s.push1();
                break;
            }
            case 2:
            {
                s.pop1();
                break;
            }
            case 3:
            {
                s.push2();
                break;
            }
            case 4:
            {
                s.pop2();
                break;
            }
            case 5:
            {
                cout <<"\nAll executions are completed\n";
                break;
            }
        }
    }
    return 0;
}