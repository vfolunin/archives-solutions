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

    int categoryCount;
    cin >> categoryCount;

    map<string, set<string>> categoriesOf;
    map<string, int> categoryScore;

    for (int i = 0; i < categoryCount; i++) {
        string category;
        int keywordCount;
        cin >> category >> keywordCount;

        for (int j = 0; j < keywordCount; j++) {
            string keyword;
            cin >> keyword;
            categoriesOf[keyword].insert(category);
        }

        categoryScore[category];
    }

    int maxScore = 0;

    for (string word; cin >> word; ) {
        for (const string &category : categoriesOf[word]) {
            categoryScore[category]++;
            maxScore = max(maxScore, categoryScore[category]);
        }
    }

    for (auto &[category, score] : categoryScore)
        if (score == maxScore)
            cout << category << "\n";
}