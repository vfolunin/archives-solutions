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

    int size, badSum;
    cin >> size >> badSum;

    int sum = 0, hasBadSum = 0;
    for (int i = 1; i <= size; i++) {
        sum += i;
        hasBadSum |= sum == badSum;
    }

    cout << sum - hasBadSum;
}