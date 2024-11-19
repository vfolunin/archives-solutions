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

    vector<unsigned long long> a;
    for (unsigned long long value; cin >> value; )
        a.push_back(value);

    sort(a.begin(), a.end());

    unsigned long long sum = 0;
    for (unsigned long long value : a) {
        if (sum + 1 < value) {
            cout << sum + 1;
            return 0;
        }
        sum += value;
    }

    cout << sum + 1;
}