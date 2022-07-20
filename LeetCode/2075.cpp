class Solution {
public:
    string decodeCiphertext(string &s, int h) {
        int w = s.size() / h;
        
        string res;
        for (int x = 0; x < w; x++)
            for (int delta = 0; delta < h && x + delta < w; delta++)
                res += s[delta * w + x + delta];
        
        while (res.back() == ' ')
            res.pop_back();
        
        return res;
    }
};