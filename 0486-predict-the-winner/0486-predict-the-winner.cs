using System;

public class Solution {
    public bool PredictTheWinner(int[] nums) {
        int n = nums.Length;
        // memo[i, j] stores the max relative score from subarray nums[i..j]
        int?[,] memo = new int?[n, n];
        
        return MaxScoreDiff(nums, 0, n - 1, memo) >= 0;
    }

    private int MaxScoreDiff(int[] nums, int i, int j, int?[,] memo) {
        // Base case: only one element left
        if (i == j) {
            return nums[i];
        }

        // Return cached result if already calculated
        if (memo[i, j].HasValue) {
            return memo[i, j].Value;
        }

        // Choice 1: Pick left number
        int pickLeft = nums[i] - MaxScoreDiff(nums, i + 1, j, memo);
        
        // Choice 2: Pick right number
        int pickRight = nums[j] - MaxScoreDiff(nums, i, j - 1, memo);

        // Optimal play: choose the maximum outcome
        memo[i, j] = Math.Max(pickLeft, pickRight);
        return memo[i, j].Value;
    }
}