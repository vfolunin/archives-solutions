#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, int> category;
    for (int i = 0; i < size; i++) {
        int itemId, categoryId;
        cin >> itemId >> categoryId;
        
        category[itemId] = categoryId;
    }

    unordered_map<int, int> last;
    int res = size;
    for (int i = 0; i < size; i++) {
        int itemId;
        cin >> itemId;

        int categoryId = category[itemId];
        if (last.count(categoryId))
            res = min(res, i - last[categoryId]);
        last[categoryId] = i;
    }

    cout << res;
}