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

    int count, a, b;
    cin >> count >> a >> b;

    int sum = (a * 100 + b - 500000) * count;

    for (int i = 0; i < count; i++) {
        int delta = min(sum, 9500000);
        sum -= delta;

        cout << delta / 100 + 5000 << " ";
    }
}