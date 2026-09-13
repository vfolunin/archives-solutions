#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    vector<long long> b(size);
    for (long long &value : b)
        cin >> value;
    sort(b.rbegin(), b.rend());

    long long sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i] * b[i];

    cout << "Case #" << test << ": " << sum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}