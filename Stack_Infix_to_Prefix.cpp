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

    // Treverse through the whole string from right to left
    for (int i=n-1;i>=0;i--)
    {
        //If character is an alphabet then add it to the 'ans' string
        
        //If it is a ')' then push it to stack
        
        //If it is a '(' then pop everything from stack and add into 'ans' string  until we found ')' and after that discard both parenthesis

        //Else if character is an operator then push it to stack if stack is empty
        //if not then first check for precedence order of sacnned character and 'st.top()'
        //if precedence of 'st.top()' is less or equal, push sacnned character to stack
        //if 'st.top()' has more precedence then pop it and add to 'ans' string until we found a less precedence operator

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

    //Pop everthing from stack and add it to the 'ans' string
    //Print reverse of 'ans' string in the end;
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