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

    int toyCount;
    cin >> toyCount;

    int res = 0;
    for (int i = 0; i < toyCount; i++) {
        int count;
        double price;
        cin >> count >> price;

        if (price < 50)
            res += count;
    }

    cout << res;
}