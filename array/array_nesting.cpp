//A zero-indexed array A of length N contains all 
//integers from 0 to N-1. Find and return the 
//longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } 
//subjected to the rule below.



public class Solution {
    public int arrayNesting(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != Integer.MAX_VALUE) {
                int start = nums[i], count = 0;
                while (nums[start] != Integer.MAX_VALUE) {
                    int temp = start;
                    start = nums[start];
                    count++;
                    nums[temp] = Integer.MAX_VALUE;
                }
                res = Math.max(res, count);
            }
        }
        return res;
    }
}