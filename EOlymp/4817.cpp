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

    for (int a, b; cin >> a >> b; )
        cout << 2 * (a + b) << " " << a * b << "\n";
}