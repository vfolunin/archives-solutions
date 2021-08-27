#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int pageCount, sheetLimit;
    if (!(cin >> pageCount))
        return 0;
    cin.ignore();
    cin >> sheetLimit;

    int pagesPerSignature = 4 * sheetLimit;
    pageCount = (pageCount + pagesPerSignature - 1) / pagesPerSignature * pagesPerSignature;

    if (test)
        cout << "\n";

    for (int signature = 1; signature * pagesPerSignature <= pageCount; signature++) {
        cout << "signature " << signature << "\n";
        int l = (signature - 1) * pagesPerSignature + 1;
        int r = signature * pagesPerSignature;
        for (int sheet = 1; sheet <= sheetLimit; sheet++) {
            cout << " sheet " << sheet << ": ";
            cout << "pages " << l + 1 << " and " << r - 1 << " (front); ";
            cout << "pages " << r << " and " << l << " (back)\n";
            l += 2;
            r -= 2;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}