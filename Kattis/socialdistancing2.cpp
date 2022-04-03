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

    int seatCount, peopleCount;
    cin >> seatCount >> peopleCount;

    vector<int> pos(peopleCount);
    for (int &p : pos)
        cin >> p;

    int res = 0;
    for (int i = 0; i + 1 < pos.size(); i++)
        res += (pos[i + 1] - pos[i] - 2) / 2;
    res += (pos[0] + seatCount - pos.back() - 2) / 2;

    cout << res;
}