#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string str;
    cin >> str;

    int n = str.length();
    if (n < 3) {
        cout << "Kurang gan karakternya" << endl;
        return 0;
    }

    queue<char> q;

    for (char c : str) {
        q.push(c);
    }

    bool isPalindrome = true;

    while (!q.empty()) {
        char frontChar = q.front();
        q.pop();
        
        if (frontChar != str[n - 1]) {
            isPalindrome = false;
            break;
        }
        
        n--;
    }

    if (isPalindrome) {
        cout << str << " Palindrom nih cuy" << endl;
    } else {
        cout << str << " Bukan Palindrom" << endl;
    }

    return 0;
}