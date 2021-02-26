#include <bits/stdc++.h>
using namespace std;

//Function to check weather a given character is an operator or not
//Return 1 if it is an operator else return 0
int isoperator(char c)
{
    if (c=='^' || c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    return 0;
}

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
    int n,flag=0;
    cin >> s;
    n=s.length();

    for (int i=0;i<n;i++)
    {
        if ( (isalpha(s[i])==0) && (isoperator(s[i])==0) && s[i]!=' ')
        {
            flag=1;
            break;
        }
    }

    if (flag==1)
    {
        cout << "\nExpression is invalid\n";
    }
    else
    {
        cout << "\nExpression is valid\n";
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
    }
    return 0;
}