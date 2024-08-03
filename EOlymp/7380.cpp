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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    int res = 0;
    for (int value : a)
        if (res < b.size() && b[res] <= value)
            res++;

    cout << res;
}