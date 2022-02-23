#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int wordCount;
    cin >> wordCount;

    vector<list<string>> lists(wordCount);
    for (auto &list : lists)
        cin >> list.emplace_back();

    for (int i = 0; i < wordCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        lists[a].splice(lists[a].end(), lists[b]);
    }

    for (auto &list : lists)
        if (!list.empty())
            for (string &word : list)
                cout << word;
}