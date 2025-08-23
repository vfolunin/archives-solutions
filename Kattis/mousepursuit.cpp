#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time, da, db;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int eventCount;
    cin >> eventCount;

    vector<Event> events(eventCount);
    for (auto &[time, da, db] : events) {
        string type;
        cin >> type >> time >> da >> db;

        if (type == "MISS") {
            da = -da;
            db = -db;
        }
    }

    int timeLimit;
    cin >> timeLimit;

    long long sumA = 0, sumB = 0;
    for (auto &[time, da, db] : events) {
        if (time <= timeLimit) {
            sumA += da;
            sumB += db;
        }
    }

    cout << sumA << " " << sumB;
}