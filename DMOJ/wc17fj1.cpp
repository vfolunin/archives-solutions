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

    int size, divisor;
    cin >> size >> divisor;

    for (int i = 1; i <= size; i++) {
        int value;
        cin >> value;

        if (value % divisor || ((value / divisor) & (value / divisor - 1)))
            cout << i << "\n";
    }
}