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
    sort(a.begin(), a.end());

    vector<int> b(size);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    int ai = 0;
    for (int bi = 0; bi < b.size(); bi++)
        if (b[bi] > a[ai])
            ai++;

    cout << ai << "\n";
}