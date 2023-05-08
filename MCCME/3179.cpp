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

    while (1) {
        int value;
        cin >> value;

        cout << (value % 2 ? 0 : value) << " ";

        if (!value)
            break;
    }
}