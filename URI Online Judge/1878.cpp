#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(int i, vector<int> &coeff, int studentCount, int scoreA, int scoreB) {
    if (i == coeff.size())
        return scoreA == scoreB;

    for (int placeA = 1; placeA <= studentCount; placeA++)
        for (int placeB = 1; placeB <= studentCount; placeB++)
            if (placeA != placeB && rec(i + 1, coeff, studentCount,
                scoreA + placeA * coeff[i], scoreB + placeB * coeff[i]))
                return 1;

    return 0;
}

bool solve() {
    int contestCount, studentCount;
    if (!(cin >> contestCount >> studentCount))
        return 0;

    vector<int> coeff(contestCount);
    for (int &c : coeff)
        cin >> c;

    if (rec(0, coeff, studentCount, 0, 0))
        cout << "Try again later, Denis...\n";
    else
        cout << "Lucky Denis!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}