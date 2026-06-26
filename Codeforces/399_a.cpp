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

    int pageCount, curPage, limit;
    cin >> pageCount >> curPage >> limit;

    int l = max(curPage - limit, 1);
    int r = min(curPage + limit, pageCount);

    if (1 < l)
        cout << "<< ";
    for (int i = l; i <= r; i++) {
        if (i == curPage)
            cout << "(" << i << ") ";
        else
            cout << i << " ";
    }
    if (r < pageCount)
        cout << ">>";
}