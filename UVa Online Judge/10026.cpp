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

void solve(int test) {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].time >> jobs[i].fine;
        jobs[i].index = i;
    }

    sort(jobs.begin(), jobs.end());

    if (test)
        cout << "\n";
    for (int i = 0; i < n; i++)
        cout << jobs[i].index + 1 << (i + 1 < n ? ' ' : '\n');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}