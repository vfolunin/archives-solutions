#include <vector>
using namespace std;

vector<int> solution(int size, int threshold, vector<int> &a) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == -1)
            a[i] = (i ? a[i - 1] : 0) + threshold;

    for (int i = 0; i < a.size(); i++)
        if (a[i] - (i ? a[i - 1] : 0) < threshold)
            return { -1 };

    vector<int> res;
    for (int i = 0; i < a.size(); i++)
        res.push_back(a[i] - (i ? a[i - 1] : 0));
    return res;
}