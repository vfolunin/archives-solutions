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

    vector<unsigned long long> fib = { 1, 1 };
    for (int i = 2; fib.back() < (1LL << 63); i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    int size;
    cin >> size;

    int res = 0;
    for (int i = 0; i < size; i++) {
        unsigned long long value;
        cin >> value;

        res += binary_search(fib.begin(), fib.end(), value);
    }

    cout << res;
}