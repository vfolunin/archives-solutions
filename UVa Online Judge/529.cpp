#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<int> chain;

    bool rec(int target, int depth, int limit) {
        if (depth > limit)
            return 0;

        if (chain.back() > target)
            return 0;

        int max = chain.back();
        for (int i = depth; i <= limit; i++)
            max *= 2;
        if (max < target)
            return 0;

        if (chain.back() == target)
            return 1;

        for (int i = chain.size() - 1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                if (chain[i] + chain[j] < chain.back())
                    continue;
                chain.push_back(chain[i] + chain[j]);
                if (rec(target, depth + 1, limit))
                    return 1;
                chain.pop_back();
            }
        }

        return 0;
    }

    vector<int> solve(int target) {
        chain = { 1 };
        for (int limit = 1; !rec(target, 0, limit); limit++);
        return chain;
    }
};

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static Solver solver;
    vector<int> chain = solver.solve(n);

    for (int i = 0; i < chain.size(); i++)
        cout << chain[i] << (i + 1 < chain.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}