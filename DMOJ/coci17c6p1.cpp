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

    int sum;
    cin >> sum;

    sum /= 52 * 7;

    for (int i = min(sum - 1, 100); i >= 0; i--) {
        if ((sum - i) % 3 == 0) {
            cout << i << "\n" << (sum - i) / 3;
            break;
        }
    }
}