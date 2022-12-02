#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<int> &a, int i, string &signs, int sum, int targetSum) {
    if (i == a.size()) {
        if (sum == targetSum) {
            cout << a[0];
            for (int i = 1; i < a.size(); i++)
                cout << signs[i] << a[i];
            cout << "=" << targetSum;
            return 1;
        }
        return 0;
    }

    signs[i] = '+';
    if (rec(a, i + 1, signs, sum + a[i], targetSum))
        return 1;

    signs[i] = '-';
    if (rec(a, i + 1, signs, sum - a[i], targetSum))
        return 1;

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetSum;
    cin >> size >> targetSum;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    string signs(a.size(), ' ');
    if (!rec(a, 1, signs, a[0], targetSum))
        cout << "No solution";
}