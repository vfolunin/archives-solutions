#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> count(20);
    count[0] = 1;

    for (int i = 1; i < size; i++) {
        count.insert(count.begin(), 0);
        if (count.size() > 20)
            count.pop_back();
        count[0] = accumulate(count.begin() + 3, count.end(), 0LL);
    }

    cout << accumulate(count.begin() + 1, count.end(), 0LL);
}