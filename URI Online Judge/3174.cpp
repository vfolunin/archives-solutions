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

    int workerCount;
    cin >> workerCount;

    map<string, int> groupTime;
    for (int i = 0; i < workerCount; i++) {
        string name, group;
        int time;
        cin >> name >> group >> time;
        groupTime[group] += time;
    }

    int res = groupTime["bonecos"] / 8;
    res += groupTime["arquitetos"] / 4;
    res += groupTime["musicos"] / 6;
    res += groupTime["desenhistas"] / 12;

    cout << res << "\n";
}