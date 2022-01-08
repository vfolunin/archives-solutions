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

    int currentCount, newerCount;
    cin >> currentCount >> newerCount;

    map<int, int> current;
    for (int i = 0; i < currentCount; i++) {
        int app, version;
        cin >> app >> version;
        current[app] = version;
    }

    map<int, int> newer;
    for (int i = 0; i < newerCount; i++) {
        int app, version;
        cin >> app >> version;
        if (current[app] < version)
            newer[app] = max(newer[app], version);
    }

    for (auto &[app, version] : newer)
        cout << app << " " << version << "\n";
}