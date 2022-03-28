#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int problemCount, totalTime;
    cin >> problemCount >> totalTime;

    long long a, b, c;
    vector<long long> problemTime(problemCount);
    cin >> a >> b >> c >> problemTime[0];

    for (int i = 1; i < problemTime.size(); i++)
        problemTime[i] = (a * problemTime[i - 1] + b) % c + 1;

    sort(problemTime.begin(), problemTime.end());

    int solvedCount = 0;
    long long curTime = 0, penalty = 0;
    for (long long time : problemTime) {
        if (totalTime >= time) {
            totalTime -= time;
            solvedCount++;
            curTime = (curTime + time) % MOD;
            penalty = (penalty + curTime) % MOD;
        }
    }

    cout << solvedCount << " " << penalty;
}