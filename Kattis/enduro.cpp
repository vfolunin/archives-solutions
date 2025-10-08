#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int readTime() {
    int h, m, s;
    char colon;
    string part;
    cin >> h >> colon >> m >> colon >> s >> part;

    if ((h == 12) ^ (part == "PM"))
        h += 12;
    h %= 24;

    return h * 60 * 60 + m * 60 + s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int startTime = readTime();

    int size;
    cin >> size;

    unordered_map<string, int> lapCount, lastLapTime;
    unordered_set<string> finished;
    for (int i = 0; i < size; i++) {
        int time = readTime();
        if (time < startTime)
            time += 24 * 60 * 60;
        cin.ignore();

        string name;
        getline(cin, name);

        if (!finished.count(name)) {
            lapCount[name]++;
            lastLapTime[name] = time;
        }
        if (time - startTime >= 3 * 60 * 60)
            finished.insert(name);
    }

    vector<string> order(finished.begin(), finished.end());
    sort(order.begin(), order.end(), [&](string &a, string &b) {
        if (lapCount[a] != lapCount[b])
            return lapCount[a] > lapCount[b];
        return lastLapTime[a] < lastLapTime[b];
    });

    for (string &name : order)
        cout << lapCount[name] << " " << name << "\n";
}