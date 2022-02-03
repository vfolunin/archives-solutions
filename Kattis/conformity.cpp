#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    map<set<int>, int> courseSetPopularity;
    int maxPopularity = 0;

    for (int i = 0; i < n; i++) {
        set<int> courseSet;
        for (int j = 0; j < 5; j++) {
            int course;
            cin >> course;
            courseSet.insert(course);
        }
        maxPopularity = max(maxPopularity, ++courseSetPopularity[courseSet]);
    }

    int res = 0;
    for (auto &[_, popularity] : courseSetPopularity)
        if (popularity == maxPopularity)
            res += popularity;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}