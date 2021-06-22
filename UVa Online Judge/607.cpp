#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int getCost(int t, int bonus) {
    if (!t)
        return 0;
    if (t <= 10)
        return -bonus;
    return (t - 10) * (t - 10);
}

bool solve(int test) {
    int topicCount, lectureLength, bonus;
    if (!(cin >> topicCount >> lectureLength >> bonus))
        return 0;

    vector<int> topicLengthP(topicCount);
    for (int i = 0; i < topicCount; i++) {
        cin >> topicLengthP[i];
        if (i)
            topicLengthP[i] += topicLengthP[i - 1];
    }

    vector<int> minLectureCount(topicCount + 1, 1e9);
    vector<int> minCost(topicCount + 1, 1e9);
    minLectureCount[0] = minCost[0] = 0;

    for (int r = 0; r < topicCount; r++) {
        for (int l = 0; l <= r; l++) {
            if (sum(topicLengthP, l, r) > lectureLength)
                continue;

            int cost = getCost(lectureLength - sum(topicLengthP, l, r), bonus);

            if (minLectureCount[r + 1] >= minLectureCount[l] + 1) {
                minLectureCount[r + 1] = minLectureCount[l] + 1;
                minCost[r + 1] = min(minCost[r + 1], minCost[l] + cost);
            }
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";
    cout << "Minimum number of lectures: " << minLectureCount.back() << "\n";
    cout << "Total dissatisfaction index: " << minCost.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}