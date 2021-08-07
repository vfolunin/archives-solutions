#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<int> a, used;
    int sum, len;

    Solver() {
        int size;
        cin >> size;

        a.resize(size);
        used.resize(size);
        sum = 0;

        for (int &x : a) {
            cin >> x;
            sum += x;
        }

        sort(a.rbegin(), a.rend());
    }

    bool can(int i, int curLen, int curSum) {
        if (curLen == len) {
            if (curSum + len == sum)
                return 1;

            int i = 0;
            while (used[i])
                i++;

            used[i] = 1;
            if (can(i + 1, a[i], curSum + len))
                return 1;
            used[i] = 0;
            return 0;
        }

        for (int j = i; j < a.size(); j++) {
            if (used[j] || curLen + a[j] > len || j && a[j - 1] == a[j] && !used[j - 1])
                continue;

            used[j] = 1;
            if (can(j + 1, curLen + a[j], curSum))
                return 1;
            used[j] = 0;

            if (curLen + a[j] == len)
                break;
        }
        return 0;
    }

    int getLen() {
        len = a[0];
        while (sum % len || !can(0, 0, 0))
            len++;
        return len;
    }
};

bool solve() {
    Solver solver;

    if (solver.a.empty())
        return 0;

    cout << solver.getLen() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}