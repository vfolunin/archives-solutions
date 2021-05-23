#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<unsigned long long>> prepare() {
    vector<vector<unsigned long long>> maxStores(64, vector<unsigned long long>(101));
    for (int tries = 1; tries <= 63; tries++) {
        maxStores[tries][1] = tries;
        for (int balls = 2; balls <= 100; balls++) 
            maxStores[tries][balls] = maxStores[tries - 1][balls - 1] + 1 + maxStores[tries - 1][balls];
    }
    return maxStores;
}

bool solve() {
    int balls;
    unsigned long long stores;    
    cin >> balls >> stores;
    
    if (!balls)
        return 0;

    static vector<vector<unsigned long long>> maxStores = prepare();

    int res = 1e9;
    for (int tries = 1; tries <= 63; tries++) {
        if (maxStores[tries][balls] >= stores) {
            res = tries;
            break;
        }
    }

    if (res == 1e9)
        cout << "More than 63 trials needed.\n";
    else
        cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}