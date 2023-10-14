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

    set<long long> values = { 1 };
    for (int i = 1; i < n; i++) {
        long long value = *values.begin();
        values.erase(values.begin());

        for (int factor : { 2, 3, 5 })
            values.insert(factor * value);

        while (values.size() > n - i)
            values.erase(prev(values.end()));
    }

    cout << *values.begin();
}