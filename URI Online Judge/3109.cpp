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

    int deskCount, queryCount;
    cin >> deskCount >> queryCount;

    vector<int> ownerOfDesk(deskCount);
    for (int i = 0; i < deskCount; i++)
        ownerOfDesk[i] = i;

    for (int i = 0; i < queryCount; i++) {
        int type, idA;
        cin >> type >> idA;
        idA--;

        if (type == 1) {
            int idB;
            cin >> idB;
            idB--;
            swap(ownerOfDesk[idA], ownerOfDesk[idB]);
        } else {
            int redirectCount = 0;
            for (int id = ownerOfDesk[idA]; id != idA; id = ownerOfDesk[id])
                redirectCount++;
            cout << redirectCount << "\n";
        }
    }
}