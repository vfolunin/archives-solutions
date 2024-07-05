#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Job {
    int time, fine, index;

    bool operator < (const Job &that) const {
        if (time * that.fine != that.time * fine)
            return time * that.fine < that.time * fine;
        return index < that.index;
    }
};

bool solve() {
    int jobCount;
    if (!(cin >> jobCount))
        return 0;

    vector<Job> jobs(jobCount);
    for (int i = 0; i < jobCount; i++) {
        cin >> jobs[i].time >> jobs[i].fine;
        jobs[i].index = i;
    }

    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < jobCount; i++)
        cout << jobs[i].index + 1 << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}