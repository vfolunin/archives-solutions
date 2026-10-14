#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

vector<int> getLuckyNumbers() {
    vector<int> luckyNumbers(5e4);
    iota(luckyNumbers.begin(), luckyNumbers.end(), 2);

    for (int i = 0; i < luckyNumbers.size(); i++) {
        for (int j = i + luckyNumbers[i]; j < luckyNumbers.size(); j += luckyNumbers[i])
            luckyNumbers[j] = 0;
        luckyNumbers.erase(remove(luckyNumbers.begin(), luckyNumbers.end(), 0), luckyNumbers.end());
    }

    return luckyNumbers;
}

bool solve() {
    int index;
    cin >> index;

    if (!index)
        return 0;

    static vector<int> luckyNumbers = getLuckyNumbers();

    cout << luckyNumbers[index - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}