#include <iostream>
using namespace std;

int AVLnodes(int height)
{
    if (height == 0)
        return 1;
    else if (height == 1)
        return 2;
    return (1 + AVLnodes(height - 1) + AVLnodes(height - 2));
}

// Driver Code
int main()
{
    int H;
    string input;
    cin >> H;
    cin >> input;
    if (H < 30 && H > 0)
    {
        cout << AVLnodes(H) << endl;
    }
    else
    {
        cout << "salah bro";
    }
}