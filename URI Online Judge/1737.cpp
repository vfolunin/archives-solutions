#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

bool solve() {
    int lineCount;
    cin >> lineCount;
    cin.ignore();

    if (!lineCount)
        return 0;

    string text;
    for (int i = 0; i < lineCount; i++) {
        string line;
        getline(cin, line);
        text += line;
    }

    map<string, int> digramMap;
    int digramCount = 0;
    for (int i = 0; i + 1 < text.size(); i++) {
        digramMap[{ text[i], text[i + 1] }]++;
        digramCount++;
    }

    vector<pair<string, int>> digramVector(digramMap.begin(), digramMap.end());
    partial_sort(digramVector.begin(), digramVector.begin() + 5, digramVector.end(), compare);

    for (int i = 0; i < 5; i++) {
        cout << digramVector[i].first << " ";
        cout << digramVector[i].second << " ";
        cout << fixed << (double)digramVector[i].second / digramCount << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}