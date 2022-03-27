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

    string events;
    cin >> events;

    vector<vector<int>> pos(26);
    for (int i = 0; i < events.size(); i++)
        pos[events[i] - 'a'].push_back(i);

    int res = 0;
    for (int i = 0; i < events.size(); i++) {
        int event = events[i] - 'a';
        auto nextIt = upper_bound(pos[event].begin(), pos[event].end(), i);
        int nextPos = (nextIt == pos[event].end() ? events.size() : *nextIt);

        for (int otherEvent = 0; otherEvent < 26; otherEvent++) {
            if (event == otherEvent)
                continue;
            auto otherNextIt = upper_bound(pos[otherEvent].begin(), pos[otherEvent].end(), i);
            int otherNextPos = (otherNextIt == pos[otherEvent].end() ? events.size() : *otherNextIt);
            res += otherNextPos < nextPos;
        }
    }

    cout << res;
}