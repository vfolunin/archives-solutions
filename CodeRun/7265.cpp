#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(int size, int swapCount, vector<int> &swaps) {
    unordered_set<int> pos;
    for (int i = 1; i <= size; i++)
        pos.insert(i);

    vector<int> res;
    int cur = size;

    for (int i = 0; i < swaps.size(); i += 2) {
        int p1 = swaps[i], p2 = swaps[i + 1];
        if (!pos.count(p1) && pos.count(p2))
            swap(p1, p2);

        if (pos.count(p1) && !pos.count(p2)) {
            cur -= p1 <= size;
            pos.erase(p1);
            cur += p2 <= size;
            pos.insert(p2);
        }
        
        res.push_back(cur);
    }

    return res;
}
