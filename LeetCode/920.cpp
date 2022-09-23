class Solution {
public:
    int numMusicPlaylists(int songCount, int playlistSize, int windowSize) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> ways(playlistSize + 1, vector<long long>(songCount + 1));
        ways[0][0] = 1;
        
        for (int p = 1; p <= playlistSize; p++) {
            for (int s = 1; s <= songCount; s++) {
                ways[p][s] = ways[p - 1][s - 1] * (songCount - s + 1) % MOD;
                if (s > windowSize)
                    ways[p][s] = (ways[p][s] + ways[p - 1][s] * (s - windowSize)) % MOD;
            }
        }
        
        return ways[playlistSize][songCount];
    }
};