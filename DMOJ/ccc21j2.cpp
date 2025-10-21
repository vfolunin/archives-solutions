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

    string resName;
    int resBet = 0;

    for (int i = 0; i < size; i++) {
        string name;
        int bet;
        cin >> name >> bet;

        if (resBet < bet) {
            resName = name;
            resBet = bet;
        }
    }

    cout << resName;
}