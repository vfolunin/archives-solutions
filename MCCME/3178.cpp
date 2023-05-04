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

    int sum = 0, prev, cur = 0;

    for (int i = 0; !i || prev != cur; i++) {
        prev = cur;
        cin >> cur;
        sum += cur;
    }

    cout << sum;
}