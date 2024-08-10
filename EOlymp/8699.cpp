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

    vector<int> a;
    do {
        cin >> a.emplace_back();
    } while (a.size() < 3 || a[a.size() - 3] + 1 != a[a.size() - 2] || a[a.size() - 2] + 1 != a[a.size() - 1]);

    cout << a.size();
}