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

    int submissionCount;
    cin >> submissionCount;

    map<string, int> judgeA;
    for (int i = 0; i < submissionCount; i++) {
        string verdict;
        cin >> verdict;
        judgeA[verdict]++;
    }

    map<string, int> judgeB;
    for (int i = 0; i < submissionCount; i++) {
        string verdict;
        cin >> verdict;
        judgeB[verdict]++;
    }

    int res = 0;
    for (auto &[verdict, count] : judgeA)
        res += min(count, judgeB[verdict]);

    cout << res;
}