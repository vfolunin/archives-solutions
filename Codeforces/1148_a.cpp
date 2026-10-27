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

    long long a, b, ab;
    cin >> a >> b >> ab;

    cout << (min(a, b) + ab) * 2 + (a != b);
}