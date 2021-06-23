#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    map<string, int> wordCount;
    int length = 0;
    string word;

    while (1) {
        static string sep = ",.:;!?\"()";
        char c = cin.get();
        if (c != EOF && !isspace(c) && sep.find(c) == -1) {
            word += tolower(c);
        } else if (!word.empty()) {
            if (word == "****end_of_text****" || word == "****end_of_input****")
                break;
            length++;
            wordCount[word]++;
            word = "";
        }
    }

    if (!length)
        return 0;

    double eT = 0;
    for (auto &[_, count] : wordCount)
        eT += count * (log10(length) - log10(count)) / length;

    double eRel = eT / log10(length) * 100;

    cout << length << " ";
    cout.precision(1);
    cout << fixed << eT << " ";
    cout.precision(0);
    cout << fixed << eRel << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}