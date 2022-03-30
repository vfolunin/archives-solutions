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

    int length, dist, birdCount;
    cin >> length >> dist >> birdCount;

    vector<int> birdPos(birdCount);
    for (int &pos : birdPos)
        cin >> pos;
    birdPos.push_back(6 - dist);
    birdPos.push_back(length - 6 + dist);

    sort(birdPos.begin(), birdPos.end());

    int res = 0;
    for (int i = 1; i < birdPos.size(); i++)
        res += (birdPos[i] - birdPos[i - 1] - dist) / dist;

    cout << res;
}