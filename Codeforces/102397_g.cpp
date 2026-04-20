#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetSum;
    cin >> size >> targetSum;

    unordered_map<int, int> seen;
    long long aScore = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        aScore += seen[targetSum - value];
        seen[value]++;
    }

    seen.clear();
    long long bScore = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        bScore += seen[targetSum - value];
        seen[value]++;
    }

    if (aScore > bScore)
        cout << "Mahmoud";
    else if (aScore == bScore)
        cout << "Draw";
    else
        cout << "Bashar";
}