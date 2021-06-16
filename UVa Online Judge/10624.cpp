#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    string s;
    vector<vector<int>> mods;

    Solver() : mods(31, vector<int>(1)) {}

    bool rec(int step, int size, int from) {
        if (step == size)
            return 1;

        for (int digit = (step ? 0 : 1); digit < 10; digit++) {
            if (step + 1 >= from && (mods[step + 1].back() * 10 + digit) % (step + 1))
                continue;

            s.push_back(digit + '0');
            for (int mod = 1; mod <= size; mod++)
                mods[mod].push_back((mods[mod].back() * 10 + digit) % mod);
            
            if (rec(step + 1, size, from))
                return 1;

            s.pop_back();
            for (int mod = 1; mod <= size; mod++)
                mods[mod].pop_back();
        }
        return 0;
    }

    string getString(int size, int from) {
        return rec(0, size, from) ? s : "-1";
    }
};

void solve(int test) {
    int from, size;
    cin >> from >> size;

    Solver solver;

    cout << "Case " << test << ": " << solver.getString(size, from) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}