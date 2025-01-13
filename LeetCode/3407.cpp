class Solution {
public:
    bool hasMatch(string &a, string &b) {
        int pos = b.find('*');
        string l = b.substr(0, pos);
        string r = b.substr(pos + 1);

        int lPos = a.find(l);
        int rPos = a.rfind(r);
        return lPos != -1 && rPos != -1 && lPos + l.size() <= rPos;
    }
};