#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a = { 1 };
    unordered_set<int> seen = { 1 };

    for (int i = 2; i <= n; i++) {
        a.push_back(a.back() + 2 + seen.count(i));
        seen.insert(a.back());
    }

    cout << a.back();
}