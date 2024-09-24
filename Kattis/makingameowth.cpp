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

    long long n, p, t1, t2;
    cin >> n >> p >> t1 >> t2;

    long long x = p * n / (n - 1);
    cout << p * t1 + x / n * t2;
}