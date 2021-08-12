/*
In phase 1, hare = nums[nums[hare]] is twice as fast as tortoise = nums[tortoise].
Since the hare goes fast, it would be the first one who enters the cycle and starts
to run around the cycle. At some point, the tortoise enters the cycle as well, and
since it's moving slower the hare catches the tortoise up at some intersection point.
Now phase 1 is over, and the tortoise has lost.
*/


class Solution {
  public :
  int findDuplicate(int[] nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {                            // do not use while here always use do while for first case
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
  }
}