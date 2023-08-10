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

    string ip;
    cin >> ip >> ip;
    cin.ignore();

    int lost = 0, minTime = 1e9, maxTime = -1e9, avgTime = 0;
    for (int i = 0; i < 4; i++) {
        string s;
        getline(cin, s);

        if (s == "Time out") {
            lost++;
        } else {
            int time = stoi(s.substr(s.find('=') + 1));
            minTime = min(minTime, time);
            maxTime = max(maxTime, time);
            avgTime += time;
        }
    }

    cout << "Ping statistics for " << ip << ":\n";
    cout << "Packets: Sent = 4 Received = " << 4 - lost << " Lost = " << lost << " (" << lost * 25 << "% loss)\n";
    if (lost < 4) {
        cout << "Approximate round trip times:\n";
        cout.precision(0);
        cout << "Minimum = " << minTime << " Maximum = " << maxTime << " Average = " << fixed << avgTime / (4.0 - lost);
    }
}