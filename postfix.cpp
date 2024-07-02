#include <iostream>
#include<stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<char> st;

    for (int i = 0; i < exp.size(); ++i) {
        if (isdigit(exp[i])) {
            st.push(exp[i] - '0');
        } else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            if (exp[i] == '+') {
                st.push(val2 + val1);
            } else if (exp[i] == '-') {
                st.push(val2 - val1);
            } else if (exp[i] == '*') {
                st.push(val2 * val1);
            } else if (exp[i] == '/') {
                st.push(val2 / val1);
            }
        }
    }

    return st.top();
}

int main() {
    string exp = "231*+9-";

    cout << "Postfix evaluation: " << evaluatePostfix(exp) << endl;

    return 0;
}