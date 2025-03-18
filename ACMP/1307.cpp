#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetCount, targetSum;
    cin >> targetCount >> targetSum;

    vector<pair<int, int>> times;
    for (int h = 6; h <= 12; h++)
        times.push_back({ h * 60, h });
    for (int h = 13; h <= 24; h++)
        times.push_back({ h * 60, h - 12 });
    for (int h = 6; h < 24; h++)
        times.push_back({ h * 60 + 30, 1 });

    sort(times.begin(), times.end());

    for (int i = times.size() - 1; i >= targetCount - 1; i--) {
        int sum = 0;
        for (int j = 0; j < targetCount; j++)
            sum += times[i - j].second;

        if (sum == targetSum) {
            cout << setw(2) << setfill('0') << times[i].first / 60 % 24 << ":";
            cout << setw(2) << setfill('0') << times[i].first % 60;
            break;
        }
    }
}