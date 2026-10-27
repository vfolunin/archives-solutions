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

    if (sum % 3) {
        cout << 0;
        return 0;
    }

    int b = sum / 3;
    int a = b - 1;
    int c = b + 1;

    cout << (a + b > c);
}