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

    int fullPrice, emptyPrice, money;
    cin >> fullPrice >> emptyPrice >> money;

    int res = 0;
    while (money >= fullPrice) {
        money -= fullPrice - emptyPrice;
        res++;
    }

    cout << res;
}