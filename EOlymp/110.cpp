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

    int n;
    cin >> n;

    vector<int> winMove(n + 1);
    for (int count = 3; count < winMove.size(); count++) {
        for (int take = 1; take < count - take; take++) {
            if (!winMove[count - take]) {
                winMove[count] = take;
                break;
            }
        }
    }

    cout << winMove[n];
}