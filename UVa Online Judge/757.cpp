#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int lakeCount;
    cin >> lakeCount;
    if (!lakeCount)
        return 0;

    int timeLimit;
    cin >> timeLimit;
    timeLimit *= 12;

    vector<int> initFish(lakeCount);
    for (int &x : initFish)
        cin >> x;

    vector<int> deltaFish(lakeCount);
    for (int &x : deltaFish)
        cin >> x;

    vector<int> walkTime(lakeCount - 1);
    for (int &x : walkTime)
        cin >> x;

    vector<int> resTimeAt(lakeCount);
    int resTotalFish = -1;

    for (int last = 0; last < lakeCount; last++) {
        int time = timeLimit;
        for (int i = 0; i < last; i++)
            time -= walkTime[i];

        vector<int> curTimeAt(lakeCount), fish = initFish;
        int curTotalFish = 0;

        while (time-- > 0) {
            int i = max_element(fish.begin(), fish.begin() + last + 1) - fish.begin();
            curTimeAt[i]++;
            curTotalFish += fish[i];
            fish[i] = max(fish[i] - deltaFish[i], 0);
        }

        if (resTotalFish < curTotalFish) {
            resTotalFish = curTotalFish;
            resTimeAt = curTimeAt;
        }
    }

    if (test)
        cout << "\n";
    for (int i = 0; i < resTimeAt.size(); i++)
        cout << resTimeAt[i] * 5 << (i + 1 < resTimeAt.size() ? ", " : "\n");
    cout << "Number of fish expected: " << resTotalFish << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}