#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<string> chosenApps;

    for (int i = 0; i < size; i++) {
        int appCount;
        cin >> appCount;

        vector<string> apps(appCount);
        for (string &app : apps)
            cin >> app;

        for (string &app : apps) {
            if (!chosenApps.count(app)) {
                cout << app << " ";
                chosenApps.insert(app);
                break;
            }
        }
    }
}