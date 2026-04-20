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

    long long solutionCount, solutionSize, driveSize;
    cin >> solutionCount >> solutionSize >> driveSize;

    long long solutionsPerDrive = driveSize / solutionSize;

    cout << (solutionCount + solutionsPerDrive - 1) / solutionsPerDrive;
}