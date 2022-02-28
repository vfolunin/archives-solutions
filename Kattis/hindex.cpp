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

    int paperCount;
    cin >> paperCount;

    vector<int> citations(paperCount);
    for (int &c : citations)
        cin >> c;

    sort(citations.rbegin(), citations.rend());

    int hIndex = 0;
    for (int i = 0; i < paperCount; i++)
        if (citations[i] >= i + 1)
            hIndex = i + 1;

    cout << hIndex;
}