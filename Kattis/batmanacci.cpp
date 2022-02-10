#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> fib = { 0, 1 };
    for (int i = 2; fib.back() <= 1e18; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    long long index;
    cin >> n >> index;
    index--;

    vector<long long> fib = prepare();

    while (n > 2) {
        if (n - 2 >= fib.size() || index < fib[n - 2]) {
            n -= 2;
        } else {
            index -= fib[n - 2];
            n--;
        }
    }

    cout << (n == 1 ? "N" : "A");
}