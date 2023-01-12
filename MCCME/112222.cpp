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

    long long sum = 0, product = 1;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        sum += value;
        product *= value;
    }

    cout << sum << " " << product;
}