public class Solution {
    public bool StoneGameIX(int[] stones) {
        int[] count = new int[3];
        foreach (int stone in stones) {
            count[stone % 3]++;
        }

        // When count[0] is even, Alice needs at least one '1' and one '2'
        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        }

        // When count[0] is odd, Alice needs a difference > 2
        return Math.Abs(count[1] - count[2]) > 2;
    }
}