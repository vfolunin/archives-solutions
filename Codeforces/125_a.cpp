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

    if (n % 3 <= 1)
        n -= n % 3;
    else
        n++;

    cout << n / 36 << " " << n % 36 / 3;
}