#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    int n;
    vector<int> numbers, takenNumbers;

    bool rec(int from, int step, int sum) {
        if (step == n)
            return sum % n == 0;
        for (int i = from; i < numbers.size(); i++) {
            takenNumbers[step] = numbers[i];
            if (rec(i + 1, step + 1, sum + numbers[i]))
                return 1;
        }
        return 0;
    }
};

bool solve() {
    Solver solver;
    cin >> solver.n;

    if (!solver.n)
        return 0;

    solver.numbers.resize(2 * solver.n - 1);
    for (int &x : solver.numbers)
        cin >> x;

    solver.takenNumbers.resize(solver.n);
    if (!solver.rec(0, 0, 0)) {
        cout << "No\n";
        return 1;
    }

    cout << "Yes\n";
    for (int i = 0; i < solver.n; i++)
        cout << solver.takenNumbers[i] << (i + 1 < solver.n ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}