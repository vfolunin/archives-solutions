#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int size, int limit) {
    static vector<vector<int>> memo(2001, vector<int>(2001, -1));
    int &res = memo[size][limit];
    if (res != -1)
        return res;

    if (!size)
        return res = 2;

    for (int take = 1; take <= limit; take++)
        if (rec(size - take, min(size - take, take * 2)) == 2)
            return res = 1;

    return res = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int size = 2; size <= 2000; size++)
        if (rec(size, size - 1) == 2)
            cout << size << "\n";
}