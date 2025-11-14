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

    int moveCount, size;
    cin >> moveCount >> size;

    vector<int> moves(moveCount);
    for (int &move : moves)
        cin >> move;

    vector<int> res(size + 1, 2);
    for (int count = 1; count < res.size(); count++)
        for (int move : moves)
            if (count >= move && res[count - move] == 2)
                res[count] = 1;

    cout << (res[size] == 1 ? "First" : "Second");
}