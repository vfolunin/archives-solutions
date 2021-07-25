#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long moves(vector<int> &config, int i, int peg) {
    if (i == -1)
        return 0;
    if (config[i] == peg)
        return moves(config, i - 1, peg);
    int aux = 6 - peg - config[i];
    return moves(config, i - 1, aux) + (1LL << i);
}

bool solve(int test) {
    int pegCount;
    cin >> pegCount;
    
    if (!pegCount)
        return 0;

    vector<int> configA(pegCount);
    for (int &peg : configA)
        cin >> peg;

    vector<int> configB(pegCount);
    for (int &peg : configB)
        cin >> peg;

    while (!configA.empty() && configA.back() == configB.back()) {
        configA.pop_back();
        configB.pop_back();
    }

    cout << "Case " << test << ": ";
    if (configA.empty()) {
        cout << "0\n";
    } else {
        int aux = 6 - configA.back() - configB.back();
        long long movesA = moves(configA, (int)configA.size() - 2, aux);
        long long movesB = moves(configB, (int)configB.size() - 2, aux);
        cout << movesA + 1 + movesB << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}