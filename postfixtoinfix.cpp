#include<iostream>
#include<stack>
using namespace std;

void postfixToInfix(string s) {
    stack<string> st;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is an operand, push it onto the stack
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            string op(1, c);  // Convert char to string
            st.push(op);
        }
        // If the character is an operator
        else {
            // Pop two elements from stack
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form a string with parentheses around the expression
            string expr = "(" + op2 + c + op1 + ")";

            // Push the resulting expression back onto the stack
            st.push(expr);
        }
    }

    // The final result on the stack is the infix expression
    cout << "Infix Expression: " << st.top() << endl;
}

int main() {
    string postfix;
    cout << "Enter Postfix: ";
    cin >> postfix;
    postfixToInfix(postfix);

    return 0;
}
