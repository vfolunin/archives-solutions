#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<vector<long long>> ways(30001, vector<long long>(11));
    ways[0][0] = 1;

    static vector<int> nominals = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
    
    for (int sum = 0; sum < ways.size(); sum++)
        for (int i = 0; i < nominals.size(); i++)
            for (int j = i; j < nominals.size(); j++)
                if (sum + nominals[j] < ways.size())
                    ways[sum + nominals[j]][j] += ways[sum][i];

    vector<long long> totalWays(30001);
    for (int sum = 0; sum < ways.size(); sum++)
        for (int i = 0; i < nominals.size(); i++)
            totalWays[sum] += ways[sum][i];

    return totalWays;
}

bool solve() {
    int dollars, cents;
    cin >> dollars;
    cin.ignore();
    cin >> cents;

    cents += dollars * 100;
    if (!cents)
        return 0;

    static vector<long long> ways = prepare();

    cout << setw(3) << cents / 100 << "." << setw(2) << setfill('0') << cents % 100;
    cout << setw(17) << setfill(' ') << ways[cents] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}