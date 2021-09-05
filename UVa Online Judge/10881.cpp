#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Result {
    int index, coord;
    string dir;

    bool operator < (const Result &that) const {
        return index < that.index;
    }
};

void solve(int test) {
    int width, time, antCount;
    cin >> width >> time >> antCount;

    vector<pair<int, int>> antsBefore(antCount);
    vector<pair<int, string>> antsAfter(antCount);

    for (int i = 0; i < antCount; i++) {
        int x;
        string dir;
        cin >> x >> dir;

        antsBefore[i] = { x, i };
        if (dir == "L")
            antsAfter[i] = { x - time, dir };
        else
            antsAfter[i] = { x + time, dir };
    }

    sort(antsBefore.begin(), antsBefore.end());
    sort(antsAfter.begin(), antsAfter.end());

    vector<Result> res(antCount);
    
    for (int i = 0; i < antCount; i++) {
        res[i].index = antsBefore[i].second;
        res[i].coord = antsAfter[i].first;
        res[i].dir = antsAfter[i].second;
    }

    for (int i = 0; i + 1 < antCount; i++)
        if (res[i].coord == res[i + 1].coord)
            res[i].dir = res[i + 1].dir = "Turning";

    sort(res.begin(), res.end());

    cout << "Case #" << test << ":\n";
    for (auto &[_, coord, dir] : res) {
        if (0 <= coord && coord <= width)
            cout << coord << " " << dir << "\n";
        else
            cout << "Fell off\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}