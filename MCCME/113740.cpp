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

    int limit, size;
    cin >> limit >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    unsigned long long res = 0;
    while (1) {
        while (!a.empty() && !a.back())
            a.pop_back();

        if (a.empty())
            break;

        long long cycles = a.back() / limit;
        res += a.size() * 2 * cycles;
        a.back() %= limit;

        if (!a.back())
            continue;

        res += a.size() * 2;
        long long sum = 0;
        for (int i = a.size() - 1; sum < limit && i >= 0; i--) {
            long long delta = min<long long>(limit - sum, a[i]);
            sum += delta;
            a[i] -= delta;
        }
    }

    cout << res;
}