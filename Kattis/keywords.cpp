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

    int keywordCount;
    cin >> keywordCount;
    cin.ignore();

    set<string> keywords;

    for (int i = 0; i < keywordCount; i++) {
        string keyword;
        getline(cin, keyword);

        for (char &c : keyword) {
            c = tolower(c);
            if (c == '-')
                c = ' ';
        }
        keywords.insert(keyword);
    }

    cout << keywords.size();
}