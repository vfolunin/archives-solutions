#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int numberCount, queryCount;
    cin >> numberCount >> queryCount;

    if (!numberCount && !queryCount)
        return 0;

    vector<int> a(numberCount);
    for (int &x : a)
        cin >> x;

    cout << "SET " << test << ":\n";

    for (int query = 1; query <= queryCount; query++) {
        int mod, chosen;
        cin >> mod >> chosen;

        vector<int> b = a;
        for (int &x : b)
            x = (x % mod + mod) % mod;

        vector<vector<vector<long long>>> ways(chosen + 1, vector<vector<long long>>(mod, vector<long long>(numberCount)));
        for (int i = 0; i < numberCount; i++)
            ways[1][b[i] % mod][i] = 1;

        for (int prevChosen = 0; prevChosen < chosen; prevChosen++)
            for (int prevMod = 0; prevMod < mod; prevMod++)
                for (int prevLast = 0; prevLast < numberCount; prevLast++)
                    for (int last = prevLast + 1; last < numberCount; last++)
                        ways[prevChosen + 1][(prevMod + b[last]) % mod][last] += ways[prevChosen][prevMod][prevLast];

        long long res = 0;
        for (int last = 0; last < numberCount; last++)
            res += ways[chosen][0][last];

        cout << "QUERY " << query << ": " << res << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}