class Solution {
public:
    bool canCross(vector<int> &coords) {
        map<int, unordered_set<int>> jumps;
        for (int coord : coords)
            jumps[coord];
        
        if (jumps.count(coords[0] + 1))
            jumps[coords[0] + 1].insert(1);
        
        for (int coord : coords)
            for (int jump : jumps[coord])
                for (int delta : { -1, 0, 1 })
                    if (jump + delta > 0 && jumps.count(coord + jump + delta))
                        jumps[coord + jump + delta].insert(jump + delta);
        
        return !jumps[coords.back()].empty();
    }
};