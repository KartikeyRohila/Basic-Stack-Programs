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
    
    // Treverse through the whole string from left to right
    for (int i=0;i<n;i++)
    {
        //If character is an alphabet then add it to the 'ans' string
        
        //If it is a '(' then push it to stack
        
        //If it is a ')' then pop everything from stack and add into 'ans' string  until we found '(' and after that discard both parenthesis
        
        //Else if character is an operator then if stack is empty push it to stack
        //if not then first check for precedence order of sacnned character and 'st.top()'
        //if precedence of 'st.top()' is less, push sacnned character to stack
        //if 'st.top()' has more precedence then pop it and add to 'ans' string until we found a less precedence operator
        //if both have same precedence then go with the asociativity of operators

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

    //Pop everthing from stack and add it to the 'ans' string
    //Print 'ans' string in the end;
    while (st.empty()==false)
    {
        char c=st.top();
        st.pop();
        ans+=c;
    }
    cout << ans <<"\n";
    return 0;
}