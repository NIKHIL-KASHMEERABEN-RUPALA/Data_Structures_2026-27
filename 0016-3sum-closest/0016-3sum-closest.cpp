class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size();
        int closest_sum = nums[0]+nums[1]+nums[2];
        for(int i = 0 ; i < n-2 ; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            while(left<right){
                int current_sum = nums[i] + nums[left] + nums[right];
            
            if(current_sum==target){
                return target;
            }
            if(std::abs(current_sum-target)<std::abs(closest_sum-target)){
                closest_sum = current_sum;
            }
            if(current_sum<target){
                ++left;
            }else{
                right--;
            }
            }
        }
        return closest_sum;
        }
};