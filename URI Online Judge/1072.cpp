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

    int in = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        in += 10 <= x && x <= 20;
    }

    cout << in << " in\n";
    cout << n - in << " out\n";
}