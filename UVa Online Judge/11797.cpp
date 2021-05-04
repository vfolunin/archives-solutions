#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int sitTime, travelTime;
    string name;
    cin >> sitTime >> travelTime >> name;

    vector<string> names = { "Ja", "Sam", "Sha", "Sid", "Tan" };
    vector<deque<int>> queue(5);

    for (int i = 0; i < 5; i++) {
        int size;
        cin >> size;
        queue[i].resize(size);

        for (int &index : queue[i]) {
            string name;
            cin >> name;
            index = find(names.begin(), names.end(), name) - names.begin();
        }
    }

    int time = 0, index = find(names.begin(), names.end(), name) - names.begin();
    vector<int> totalSitTime(5);

    while (time < travelTime) {
        int delta = min(travelTime - time, sitTime);
        totalSitTime[index] += delta;
        time += delta + 2;
        int nextIndex = queue[index].front();
        queue[index].pop_front();
        queue[index].push_back(nextIndex);
        index = nextIndex;
    }

    cout << "Case " << test << ":\n";
    for (int i = 0; i < 5; i++)
        cout << names[i] << " " << totalSitTime[i] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}