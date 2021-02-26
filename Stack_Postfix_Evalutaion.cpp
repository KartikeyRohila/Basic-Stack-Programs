#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack <int> st;     //Create an empty stack
    long long int n;
    string s;
    getline (cin,s);
    n=s.length();

    for (int i=0;i<n;i++)
    {
        if (s[i]==' ')
            continue;
        else if ('0'<=s[i] && s[i]<='9')
        {
            int temp=0;

            //To store the multi digit number
            while (s[i]!=' ')
            {
                temp=(temp*10)+(s[i]-'0');
                i++;
            }
            i--;
            st.push (temp);
        }
        else
        {
            int p2=st.top();
            st.pop();
            int p1=st.top();
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
                    temp=pow (p1,p2);
                    break;
            }
            st.push(temp);
        }
    }

    //Print final value in the stack
    cout << st.top() <<"\n";
    return 0;
}