#include <vector>
#include <string>

static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        // If s is shorter than t, t cannot be a subsequence of s
        if (m < n) return 0;
        if (m == n) return s == t ? 1 : 0;

        // dp[j] stores the number of distinct subsequences of s that match t[0...j-1]
        // Using unsigned long long prevents overflow during intermediate additions
        std::vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        // Precompute the positions of each character in t
        // Positions are stored in reverse order to allow in-place 1D DP transitions
        std::vector<int> char_pos[128];
        for (int j = n - 1; j >= 0; --j) {
            char_pos[static_cast<unsigned char>(t[j])].push_back(j);
        }

        // Iterate through each character in s and update only the matching positions in t
        for (char c : s) {
            const auto& positions = char_pos[static_cast<unsigned char>(c)];
            for (int j : positions) {
                dp[j + 1] += dp[j];
            }
        }

        return dp[n];
    }
};