class Solution {
public:
    int uniqueXorTriplets(vector<int> &a) {
        if (a.size() < 3) {
            unordered_set<int> xors;
            for (int i = 0; i < a.size(); i++)
                for (int j = i; j < a.size(); j++)
                    for (int k = j; k < a.size(); k++)
                        xors.insert(a[i] ^ a[j] ^ a[k]);
            return xors.size();
        }
        
        int pow = 0;
        for (int i = 0; i < 20; i++)
            if (a.size() & (1 << i))
                pow = i;
        return 1 << (pow + 1);
    }
};