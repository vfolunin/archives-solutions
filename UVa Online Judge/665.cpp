#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Check {
    set<int> a, b;
    char res;
};

void solve(int test) {
    int coinCount, checkCount;
    cin >> coinCount >> checkCount;

    vector<Check> checks(checkCount);
    for (auto &[a, b, res] : checks) {
        int size;
        cin >> size;

        for (int i = 0; i < size; i++) {
            int coin;
            cin >> coin;
            a.insert(coin);
        }

        for (int i = 0; i < size; i++) {
            int coin;
            cin >> coin;
            b.insert(coin);
        }

        cin >> res;
    }

    if (test)
        cout << "\n";

    int falseCoin = 0;
    for (int coin = 1; coin <= coinCount; coin++) {
        for (int less = 0; less <= 1; less++) {
            bool ok = 1;
            for (auto &[a, b, res] : checks) {
                if (a.count(coin))
                    ok &= (less && res == '<' || !less && res == '>');
                else if (b.count(coin))
                    ok &= (less && res == '>' || !less && res == '<');
                else
                    ok &= res == '=';
                if (!ok)
                    break;
            }

            if (ok) {
                if (falseCoin && falseCoin != coin) {
                    cout << "0\n";
                    return;
                }
                falseCoin = coin;
            }
        }
    }

    cout << falseCoin << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}