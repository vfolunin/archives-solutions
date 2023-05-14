class Solution {
public:
    bool doesValidArrayExist(vector<int> &xors) {
        vector<int> a(xors.size());
        for (int i = 0; i + 1 < a.size(); i++)
            a[i + 1] = a[i] ^ xors[i];
        
        return a[0] == a.back() ^ xors.back();
    }
};