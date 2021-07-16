#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(int aut, int i, string &prevState, string &state) {
    if (i == state.size()) {
        int bit = ((prevState[state.size() - 2] & 1) << 2) | ((prevState[state.size() - 1] & 1) << 1) | (prevState[0] & 1);
        if (((state[state.size() - 1] & 1) != ((aut >> bit) & 1)))
            return 0;

        bit = ((prevState[state.size() - 1] & 1) << 2) | ((prevState[0] & 1) << 1) | (prevState[1] & 1);
        if (((state[0] & 1) != ((aut >> bit) & 1)))
            return 0;

        return 1;
    }

    if (i < 2) {
        prevState[i] = '0';
        if (rec(aut, i + 1, prevState, state))
            return 1;

        prevState[i] = '1';
        if (rec(aut, i + 1, prevState, state))
            return 1;

        return 0;
    }

    prevState[i] = '0';
    int bit = ((prevState[i - 2] & 1) << 2) | ((prevState[i - 1] & 1) << 1) | (prevState[i] & 1);
    if (((state[i - 1] & 1) == ((aut >> bit) & 1)) && rec(aut, i + 1, prevState, state))
        return 1;

    prevState[i] = '1';
    bit = ((prevState[i - 2] & 1) << 2) | ((prevState[i - 1] & 1) << 1) | (prevState[i] & 1);
    if (((state[i - 1] & 1) == ((aut >> bit) & 1)) && rec(aut, i + 1, prevState, state))
        return 1;

    return 0;
}

bool solve() {
    int aut, cellCount;
    string state;
    if (!(cin >> aut >> cellCount >> state))
        return 0;

    string prevState(cellCount, '0');
    if (rec(aut, 0, prevState, state))
        cout << "REACHABLE\n";
    else
        cout << "GARDEN OF EDEN\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}