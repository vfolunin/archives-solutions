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

    int n;
    cin >> n;

    set<long long> values = { 2, 3, 5 };
    for (int i = 0; i < n; i++) {
        cout << *values.begin() << " ";

        for (int factor : { 2, 3, 5 })
            values.insert(*values.begin() * factor);

        values.erase(values.begin());
    }
}