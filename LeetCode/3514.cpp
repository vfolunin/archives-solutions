class Solution {
public:
    int uniqueXorTriplets(vector<int> &a) {
        unordered_set<int> pairXors;
        for (int i = 0; i < a.size(); i++)
            for (int j = i; j < a.size(); j++)
                pairXors.insert(a[i] ^ a[j]);

        unordered_set<int> xors;
        for (int value : a)
            for (int pairXor : pairXors)
                xors.insert(value ^ pairXor);
        return xors.size();
    }
};