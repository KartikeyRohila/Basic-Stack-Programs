#include <bits/stdc++.h>
using namespace std;

//Function to check the precedence of operators
int prec (char c)
{
    if (c=='^')
        return 3;
    else if (c=='*' || c=='/')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    
    return -1;
}

int main()
{
    stack <char> st;    //Create an empty stack
    long long int n;
    string s,ans="";
    cin >> s;
    n=s.length();
    
    for (int i=0;i<n;i++)
    {
        if (('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z'))
        {
            ans+=s[i];
        }
        else if (s[i]=='(')
        {
            st.push('(');
        }
        else if (s[i]==')')
        {
            while (st.empty()==false && st.top()!='(')
            {
                char c=st.top();
                st.pop();
                ans+=c;
            }
            if (st.top()=='(')
            {
                st.pop();
            }
        }
        else
        {
            while (st.empty()==false && prec(s[i])<=prec(st.top()))
            {
                char c=st.top();
                st.pop();
                ans+=c;
            }
            st.push(s[i]);
        }
    }

    while (st.empty()==false)
    {
        char c=st.top();
        st.pop();
        ans+=c;
    }
    cout << ans <<"\n";
    return 0;
}