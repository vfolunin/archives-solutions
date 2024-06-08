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

    cout << n / 5 * 2 << " " << (n / 5 * 3 + 1) / 2 << " " << n / 5 * 3 / 2;
}