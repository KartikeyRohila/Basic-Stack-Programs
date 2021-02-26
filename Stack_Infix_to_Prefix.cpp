#include <bits/stdc++.h>
using namespace std;

//Function to check the precedence of operators
int prec (char a)
{
    if (a=='^')
        return 3;
    else if (a=='*' || a=='/')
        return 2;
    else if (a=='+' || a=='-')
        return 1;
    
    return -1;
}

int main()
{
    stack <char> st;    //Create an empty stack
    string s,ans="";
    int n;
    cin >> s;
    n=s.length();

    for (int i=n-1;i>=0;i--)
    {
        if (('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z'))
        {
            char c=s[i];
            ans+=c;
        }
        else if (s[i]==')')
            st.push(s[i]);
        else if (s[i]=='(')
        {
            while (st.empty()==false && st.top()!=')')
            {
                char c=st.top();
                st.pop();
                ans+=c;
            }
            if (st.top()==')')
            {
                st.pop();
            }
        }
        else
        {
            while (st.empty()==false && prec(s[i])<prec(st.top()))
            {
                char c=st.top();
                ans+=c;
                st.pop();
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
    reverse(ans.begin(),ans.end());
    cout << ans <<"\n";
    return 0;
}