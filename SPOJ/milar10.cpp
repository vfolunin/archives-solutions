#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool canJump(int from, int to, vector<int> &pos, int minJump) {
    if (!minJump)
        return pos[0] * 2 - from == to;

    if ((to - from) % minJump == 0)
        return 1;

    for (int p : pos)
        if ((p * 2 - from - to) % minJump == 0)
            return 1;

    return 0;
}

bool solve() {
    int posCount, queryCount;
    cin >> posCount >> queryCount;

    if (!posCount && !queryCount)
        return 0;

    vector<int> pos(posCount);
    for (int &p : pos)
        cin >> p;
    sort(pos.begin(), pos.end());

    int minJump = 0;
    for (int i = 0; i + 1 < pos.size(); i++)
        minJump = gcd(minJump, (pos[i + 1] - pos[i]) * 2);

    for (int i = 0; i < queryCount; i++) {
        int from, to;
        cin >> from >> to;

        cout << (canJump(from, to, pos, minJump) ? "Y" : "N") << (i + 1 < queryCount ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}