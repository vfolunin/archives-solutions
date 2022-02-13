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

    map<string, int> wa;
    set<string> solved;
    int penalty = 0;

    int time;
    string problem;
    string verdict;
    while (cin >> time >> problem >> verdict) {
        if (solved.count(problem))
            continue;
        if (verdict == "right") {
            solved.insert(problem);
            penalty += time + wa[problem] * 20;
        } else {
            wa[problem]++;
        }
    }

    cout << solved.size() << " " << penalty;
}