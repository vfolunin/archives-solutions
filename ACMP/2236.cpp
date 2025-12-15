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

    int d;
    cin >> d;

    for (int i = 1000; i <= 1e6; i++)
        if (i % 1000 / 100 == 2 && to_string(i)[0] == '1' && (i * 100 + 76) % d == 0)
            cout << i * 100 + 76 << " " << (i * 100 + 76) / d << "\n";
}