#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void processSite(unordered_map<string, int> &count) {
    string site, line;
    cin >> site;
    cin.ignore();
    getline(cin, line);

    string word;
    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else if (!word.empty()) {
            count[site] += word == "goose";
            word.clear();
        }
    }
    if (!word.empty())
        count[site] += word == "goose";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int siteCount, threshold;
    cin >> siteCount >> threshold;

    unordered_map<string, int> count;
    for (int i = 0; i < siteCount; i++)
        processSite(count);

    vector<string> sites;
    for (auto &[site, count] : count)
        if (count >= threshold)
            sites.push_back(site);
    sort(sites.begin(), sites.end());

    cout << sites.size() << "\n";
    for (string &site : sites)
        cout << site << "\n";
}