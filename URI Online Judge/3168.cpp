#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int giftCount, defectCount;
    double defectProbability;
    cin >> giftCount >> defectCount >> defectProbability;
    defectProbability /= 100;

    vector<vector<double>> probability(giftCount + 1, vector<double>(giftCount + 1));
    probability[0][0] = 1;
    for (int gifts = 1; gifts <= giftCount; gifts++) {
        probability[gifts][0] = probability[gifts - 1][0] * (1 - defectProbability);
        for (int defects = 1; defects <= defectCount; defects++)
            probability[gifts][defects] = probability[gifts - 1][defects - 1] * defectProbability +
            probability[gifts - 1][defects] * (1 - defectProbability);
    }

    cout.precision(2);
    cout << "A chance de Basy acertar o numero no dia " << test << " eh ";
    cout << fixed << probability[giftCount][defectCount] * 100 << "%\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}