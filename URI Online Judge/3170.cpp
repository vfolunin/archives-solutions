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
    
    int ballCount, branchCount;
    cin >> ballCount >> branchCount;

    if (ballCount >= branchCount / 2)
        cout << "Amelia tem todas bolinhas!\n";
    else
        cout << "Faltam " << branchCount / 2 - ballCount << " bolinha(s)\n";
}