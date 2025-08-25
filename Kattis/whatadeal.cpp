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

    vector<pair<long long, long long>> a(size);
    for (auto &[num, den] : a)
        cin >> num >> den;

    sort(a.begin(), a.end(), [](auto &lhs, auto &rhs) {
        if (lhs.first * rhs.second != lhs.second * rhs.first)
            return lhs.first * rhs.second < lhs.second * rhs.first;
        return lhs.first > rhs.first;
    });

    for (auto &[num, den] : a)
        cout << num << " " << den << "\n";
}