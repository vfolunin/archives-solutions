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

    int initialCost, extraCost, failCost, depth, verdict;
    cin >> initialCost >> extraCost >> failCost >> depth >> verdict;

    cout << (verdict ? initialCost + max(0, depth - 12) * extraCost : depth * failCost);
}