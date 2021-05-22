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

    int bookCount, maxCost;
    cin >> bookCount >> maxCost;

    vector<int> price(bookCount);
    for (int &p : price)
        cin >> p;

    vector<int> pages(bookCount);
    for (int &p : pages)
        cin >> p;

    vector<int> maxPages(maxCost + 1);
    for (int bookIndex = 0; bookIndex < bookCount; bookIndex++)
        for (int cost = maxCost; cost >= price[bookIndex]; cost--)
            maxPages[cost] = max(maxPages[cost], maxPages[cost - price[bookIndex]] + pages[bookIndex]);

    cout << *max_element(maxPages.begin(), maxPages.end());
}