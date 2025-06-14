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
 
    int size;
    cin >> size;

    vector<int> res(size);
    for (int step = 2; 1; step *= 2) {
        int i = find(res.begin(), res.end(), 0) - res.begin();
        if (i == res.size())
            break;
        for (; i < res.size(); i += step)
            res[i] = size--;
    }

    for (int value : res)
        cout << value << " ";
}