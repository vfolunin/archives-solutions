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

    int res = 1;
    for (int i = 0; i < 6; i++) {
        long long value;
        cin >> value;

        res &= value % 42 == 0;
    }

    cout << (res ? "Yes" : "No");
}