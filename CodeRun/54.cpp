#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int studentCount;
    cin >> studentCount;

    unordered_map<string, int> count;
    int commonLanguageCount = 0;

    for (int i = 0; i < studentCount; i++) {
        int languageCount;
        cin >> languageCount;

        for (int j = 0; j < languageCount; j++) {
            string language;
            cin >> language;
            count[language]++;
            commonLanguageCount += count[language] == studentCount;
        }
    }

    cout << commonLanguageCount << "\n";
    for (auto &[language, count] : count)
        if (count == studentCount)
            cout << language << "\n";

    cout << count.size() << "\n";
    for (auto &[language, count] : count)
        cout << language << "\n";
}