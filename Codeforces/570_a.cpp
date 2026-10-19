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

    int width, height;
    cin >> width >> height;

    vector<int> resCount(width);
    for (int y = 0; y < height; y++) {
        vector<int> count(width);
        for (int &count : count)
            cin >> count;

        resCount[max_element(count.begin(), count.end()) - count.begin()]++;
    }

    cout << max_element(resCount.begin(), resCount.end()) - resCount.begin() + 1;
}