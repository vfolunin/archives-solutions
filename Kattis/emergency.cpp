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

    long long n, d;
    cin >> n >> d;

    cout << min(n - 1, d + 1 + (n - 1) % d);
}