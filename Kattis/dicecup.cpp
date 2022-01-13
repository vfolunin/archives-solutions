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

    int aFaces, bFaces;
    cin >> aFaces >> bFaces;

    vector<int> count(41);
    for (int a = 1; a <= aFaces; a++)
        for (int b = 1; b <= bFaces; b++)
            count[a + b]++;

    int maxCount = *max_element(count.begin(), count.end());
    for (int sum = 0; sum < count.size(); sum++)
        if (count[sum] == maxCount)
            cout << sum << "\n";
}