#include<iostream>
#include<string>
stack<char> s;
bool operand(char a)
{
    if(a>=0 && a<=9)
    return true;
    else return false;
}
string infixtopostfix(string s)
{  string res;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]==',' || s[i]==' ')
        continue;
        else if(operand(s[i]))
        res+=s[i];
        else if(s[i]=='(')
        s.push(s[i]);
        else if(s[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                res+=s.top();
                s.pop();
            }
            s.pop();
        }
        else {
        while(ihigherprecedence(s[i],s.top())==1 && !s.empty() && s.top!='(')
        {

        }
        
    }
}
int main(void)
{
    string s;
    getline(cin,s);
    cout<<infixtopostfix(s);
}
