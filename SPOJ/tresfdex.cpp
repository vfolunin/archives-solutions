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

    for (int i = 0; i < 3; i++) {
        int value;
        cin >> value;

        cout << value * value - 3 * value + value % 10 << " ";
    }
}