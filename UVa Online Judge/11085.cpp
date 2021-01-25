#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> solutions;
void rec(int col, vector<int> &usedR, vector<int> &usedD1, vector<int> &usedD2, vector<int> &solution) {
    if (col == 8) {
        solutions.push_back(solution);
        return;
    }
    for (int row = 0; row < 8; row++) {
        if (usedR[row] || usedD1[col + row] || usedD2[col - row + 8])
            continue;
        usedR[row] = usedD1[col + row] = usedD2[col - row + 8] = 1;
        solution[col] = row;
        rec(col + 1, usedR, usedD1, usedD2, solution);
        usedR[row] = usedD1[col + row] = usedD2[col - row + 8] = 0;
    }
}

void prepare() {
    vector<int> usedR(8), usedD1(20), usedD2(20), solution(8);
    rec(0, usedR, usedD1, usedD2, solution);
}

int diff(vector<int> &solution, vector<int> &position) {
    int res = 0;
    for (int i = 0; i < 8; i++)
        res += solution[i] != position[i];
    return res;
}

bool solve(int test) {
    vector<int> position(8);
    for (int &row : position) {
        if (!(cin >> row))
            return 0;
        row--;
    }
    
    int res = 8;
    for (vector<int> &solution : solutions)
        res = min(res, diff(solution, position));

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    prepare();

    for (int test = 1; solve(test); test++);
}