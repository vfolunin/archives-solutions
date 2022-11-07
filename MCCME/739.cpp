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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    for (int i = 0; i < queryCount; i++) {
        long long value;
        cin >> value;

        cout << (binary_search(a.begin(), a.end(), value) ? "YES\n" : "NO\n");
    }
}