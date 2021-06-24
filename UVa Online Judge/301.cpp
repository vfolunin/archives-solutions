#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Ticket {
    int l, r, seats;
};

struct Solver {
    int capacity;
    vector<Ticket> tickets;
    vector<int> load;
    int res;

    void rec(int step, int sum) {
        if (step == tickets.size()) {
            res = max(res, sum);
            return;
        }

        rec(step + 1, sum);

        auto &[l, r, seats] = tickets[step];
        bool ok = 1;
        for (int i = l; ok && i < r; i++)
            ok &= load[i] + seats <= capacity;
        if (ok) {
            for (int i = l; i < r; i++)
                load[i] += seats;
            rec(step + 1, sum + (r - l) * seats);
            for (int i = l; i < r; i++)
                load[i] -= seats;
        }
    }

    int getRes() {
        res = 0;
        rec(0, 0);
        return res;
    }
};

bool solve() {
    Solver solver;
    int maxTown, ticketCount;
    cin >> solver.capacity >> maxTown >> ticketCount;

    if (!solver.capacity && !maxTown && !ticketCount)
        return 0;

    solver.load.assign(maxTown, 0);
    solver.tickets.resize(ticketCount);

    for (auto &[l, r, cost] : solver.tickets)
        cin >> l >> r >> cost;

    cout << solver.getRes() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}