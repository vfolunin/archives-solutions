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

    int h, w;
    cin >> h >> w;

    vector<int> count(10);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int product = i * j;
            while (product) {
                count[product % 10]++;
                product /= 10;
            }
        }
    }

    for (int count : count)
        cout << count << "\n";
}