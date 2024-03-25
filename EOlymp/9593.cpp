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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

    for (int ai = 0, bi = 0; ai < a.size() || bi < b.size(); ) {
        if (bi == b.size() || ai < a.size() && a[ai] <= b[bi]) {
            cout << a[ai] << " ";
            ai++;
        } else {
            cout << b[bi] << " ";
            bi++;
        }
    }
}