#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string name[100];

    for (int i = 0; i < 7; i++)
    {
        cin >> name[i];
    }

    queue<string> nameQueue;

    nameQueue.push(name[3]);
    nameQueue.push(name[1]);
    nameQueue.push(name[4]);
    nameQueue.push(name[0]);
    nameQueue.push(name[5]);
    nameQueue.push(name[2]);
    nameQueue.push(name[6]);

    while (!nameQueue.empty())
    {
        cout << nameQueue.front() << " ";
        nameQueue.pop();
    }

    cout << endl;

    return 0;
}