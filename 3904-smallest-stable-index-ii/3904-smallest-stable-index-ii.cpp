#include <vector>
#include <algorithm>

static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // suffix_min[i] will store min(nums[i..n-1])
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
        }

        // Maintain prefix maximum on the fly
        int prefix_max = nums[0];
        for (int i = 0; i < n; ++i) {
            if (nums[i] > prefix_max) {
                prefix_max = nums[i];
            }
            if (prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};