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

    long long a = n + 1;
    long long b = abs(n - 1) + 1;

    if (a % 2 == 0)
        a /= 2;
    else
        b /= 2;

    cout << a * b;
}