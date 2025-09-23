#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pageCount, targetIndex;
    if (!(cin >> pageCount >> targetIndex))
        return 0;

    vector<vector<int>> pages(pageCount / 4);
    int index = 1;
    for (int i = 0; i < pages.size(); i++) {
        pages[i].push_back(index++);
        pages[i].push_back(index++);
    }
    for (int i = pages.size() - 1; i >= 0; i--) {
        pages[i].push_back(index++);
        pages[i].push_back(index++);
    }

    for (vector<int> &page : pages) {
        if (find(page.begin(), page.end(), targetIndex) != page.end()) {
            for (int index : page)
                if (index != targetIndex)
                    cout << index << " ";
            cout << "\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}