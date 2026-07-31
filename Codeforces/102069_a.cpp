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

    long long n, m, sum;
    cin >> n >> m >> sum;

    cout << sum + (sum + n - m - 1) / (n - m) * m;
}