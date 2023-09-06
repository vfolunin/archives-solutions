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

    int letterCount;
    cin >> letterCount;

    int coord = 0, res = 0;
    for (int i = 0; i < letterCount; i++) {
        string name;
        cin >> name;

        static string letters = "AOPRBMSDGJKTW";
        static string coords = "0000111222222";
        int nextCoord = coords[letters.find(name[0])] - '0';

        res += abs(coord - nextCoord);
        coord = nextCoord;
    }

    cout << res;
}