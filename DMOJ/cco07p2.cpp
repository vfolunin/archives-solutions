#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getMinRotation(vector<int> a) {
    vector<int> res = a;
    for (int i = 0; i < a.size() - 1; i++) {
        rotate(a.begin(), a.begin() + 1, a.end());
        res = min(res, a);
    }
    return res;
}

vector<int> readSnowflake() {
    vector<int> a(6);
    for (int &value : a)
        cin >> value;

    return min(getMinRotation(a), getMinRotation({ a.rbegin(), a.rend() }));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int snowflakeCount;
    cin >> snowflakeCount;

    set<vector<int>> snowflakes;
    for (int i = 0; i < snowflakeCount; i++)
        snowflakes.insert(readSnowflake());

    cout << (snowflakes.size() == snowflakeCount ? "No two snowflakes are alike.\n" : "Twin snowflakes found.\n");
}