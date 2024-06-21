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

    int size, limit;
    cin >> size >> limit;
    limit *= 100;

    int res = -1;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        int price = a * 100 + b;
        if (price <= limit)
            res = max(res, (limit - price) % 100);
    }

    cout << res;
}