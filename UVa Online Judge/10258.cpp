#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Result {
    int uid, ac, time;

    bool operator < (const Result &that) const {
        if (ac != that.ac)
            return ac > that.ac;
        if (time != that.time)
            return time < that.time;
        return uid < that.uid;
    }
};

void solve(int test) {
    map<int, map<int, int>> subs, acTime;

    while (cin.get() != '\n' && !cin.eof()) {
        cin.unget();

        int uid, pid, time;
        char res;
        cin >> uid >> pid >> time >> res;
        cin.ignore();

        if (acTime[uid].count(pid))
            continue;
        if (res == 'C')
            acTime[uid][pid] = time;
        if (res == 'I')
            subs[uid][pid]++;
    }

    vector<Result> results;
    for (auto &[uid, acs] : acTime) {
        results.push_back({ uid, (int)acs.size(), 0 });
        for (auto &[pid, time] : acs)
            results.back().time += time + 20 * subs[uid][pid];
    }
    sort(results.begin(), results.end());

    if (test)
        cout << "\n";
    for (auto &[uid, ac, time] : results)
        cout << uid << " " << ac << " " << time << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}