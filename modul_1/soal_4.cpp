#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    return tmpStack;
}

int main()
{
    stack<int> input;
    string num, status = "done";

    while (true)
    {
        cin >> num;
        if (num == status)
        {
            break;
        }
        int number = stoi(num);
        input.push(number);
    }

    stack<int> tmpStack = sortStack(input);

    while (!tmpStack.empty())
    {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }
}