#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int peopleCount, slotCount;
    if (!(cin >> peopleCount >> slotCount))
        return 0;

    vector<int> id;
    for (int i = 0; i < peopleCount; i++)
        id.push_back(i + 1);

    vector<int> card(20);
    for (int &c : card)
        cin >> c;

    for (int i = 0; i < 20 && id.size() > slotCount; i++) {
        int pos = 0;
        while (1) {
            pos += card[i] - 1;
            if (pos >= id.size())
                break;
            id.erase(id.begin() + pos);
            if (id.size() == slotCount)
                break;
        }
    }

    cout << "Selection #" << test << "\n";
    for (int i = 0; i < id.size(); i++)
        cout << id[i] << (i + 1 < id.size() ? " " : "\n\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}