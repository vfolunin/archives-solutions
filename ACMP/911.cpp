#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int targetWeight, vector<int> &left, vector<int> &right) {
    if (!targetWeight)
        return;

    int sum = 0, weight = 1;
    while (sum + weight < targetWeight) {
        sum += weight;
        weight *= 3;
    }

    left.push_back(weight);

    if (targetWeight >= weight)
        rec(targetWeight - weight, left, right);
    else
        rec(weight - targetWeight, right, left);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char side;
    int targetWeight;
    cin >> side >> targetWeight;

    vector<int> left, right;
    if (side == 'R')
        rec(targetWeight, left, right);
    else
        rec(targetWeight, right, left);
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());

    cout << "L:";
    for (int value : left)
        cout << value << " ";
    cout << "\nR:";
    for (int value : right)
        cout << value << " ";
}