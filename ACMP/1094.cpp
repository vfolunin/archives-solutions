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

    unsigned long long a, b, c;
    cin >> a >> b >> c;

    unsigned long long p = a + b + c;

    cout << p / 2 << (p % 2 ? ".5" : ".0");
}