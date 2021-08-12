//Given an array of non-negative integers, you are initially positioned at the first index of the array.

//Each element in the array represents your maximum jump length at that position.

//Determine if you are able to reach the last index.


public class Solution {
    public boolean canJump(int[] nums) {
        int lastPos = nums.length - 1;              // here lastPos is nlength-1 which is important
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
} 