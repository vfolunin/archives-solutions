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

    int limit, weight, itemCount;
    cin >> limit >> weight >> itemCount;

    limit = (limit - weight) / 10 * 9;
    for (int i = 0; i < itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;
        limit -= itemWeight;
    }

    cout << limit;
}