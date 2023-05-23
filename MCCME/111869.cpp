#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;

    if (value % 10 == 0)
        cout << 1;
    else if (value % 5 == 0)
        cout << 2;
    else if (value % 2 == 0)
        cout << 5;
    else
        cout << 10;
}