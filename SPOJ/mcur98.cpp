#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int getNext(int n) {
    int res = n;
    for (; n; n /= 10)
        res += n % 10;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_set<int> nexts;
    for (int i = 0; i < 1e6; i++)
        nexts.insert(getNext(i));

    for (int i = 0; i < 1e6; i++)
        if (!nexts.count(i))
            cout << i << "\n";
}