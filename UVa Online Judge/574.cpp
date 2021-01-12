#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(const vector<int> &numbers, int step, vector<int> &subset, int sum, int targetSum, set<vector<int>> &subsets) {
    if (sum == targetSum) {
        subsets.insert(subset);
        return;
    }

    if (step == numbers.size() || sum > targetSum)
        return;

    rec(numbers, step + 1, subset, sum, targetSum, subsets);

    subset.push_back(numbers[step]);
    rec(numbers, step + 1, subset, sum + numbers[step], targetSum, subsets);
    subset.pop_back();
}

bool solve() {
    int targetSum, numberCount;
    cin >> targetSum >> numberCount;

    if (!targetSum && !numberCount)
        return 0;

    vector<int> numbers(numberCount);
    for (int &x : numbers)
        cin >> x;

    set<vector<int>> subsets;
    vector<int> subset;
    rec(numbers, 0, subset, 0, targetSum, subsets);

    cout << "Sums of " << targetSum << ":\n";
    if (subsets.empty()) {
        cout << "NONE\n";
    } else {
        for (auto it = subsets.rbegin(); it != subsets.rend(); it++)
            for (int i = 0; i < it->size(); i++)
                cout << (*it)[i] << (i + 1 < it->size() ? '+' : '\n');
    }    
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}