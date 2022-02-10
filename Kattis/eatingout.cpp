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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ab = max(0, a + b - n);
    int abc = max(0, ab + c - n);

    cout << (abc ? "impossible" : "possible");
}