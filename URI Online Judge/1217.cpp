#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dayCount;
    cin >> dayCount;

    double totalMoney = 0, totalMass = 0;
    for (int day = 1; day <= dayCount; day++) {
        double money;
        cin >> money;
        totalMoney += money;

        cin.ignore();
        int mass = readWords().size();
        totalMass += mass;

        cout << "day " << day << ": " << mass << " kg\n";
    }

    totalMoney /= dayCount;
    totalMass /= dayCount;

    cout.precision(2);
    cout << fixed << totalMass << " kg by day\n";
    cout << "R$ " << fixed << totalMoney << " by day\n";
}