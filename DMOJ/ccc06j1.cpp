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

    vector<vector<int>> calories = {
        { 461, 431, 420, 0 },
        { 100, 57, 70, 0 },
        { 130, 160, 118, 0 },
        { 167, 266, 75, 0 }
    };

    int totalCalories = 0;
    for (int i = 0; i < calories.size(); i++) {
        int index;
        cin >> index;

        totalCalories += calories[i][index - 1];
    }

    cout << "Your total Calorie count is " << totalCalories << ".";
}