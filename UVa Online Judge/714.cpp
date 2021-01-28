#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &pages, long long maxPages, int scribeCount) {
    int scribes = 1;
    long long scribePages = 0;

    for (int p : pages) {
        if (scribePages + p <= maxPages) {
            scribePages += p;
        } else {
            scribePages = p;
            scribes++;
        }
    }

    return scribes <= scribeCount;
}

vector<vector<int>> divide(vector<int> &pages, long long maxPages, int scribeCount) {
    vector<vector<int>> parts(scribeCount);
    vector<long long> partPages(scribeCount);
    int partIndex = scribeCount - 1;

    for (int i = pages.size() - 1; i >= 0; i--) {
        if (partIndex > i || partPages[partIndex] + pages[i] > maxPages)
            partIndex--;
        parts[partIndex].push_back(pages[i]);
        partPages[partIndex] += pages[i];
    }

    for (vector<int> &part : parts)
        reverse(part.begin(), part.end());

    return parts;
}

void solve(int test) {
    int bookCount, scribeCount;
    cin >> bookCount >> scribeCount;

    vector<int> pages(bookCount);
    for (int &p : pages)
        cin >> p;
    
    long long l = *max_element(pages.begin(), pages.end()) - 1, r = 1e10;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(pages, m, scribeCount))
            r = m;
        else
            l = m;
    }

    vector<vector<int>> res = divide(pages, r, scribeCount);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << (j + 1 < res[i].size() ? " " : "");
        cout << (i + 1 < res.size() ? " / " : "\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}