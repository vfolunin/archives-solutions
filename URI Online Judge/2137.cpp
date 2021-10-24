#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int bookCount;
    if (!(cin >> bookCount))
        return 0;

    vector<string> books(bookCount);
    for (string &book : books)
        cin >> book;
    sort(books.begin(), books.end());

    for (string &book : books)
        cout << book << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}