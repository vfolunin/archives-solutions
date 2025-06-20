#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    long long a, b, mod;
    cin >> size >> a >> b >> mod;

    for (int i = 1; i <= size; i++)
        cout << ones((a * i + b) % mod) << "\n";
}