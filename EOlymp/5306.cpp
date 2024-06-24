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

    int n;
    cin >> n;

    vector<int> res(n + 1, 2);
    for (int i = 1; i < res.size(); i++) {
        vector<int> take;
        if (i % 3 == 0)
            take = { 1, 2 };
        else if (i % 3 == 1)
            take = { 1, 3 };
        else
            take = { 1, 2, 3 };

        for (int take : take)
            if (i >= take && res[i - take] == 2)
                res[i] = 1;
    }

    cout << res[n];
}