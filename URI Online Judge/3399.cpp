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

    long long a, b, c, index;
    cin >> a >> b >> c >> index;

    cout << a + (b - a) * (index - 1) << "\n";
}