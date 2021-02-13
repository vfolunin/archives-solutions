#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compareBlocks(vector<int> &a, vector<int> &b) {
    return a[0] * a[1] > b[0] * b[1];
}

bool solve(int test) {
    int blockCount;
    cin >> blockCount;

    if (!blockCount)
        return 0;

    vector<vector<int>> blocks;
    for (int i = 0; i < blockCount; i++) {
        vector<int> block(3);
        cin >> block[0] >> block[1] >> block[2];

        sort(block.begin(), block.end());
        do
            blocks.push_back(block);
        while (next_permutation(block.begin(), block.end()));
    }
    
    sort(blocks.begin(), blocks.end(), compareBlocks);

    vector<int> maxHeight(blocks.size());
    for (int i = 0; i < blocks.size(); i++) {
        maxHeight[i] = blocks[i][2];
        for (int j = 0; j < i; j++)
            if (blocks[j][0] > blocks[i][0] && blocks[j][1] > blocks[i][1] && maxHeight[j] + blocks[i][2] > maxHeight[i])
                maxHeight[i] = maxHeight[j] + blocks[i][2];
    }

    cout << "Case " << test << ": maximum height = " << *max_element(maxHeight.begin(), maxHeight.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}