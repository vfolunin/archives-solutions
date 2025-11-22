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

    int roomCount, finish, crateCount;
    cin >> roomCount >> finish >> crateCount;

    vector<int> res(2);
    for (int i = 0; i < crateCount; i++) {
        int pos;
        cin >> pos;

        res[1 <= pos && pos < finish]++;
    }

    cout << min(res[0], res[1]);
}