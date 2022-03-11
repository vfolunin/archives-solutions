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

    int voterCount, districtCount;
    cin >> voterCount >> districtCount;

    vector<pair<int, int>> votes(districtCount);
    for (int i = 0; i < voterCount; i++) {
        int district, a, b;
        cin >> district >> a >> b;
        district--;
        votes[district].first += a;
        votes[district].second += b;
    }

    int total = 0, totalA = 0, totalB = 0;
    for (auto &[a, b] : votes) {
        char winner;
        int wastedA, wastedB;
        
        if (a > b) {
            winner = 'A';
            wastedA = a - ((a + b) / 2 + 1);
            wastedB = b;
        } else {
            winner = 'B';
            wastedA = a;
            wastedB = b - ((a + b) / 2 + 1);
        }

        total += a + b;
        totalA += wastedA;
        totalB += wastedB;
        cout << winner << " " << wastedA << " " << wastedB << "\n";
    }

    cout << fixed << (double)abs(totalA - totalB) / total;
}