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

    long long n;
    cin >> n;

    for (int d : { 2, 5 })
        while (n % d == 0)
            n /= d;

    cout << (n == 1 ? "NO" : "YES");
}