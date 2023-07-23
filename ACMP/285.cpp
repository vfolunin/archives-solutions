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

    int size, targetSum;
    cin >> size >> targetSum;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > targetSum) {
            cout << "no";
            return 0;
        }

        sum += value - 1;
    }

    cout << (sum + 1 >= targetSum ? "yes" : "no");
}