class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_water = 0;
        while(left<right){
            int h_left = height[left];
            int h_right = height[right];
            int curr_height = std::min(h_left,h_right);
            
            max_water = std::max(max_water,curr_height*(right-left));
            if(h_left<=h_right){
                while(left<right && height[left] <= curr_height){
                    left++;
                }
            }
            else{
                while(left<right && height[right]<= curr_height){
                    right--;
                }
            }
        }
        return max_water;
    }
};