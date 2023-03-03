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

    vector<int> travelTime(3);
    for (int &time : travelTime)
        cin >> time;

    vector<int> interval = { 15, 10, 5 };

    int time;
    cin >> time;

    int res = 1e9;
    for (int i = 0; i < interval.size(); i++)
        res = min(res, (time + interval[i] - 1) / interval[i] * interval[i] + travelTime[i] - time);

    cout << res;
}