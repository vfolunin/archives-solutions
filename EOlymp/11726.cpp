#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, int targetOnes, double p, int i, int curOnes, double curP, double &resP) {
    if (i == size) {
        if (curOnes == targetOnes)
            resP += curP;
        return;
    }

    rec(size, targetOnes, p, i + 1, curOnes, curP * (1 - p), resP);
    rec(size, targetOnes, p, i + 1, curOnes + 1, curP * p, resP);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetOnes;
    double p;
    cin >> size >> targetOnes >> p;

    double res = 0;
    rec(size, targetOnes, p, 0, 0, 1, res);

    cout << fixed << res;
}