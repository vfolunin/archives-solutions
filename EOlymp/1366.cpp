#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getLisSize(vector<int> &a) {
    vector<int> lisLast(a.size() + 1, 1e9);
    lisLast[0] = -1e9;

    for (int value : a)
        *lower_bound(lisLast.begin(), lisLast.end(), value) = value;

    int lisSize = a.size();
    while (lisLast[lisSize] == 1e9)
        lisSize--;
    return lisSize;
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << getLisSize(a) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}