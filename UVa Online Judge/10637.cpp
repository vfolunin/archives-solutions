#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct Solver {
    vector<bitset<101>> coprime;
    vector<int> partition;

    void rec(int step, int count, int curSum, int targetSum, bitset<101> curCoprime) {
        if (step == count - 1) {
            if ((!step || partition[step - 1] <= targetSum - curSum) && curCoprime[targetSum - curSum]) {
                partition[step] = targetSum - curSum;
                for (int i = 0; i < count; i++)
                    cout << partition[i] << (i + 1 < count ? " " : "\n");
            }
            return;
        }

        partition[step] = (step ? partition[step - 1] : 1);
        while (partition[step] * (count - step) <= targetSum - curSum) {
            if (curCoprime[partition[step]])
                rec(step + 1, count, curSum + partition[step], targetSum, curCoprime & coprime[partition[step]]);
            partition[step]++;
        }
    }

    Solver() {
        coprime.assign(101, bitset<101>());
        for (int a = 1; a <= 100; a++)
            for (int b = 1; b <= 100; b++)
                coprime[a][b] = gcd(a, b) == 1;
        partition.resize(101);
    }
};

bool solve(int test, Solver &solver) {
    int targetSum, count;
    cin >> targetSum >> count;

    bitset<101> curCoprime;
    for (int i = 0; i <= 100; i++)
        curCoprime[i] = 1;

    cout << "Case " << test << ":\n";
    solver.rec(0, count, 0, targetSum, curCoprime);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    Solver solver;

    for (int test = 1; test <= n; test++)
        solve(test, solver);
}