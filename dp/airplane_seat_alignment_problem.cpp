/*
----------------------------------------
for(n==1)
if you are only passenger then there will be only one seat as well.So either you lose ticket or not you will sit in that only seat and since you are nth person as well so u get the probability of 100% i.e 1.0000.

for(n>1)
since we have to calculate the probability of nth person to sit in his/her own place,the the passenger mising his/her ticket has two case:
			1.if he/she sits in his/her own place the all other passengers will sit in their seat as given in question.
			2.if 1st passenger sits in anyone else's place then no matter who sits where nth passenger will either sit in his/her place or he/she won't.
	so the probability will always gonna remain 0.5000.



    Let's first consider some cases:

n = 1. The probability is 1.

n = 2. The probability is 1/2.

n = 3. The probability is 1/3 + 1/3 * 1/2 = 1/2.

n = 4. The first passenger P1 can take any of the four seats S1,S2,S3,S4 with equal probabilities.

If P1 takes S1, then all the passengers can take their own seats.
If P1 takes S2, then the rest three fall into the case of n = 3, with P2 being the first
passenger who has lost the ticket and can choose randomly
(actually, P2 finds his/her seat occupied but these two situations are equivalent here).
If P1 takes S3, then P2 will take his/her own seat S2. The rest two fall into the case of n = 2,
with P3 being the first passenger who has lost the ticket and can choose randomly
(actually, P3 finds his/her seat occupied but these two situations are equivalent here).
If P1 takes S4, then P4 will not be able to get his/her own seat.
Therefore, the probability is 1/4 + 1/4 * 1/2 + 1/4 * 1/2 = 1/2.

With above observations, it is a reasonable conjecture that p = 1/2 when n > 1. In fact, we can prove it by induction:

Denote by p(n) the probability that the n-th person can get his/her own seat. Denote by S[i] the right seat of the i-th
passenger P[i].

Suppose that p(n) = 1/2 for all n from 2 to k-1.

When n = k, as far as P[1] is concerned, there are k possibilities (with equal probabilities):

P[1] takes S[k], then P[k] will not be able to get his/her own seat.
P[1] takes S[k-1], then P[2],P[3],P[4],...,P[k-2] will take their own seats. Regard S[1] as the right seat of P[k-1],
then P[k-1] and P[k] fall into the situation of n = 2.
P[1] takes S[k-2], then P[2],P[3],P[4],...,P[k-3] will take their own seats. Regard S[1] as the right seat of P[k-2],
then P[k-2],P[k-1] and P[k] fall into the situation of n = 3.
...
P[1] takes S[1], then P[k] will definitely get his/her own seat.
Thus p(k) = 1/k + (k-2)/k * 1/2 = 1/2.

*/
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
            return 1;
        return 0.5;
    }
};