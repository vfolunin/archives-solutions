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

    if (n >= 10)
        cout << n * n * n + 5 * n;
    else
        cout << n * n - 2 * n + 4;
}