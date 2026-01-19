#include <vector>
using namespace std;

vector<int> solve(int width, int stoneCount, vector<int> &a) {
    a.insert(a.begin(), 0);
    a.push_back(width);

    vector<int> minJumps(a.size(), 1e9), next(a.size(), a.size());
    minJumps.back() = 0;

    for (int i = a.size() - 2; i >= 0; i--) {
        for (int jump : { 1, 2 }) {
            int j = i + 1;
            while (j < a.size() && a[i] + jump > a[j])
                j++;
            if (j < a.size() && a[i] + jump == a[j] && minJumps[i] > minJumps[j] + 1) {
                minJumps[i] = minJumps[j] + 1;
                next[i] = j;
            }
        }
    }

    if (minJumps[0] == 1e9)
        return { -1 };

    vector<int> res = { minJumps[0] };
    for (int i = 0; i + 1 < a.size(); i = next[i])
        res.push_back(a[next[i]] - a[i]);
    return res;
}