#include <bits/stdc++.h>
using namespace std;

//Function to reverse a number because we are treversing in array from right to left
int rev(int num,int n)
{
    int ans=0,count=0;
    while (num>0)
    {
        count++;
        ans=(ans*10)+(num%10);
        num/=10;
    }
    if (count==n)
        return ans;
    
    int temp=(n-count);
    temp=pow(10,temp);
    ans=ans*temp;
    return ans;
}

int main()
{
    stack <int> st;     //Create an empty stack
    string s;
    int n;
    getline (cin, s);
    n=s.length();

    for (int i=n-1;i>=0;i--)
    {
        if (s[i]==' ')
            continue;
        else if ('0'<=s[i] && s[i]<='9')
        {
            int temp=0,count=0;
            //To store multi digit numbers
            while (s[i]!=' ')
            {
                count++;
                temp=(temp*10)+(s[i]-'0');
                i--;
            }
            i++;
            //Reverse of number and push it to stack
            temp=rev(temp,count);
            st.push (temp);
        }
        else
        {
            int p1=st.top();
            st.pop();
            int p2=st.top();
            st.pop();
            int temp;

            switch (s[i])
            {
                case '+':
                    temp=p1+p2;
                    break;
                case '-':
                    temp=p1-p2;
                    break;
                case '*':
                    temp=p1*p2;
                    break;
                case '/':
                    temp=p1/p2;
                    break;
                case '^':
                    temp=pow(p1,p2);
                    break;
            }
            st.push(temp);
        }
    }

    //Print final value in the stack
    cout << st.top() <<"\n";
    return 0;
}