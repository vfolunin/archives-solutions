#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int cubeCount;
    cin >> cubeCount;

    if (!cubeCount)
        return 0;

    vector<vector<int>> cubes(cubeCount, vector<int>(6));
    for (vector<int> &cube : cubes)
        for (int &c : cube)
            cin >> c;
    
    vector<vector<int>> height(cubeCount, vector<int>(6));
    vector<vector<int>> predI(cubeCount, vector<int>(6, -1));
    vector<vector<int>> predSide(cubeCount, vector<int>(6, -1));

    vector<int> colorHeight(101);
    vector<int> colorPredI(101, -1);
    vector<int> colorPredSide(101, -1);

    for (int side = 0; side < 6; side++) {
        height[0][side] = 1;
        colorHeight[cubes[0][side]] = 1;
        colorPredI[cubes[0][side]] = 0;
        colorPredSide[cubes[0][side]] = side;
    }

    for (int i = 1; i < cubeCount; i++) {
        for (int side = 0; side < 6; side++) {
            height[i][side] = colorHeight[cubes[i][side ^ 1]] + 1;
            predI[i][side] = colorPredI[cubes[i][side ^ 1]];
            predSide[i][side] = colorPredSide[cubes[i][side ^ 1]];
        }
        for (int side = 0; side < 6; side++) {
            if (colorHeight[cubes[i][side]] < height[i][side]) {
                colorHeight[cubes[i][side]] = height[i][side];
                colorPredI[cubes[i][side]] = i;
                colorPredSide[cubes[i][side]] = side;
            }
        }
    }

    int maxHeight = 0, maxI, maxSide;
    for (int i = 0; i < cubeCount; i++) {
        for (int side = 0; side < 6; side++) {
            if (maxHeight < height[i][side]) {
                maxHeight = height[i][side];
                maxI = i;
                maxSide = side;
            }
        }
    }

    vector<pair<int, string>> tower;
    static vector<string> sides = { "front", "back", "left", "right", "top", "bottom" };
    for (int i = maxI, side = maxSide; i != -1; ) {
        tower.push_back({ i + 1, sides[side ^ 1] });
        int pi = predI[i][side];
        int pSide = predSide[i][side];
        i = pi;
        side = pSide;
    }
    reverse(tower.begin(), tower.end());

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << "\n";
    cout << tower.size() << "\n";
    for (auto &[index, side] : tower)
        cout << index << " " << side << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}