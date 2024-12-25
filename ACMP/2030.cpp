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

    long long a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    if (a == b)
        cout << min(a * 6 + 2, a * 7);
    else
        cout << a * 2 + b * 4;
}