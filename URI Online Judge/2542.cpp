#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int attrCount;
    if (!(cin >> attrCount))
        return 0;

    int aCardCount, bCardCount;
    cin >> aCardCount >> bCardCount;

    vector<vector<int>> aCards(aCardCount, vector<int>(attrCount));
    for (vector<int> &card : aCards)
        for (int &attr : card)
            cin >> attr;

    vector<vector<int>> bCards(bCardCount, vector<int>(attrCount));
    for (vector<int> &card : bCards)
        for (int &attr : card)
            cin >> attr;

    int aCardIndex, bCardIndex, attrIndex;
    cin >> aCardIndex >> bCardIndex >> attrIndex;
    aCardIndex--;
    bCardIndex--;
    attrIndex--;

    if (aCards[aCardIndex][attrIndex] > bCards[bCardIndex][attrIndex])
        cout << "Marcos\n";
    else if (aCards[aCardIndex][attrIndex] < bCards[bCardIndex][attrIndex])
        cout << "Leonardo\n";
    else
        cout << "Empate\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}