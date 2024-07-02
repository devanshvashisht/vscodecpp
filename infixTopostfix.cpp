#include <iostream>
#include <string>
#include <stack>
using namespace std;
int precedence (char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return 0;
    }
}
bool isOperand(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}
string infixToPostfix (string s) {
    stack<char> st; 
    string postFix;
    for(int i = 0; i < s.length(); i++) {
        if (isOperand(s[i])) {
            postFix += s[i];
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            while(st.top() != '(') {
                postFix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                postFix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        postFix += st.top();
        st.pop();
    }
    return postFix;
}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
  
    
    cout<<infixToPostfix(exp);
    
    return 0;
}