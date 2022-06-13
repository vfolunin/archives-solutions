class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        static vector<string> letterCode = {
            ".-", "-...", "-.-.", "-..", ".",
            "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---",
            ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        
        unordered_set<string> codes;
        for (string &word : words) {
            string code;
            for (char letter : word)
                code += letterCode[letter - 'a'];
            codes.insert(code);
        }
        return codes.size();
    }
};