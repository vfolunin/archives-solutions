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

    int clauseCount;
    cin >> clauseCount;

    cout << (clauseCount < 8 ? "unsatisfactory" : "satisfactory");
}