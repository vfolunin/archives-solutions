#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int sum, int targetSum, int index, int minValue, vector<int> &a) {
    if (index == a.size()) {
        if (sum == targetSum) {
            for (int value : a)
                cout << value << " ";
            cout << "\n";
        }
        return;
    }

    if (sum + (a.size() - index) * minValue > targetSum)
        return;

    for (int value = minValue; sum + value <= targetSum; value++) {
        a[index] = value;
        rec(sum + value, targetSum, index + 1, value, a);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    rec(0, n, 0, 1, a);
}