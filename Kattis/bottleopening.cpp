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

    if (a > b) {
        for (int i = 1; i <= b; i++)
            cout << "open " << i << " using " << a << "\n";
    } else {
        cout << "impossible";
    }
}