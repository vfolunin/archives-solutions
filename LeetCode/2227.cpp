class Encrypter {
    unordered_map<char, string> code;
    unordered_map<string, int> decode;
    
public:
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dict) {
        for (int i = 0; i < keys.size(); i++)
            code[keys[i]] = values[i];
        for (string &s : dict)
            decode[encrypt(s)]++;
    }
    
    string encrypt(const string &s) {
        string res;
        for (char c : s) {
            if (!code.count(c))
                return "";
            res += code[c];
        }
        return res;
    }
    
    int decrypt(const string &s) {
        if (auto it = decode.find(s); it != decode.end())
            return it->second;
        return 0;
    }
};