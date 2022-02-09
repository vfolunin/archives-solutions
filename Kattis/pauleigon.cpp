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

    int serveCount, aScore, bScore;
    cin >> serveCount >> aScore >> bScore;

    int serveRowCount = (aScore + bScore) / serveCount;

    cout << (serveRowCount % 2 ? "opponent" : "paul");
}