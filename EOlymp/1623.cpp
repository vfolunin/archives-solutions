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

    int even = 0, odd = 0;
    for (int i = 0; i < 3; i++) {
        int value;
        cin >> value;

        even += value % 2 == 0;
        odd += value % 2 != 0;
    }

    cout << (even && odd ? "YES" : "NO");
}