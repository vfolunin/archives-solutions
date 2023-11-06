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

    int a, b, n;
    cin >> a >> b >> n;

    int cost = (a * 100 + b) * n;

    cout << cost / 100 << " " << cost % 100;
}