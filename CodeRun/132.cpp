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
    a.erase(unique(a.begin(), a.end()), a.end());

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        cout << lower_bound(a.begin(), a.end(), value) - a.begin() << "\n";
    }
}