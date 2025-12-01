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

    int restaurantCount;
    cin >> restaurantCount;

    vector<int> group(restaurantCount);
    for (int mark = 1; mark <= 3; mark++) {
        int groupSize;
        cin >> groupSize;

        for (int i = 0; i < groupSize; i++) {
            int restaurant;
            cin >> restaurant;

            group[restaurant - 1] = mark;
        }
    }

    int res = 0;
    for (int mark = 1; mark <= 3; mark++) {
        int groupSize;
        cin >> groupSize;

        for (int i = 0; i < groupSize; i++) {
            int restaurant;
            cin >> restaurant;

            res += group[restaurant - 1] == mark;
        }
    }

    cout << res;
}