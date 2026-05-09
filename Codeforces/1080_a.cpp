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

    int friendCount, pageCount;
    cin >> friendCount >> pageCount;

    int res = 0;
    for (int pagePerFriend : { 2, 5, 8 })
        res += (friendCount * pagePerFriend + pageCount - 1) / pageCount;

    cout << res;
}