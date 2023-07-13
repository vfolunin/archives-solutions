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
    n--;

    if (n > 7)
        cout << n - 7 << " ";
    if (n % 8)
        cout << n << " ";
    if (n % 8 < 7)
        cout << n + 2 << " ";
    if (n < 56)
        cout << n + 9;
}