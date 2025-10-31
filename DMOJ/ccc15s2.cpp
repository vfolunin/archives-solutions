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

    int jerseyCount, athleteCount;
    cin >> jerseyCount >> athleteCount;

    string jerseys(jerseyCount, ' ');
    for (char &jerseySize : jerseys)
        cin >> jerseySize;

    string sizeOrder = " SML";
    int res = 0;
    for (int i = 0; i < athleteCount; i++) {
        char jerseySize;
        int number;
        cin >> jerseySize >> number;
        number--;

        if (sizeOrder.find(jerseySize) <= sizeOrder.find(jerseys[number])) {
            jerseys[number] = ' ';
            res++;
        }
    }

    cout << res;
}