#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int clientCount;
    cin >> clientCount;

    queue<int> outTimes;
    for (int i = 0; i < clientCount; i++) {
        int h, m, limit;
        cin >> h >> m >> limit;

        int inTime = h * 60 + m;
        while (!outTimes.empty() && outTimes.front() <= inTime)
            outTimes.pop();

        int outTime = inTime;
        if (outTimes.size() <= limit) {
            outTime = (outTimes.empty() ? inTime : outTimes.back()) + 20;
            outTimes.push(outTime);
        }

        cout << outTime / 60 << " " << outTime % 60 << "\n";
    }
}