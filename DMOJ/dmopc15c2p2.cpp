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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    int aScore = 0, bScore = 0;
    for (int i = 0; i < a.size(); i++) {
        aScore += a[i] > b[i];
        bScore += a[i] < b[i];
    }

    cout << aScore << " " << bScore << "\n";
    if (aScore > bScore)
        cout << "Xyene";
    else if (aScore < bScore)
        cout << "FatalEagle";
    else
        cout << "Tie";
}