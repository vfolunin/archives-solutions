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

    long long sum;
    cin >> sum;

    for (long long count = 1e5; 1; count--) {
        if (sum * 2 % count)
            continue;
        long long from = sum * 2 / count - count + 1;

        if (from % 2)
            continue;
        from /= 2;

        if (from > 0) {
            cout << from << " " << count;
            return 0;
        }
    }
}