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

    int queryCount;
    cin >> queryCount;

    map<int, int> lastTime, waitingTime;
    int time = 0;

    for (int i = 0; i < queryCount; i++) {
        char type;
        int arg;
        cin >> type >> arg;

        if (type == 'W') {
            time += arg - 1;
            continue;
        }

        time++;
        if (type == 'R') {
            waitingTime[arg];
            lastTime[arg] = time;
        } else {
            waitingTime[arg] += time - lastTime[arg];
            lastTime.erase(arg);
        }
    }

    for (auto &[id, time] : waitingTime)
        cout << id << " " << (lastTime.count(id) ? -1 : time) << "\n";
}