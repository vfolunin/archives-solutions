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

    vector<int> bookPrice(bookCount);
    for (int &price : bookPrice)
        cin >> price;
    sort(bookPrice.begin(), bookPrice.end());

    int targetSum;
    cin >> targetSum;

    int a, b;
    for (int l = 0, r = bookCount - 1; l < r; l++) {
        while (l < r && bookPrice[l] + bookPrice[r] > targetSum)
            r--;
        if (l < r && bookPrice[l] + bookPrice[r] == targetSum) {
            a = bookPrice[l];
            b = bookPrice[r];
        }
    }

    cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}