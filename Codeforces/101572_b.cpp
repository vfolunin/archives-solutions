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

    int runnerCount;
    cin >> runnerCount;

    vector<string> name(runnerCount);
    vector<double> t1(runnerCount);
    vector<double> t2(runnerCount);
    set<pair<double, string>> runners;
    for (int i = 0; i < runnerCount; i++) {
        cin >> name[i] >> t1[i] >> t2[i];
        runners.insert({ t2[i], name[i] });
    }

    double bestSum = 1e9;
    vector<string> bestNames;

    for (int i = 0; i < runnerCount; i++) {
        runners.erase({ t2[i], name[i] });

        double sum = t1[i];
        vector<string> names = { name[i] };
        for (auto it = runners.begin(); names.size() < 4; it++) {
            sum += it->first;
            names.push_back(it->second);
        }

        if (bestSum > sum) {
            bestSum = sum;
            bestNames = names;
        }

        runners.insert({ t2[i], name[i] });
    }

    cout << fixed << bestSum << "\n";
    for (string &name : bestNames)
        cout << name << "\n";
}