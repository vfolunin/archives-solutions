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

    int wordCount, descriptionCount;
    cin >> wordCount >> descriptionCount;

    map<string, int> wordPrice;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word >> wordPrice[word];
    }

    for (int i = 0; i < descriptionCount; i++) {
        int descriptionPrice = 0;

        while (1) {
            string word;
            cin >> word;

            if (word == ".")
                break;

            if (wordPrice.count(word))
                descriptionPrice += wordPrice[word];
        }

        cout << descriptionPrice << "\n";
    }
}