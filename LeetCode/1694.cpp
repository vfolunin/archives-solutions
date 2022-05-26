class Solution {
public:
    string reformatNumber(string number) {
        string res, block;
        
        for (char c : number) {
            if (isdigit(c)) {
                block += c;
                if (block.size() == 3) {
                    res += block + "-";
                    block = "";
                }
            }
        }
        
        if (block.size() == 0) {
            res.pop_back();
        } else if (block.size() == 1) {
            swap(res[res.size() - 2], res[res.size() - 1]);
            res += block;
        } else {
            res += block;
        }
        return res;
    }
};