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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    int bi = 0;
    for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
        bi += bi < b.size() && a[ai] == b[bi];

    cout << (bi == b.size() ? "Yes" : "No");
}