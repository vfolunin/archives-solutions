#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    queue<vector<string>> dayQ;
    unordered_map<string, int> count;
    set<pair<int, string>> counts;

    void add(string &s, int delta) {
        counts.erase({ -count[s], s });
        count[s] += delta;
        if (count[s])
            counts.insert({ -count[s], s });
    }

    void addDay() {
        dayQ.emplace();
        if (dayQ.size() > 7) {
            for (string &s : dayQ.front())
                add(s, -1);
            dayQ.pop();
        }
    }

    void addS(string &s) {
        dayQ.back().push_back(s);
        add(s, 1);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Counter counter;

    for (string s; cin >> s; ) {
        if (s == "<text>") {
            counter.addDay();
        } else if (s == "<top") {
            int rowCount;
            cin >> rowCount >> s;

            cout << "<top " << rowCount << ">\n";
            int row = 0, lastSCount = 1;
            for (auto &[sCount, s] : counter.counts) {
                if (row < rowCount || sCount == lastSCount) {
                    cout << s << " " << -sCount << "\n";
                    row++;
                    lastSCount = sCount;
                }
            }
            cout << "</top>\n";
        } else if (s != "</text>" && s.size() >= 4) {
            counter.addS(s);
        }
    }
}