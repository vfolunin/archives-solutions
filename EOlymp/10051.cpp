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

    vector<long long> a(3);
    for (long long &value : a)
        cin >> value;

    vector<long long> b = a;
    sort(b.begin(), b.end());

    if (b[0] == b[1] || b[1] == b[2])
        cout << 0;
    else
        cout << find(a.begin(), a.end(), b[1]) - a.begin() + 1;
}