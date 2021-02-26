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
    long long int n,flag=0;
    string s,ans="";
    cin >> s;
    n=s.length();

    //Check weather expression is valid or not
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
        cout << "\nExpression is not valid\n";
    }
    else
    {
        cout << "\nExpression is valid\n";
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
    }
    return 0;
}