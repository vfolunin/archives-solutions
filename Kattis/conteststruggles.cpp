#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int totalCount, solvedCount;
    cin >> totalCount >> solvedCount;

    double totalAvg, solvedAvg;
    cin >> totalAvg >> solvedAvg;

    double totalSum = totalAvg * totalCount;
    double solvedSum = solvedAvg * solvedCount;
    double unsolvedSum = totalSum - solvedSum;
    int unsolvedCount = totalCount - solvedCount;
    double unsolvedAvg = unsolvedSum / unsolvedCount;

    if (0 <= unsolvedAvg && unsolvedAvg <= 100)
        cout << fixed << unsolvedAvg;
    else
        cout << "impossible";
}