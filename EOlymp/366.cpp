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

    int divisor;
    cin >> divisor;

    vector<int> remainder(10);
    for (int size = 1; size <= divisor; size++) {
        for (int digit = 1; digit < remainder.size(); digit++) {
            remainder[digit] = (remainder[digit] * 10 + digit) % divisor;
            if (!remainder[digit]) {
                cout << digit << " " << size;
                return 0;
            }
        }
    }

    cout << "0 0";
}