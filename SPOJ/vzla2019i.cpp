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

    long long res = 1;

    for (int i = 0; i < 6; i++) {
        int value;
        cin >> value;

        res *= value;
    }

    cout << res;
}