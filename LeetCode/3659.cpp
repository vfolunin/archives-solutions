class Solution {
public:
    bool partitionArray(vector<int> &a, int groupSize) {
        if (a.size() % groupSize)
            return 0;
        
        int groupCount = a.size() / groupSize;

        unordered_map<int, int> count;
        for (int value : a)
            if (++count[value] > groupCount)
                return 0;
        
        return 1;
    }
};