#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int sum, int targetSum, int maxValue, vector<int> &a) {
    if (sum == targetSum) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
        return;
    }

    for (int value = 1; value <= maxValue && sum + value <= targetSum; value++) {
        a.push_back(value);
        rec(sum + value, targetSum, value, a);
        a.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a;
    rec(0, n, n, a);
}