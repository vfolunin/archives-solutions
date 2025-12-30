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

    long long a, b, h;
    cin >> a >> b >> h;

    cout << (h - b - 1) / (a - b) + 1;
}