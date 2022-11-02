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

    long long product = 1;

    for (int i = 0; i < 30; i++) {
        int value;
        cin >> value;

        if (value < 0)
            product *= value;
    }

    cout << product;
}