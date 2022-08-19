class Solution {
    int minMoves(vector<int> &pos) {
        if (pos[0] + 2 == pos[2])
            return 0;
        if (pos[0] + 2 >= pos[1] || pos[1] + 2 >= pos[2])
            return 1;
        return 2;
    }
    
    int maxMoves(vector<int> &pos) {
        return pos[2] - pos[0] - 2;
    }
    
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = { a, b, c };
        sort(pos.begin(), pos.end());
        return { minMoves(pos), maxMoves(pos) };
    }
};