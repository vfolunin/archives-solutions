#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(int size, vector<int> &a) {
    a.insert(a.begin(), 0);

    a[1] = -abs(a[1]);
    for (int i = 2; i < a.size(); i++) {
        if (a[i - 1] <= -abs(a[i]))
            a[i] = -abs(a[i]);
        else if (a[i - 1] <= abs(a[i]))
            a[i] = abs(a[i]);
        else
            return a;
    }

    a[0] = 1;
    return a;
}
