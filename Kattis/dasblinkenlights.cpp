#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, t;
    cin >> a >> b >> t;

    cout << (lcm(a, b) <= t ? "yes" : "no");
}