#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int count, int limit) {
    static vector<vector<int>> memo(201, vector<int>(401));
    int &res = memo[count][limit];
    if (res)
        return res;

    if (!count)
        return res = 1;

    for (int take = 1; take <= count && take <= limit; take++)
        if (rec(count - take, take + 1) == 2)
            return res = 1;

    return res = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count, limit;
    cin >> count >> limit;

    bool found = 0;
    for (int take = 1; take <= limit; take++) {
        if (rec(count - take, take + 1) == 2) {
            cout << take << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}