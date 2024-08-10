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

    for (int ai = 0, bi = 0; ai < a.size() || bi < b.size(); ) {
        if (bi == b.size() || ai < a.size() && a[ai] <= b[bi])
            cout << a[ai++] << " ";
        else
            cout << b[bi++] << " ";
    }
}