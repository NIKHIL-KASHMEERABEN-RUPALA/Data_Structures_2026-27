class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        bool has_odd = false;

        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                has_odd = true;
            }
        }

        // If no odd numbers exist, we can keep everything even.
        // If the smallest element is odd, every even element can subtract an odd number.
        return !has_odd || (min_val % 2 != 0);
    }
};