#include <bits/stdc++.h>
using namespace std;

int match (char a,char b)
{
    if ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
        return 1;
    
    return 0;
}

int isbalanced (string s)
{
    int n;
    stack <char> st;
    n=s.length();

    for (int i=0;i<n;i++)
    {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else
        {
            if (st.empty()==true)
                return 0;
            else if ((match(st.top(),s[i]))==0)
                return 0;
            else
                st.pop();
        }
    }

    if (st.empty()==true)
        return 1;
    
    return 0;
}

int main()
{
    string s;
    cin >> s;
    
    if ((isbalanced(s))==1)
        cout << s <<"\nYES\n";
    else
        cout << s <<"\nNO\n";
    
    return 0;
}