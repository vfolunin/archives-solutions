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

    long long a, b, n;
    cin >> a >> b >> n;

    long long sum = (a * 100 + b) * n;

    cout << sum / 100 << " " << sum % 100;
}