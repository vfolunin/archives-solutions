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

    int n;
    cin >> n;

    if (n > 0)
        cout << n * (n + 1) / 2;
    else
        cout << -(-n * (-n + 1) / 2 - 1);
}