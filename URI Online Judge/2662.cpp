#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<set<int>> prepare() {
    vector<set<int>> scales(12);
    for (int i = 0; i < scales.size(); i++)
        for (int d : {1, 3, 5, 6, 8, 10, 12})
            scales[i].insert((i + d) % 12);
    return scales;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int noteCount;
    cin >> noteCount;

    vector<set<int>> scales = prepare();
    vector<int> can(scales.size(), 1);

    for (int i = 0; i < noteCount; i++) {
        int note;
        cin >> note;
        for (int j = 0; j < scales.size(); j++)
            can[j] &= scales[j].count(note % 12);
    }

    vector<string> answer = {
        "do", "do#", "re", "re#", "mi", "fa", "fa#",
        "sol", "sol#", "la", "la#", "si", "desafinado"
    };
    cout << answer[find(can.begin(), can.end(), 1) - can.begin()] << "\n";
}