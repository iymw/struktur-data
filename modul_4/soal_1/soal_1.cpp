#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool callFunction(string s) {
    stack<char> st;

    for (char kurungSiku : s) {
        if (kurungSiku == '(' || kurungSiku == '{' || kurungSiku == '[') {
            st.push(kurungSiku);
        } else {
            if (st.empty()) {
                return false;
            } else if ((kurungSiku == ')' && st.top() == '(') ||
                       (kurungSiku == '}' && st.top() == '{') ||
                       (kurungSiku == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (callFunction(s)) {
        cout << "Mark Lee Hebat" << endl;
    } else {
        cout << "Coba lagi sampe dapet" << endl;
    }

    return 0;
}