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

    int a, b;
    cin >> a >> b;

    if (!a && !b)
        cout << "INF";
    else if (!a || -b % a)
        cout << "NO";
    else
        cout << -b / a;
}