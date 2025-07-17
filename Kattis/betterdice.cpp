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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    int res = 0;
    for (int aValue : a)
        for (int bValue : b)
            res += (aValue > bValue) - (aValue < bValue);

    if (res > 0)
        cout << "first";
    else if (res < 0)
        cout << "second";
    else
        cout << "tie";
}