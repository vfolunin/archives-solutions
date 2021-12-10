#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int serverCount, clientCount;
    cin >> serverCount >> clientCount;

    if (!serverCount && !clientCount)
        return 0;

    vector<set<string>> serverApps(serverCount);
    for (set<string> &apps : serverApps) {
        int appCount;
        cin >> appCount;
        for (int i = 0; i < appCount; i++) {
            string app;
            cin >> app;
            apps.insert(app);
        }
    }

    int connectionCount = 0;

    for (int i = 0; i < clientCount; i++) {
        int appCount;
        cin >> appCount;
        vector<string> apps(appCount);
        for (string &app : apps)
            cin >> app;

        for (int j = 0; j < serverCount; j++) {
            for (string &app : apps) {
                if (serverApps[j].count(app)) {
                    connectionCount++;
                    break;
                }
            }
        }
    }

    cout << connectionCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}