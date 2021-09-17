#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int programCount;
    cin >> programCount;

    if (!programCount)
        return 0;

    vector<int> programs(programCount);
    for (int &p : programs)
        cin >> p;
    sort(programs.begin(), programs.end());

    int pointCount;
    cin >> pointCount;

    map<int, set<int>> points;
    for (int i = 0; i < pointCount; i++) {
        int level, point;
        cin >> level >> point;
        points[level].insert(point);
    }

    vector<int> bestPrograms;
    map<int, int> bestError;
    do {
        set<int> times = { (int)-1e9, (int)1e9 };
        int time = 0;
        for (int program : programs) {
            time += program;
            times.insert(time);
        }

        map<int, int> error;
        for (auto &[level, levelPoints] : points) {
            for (int point : levelPoints) {
                auto r = times.upper_bound(point), l = prev(r);
                error[level] += min(abs(point - *l), abs(point - *r));
            }
        }

        if (bestError.empty() || bestError > error) {
            bestPrograms = programs;
            bestError = error;
        }
    } while (next_permutation(programs.begin(), programs.end()));

    int bestErrorSum = 0;
    for (auto &[_, error] : bestError)
        bestErrorSum += error;

    cout << "Data set " << test << "\n";
    cout << "  Order: ";
    for (int i = 0; i < programCount; i++)
        cout << bestPrograms[i] << (i + 1 < programCount ? " " : "\n");
    cout << "  Error: " << bestErrorSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}