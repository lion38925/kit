/* explanation
    lets solve the problem only for 2 chicken.
    s[i] = speed of chicken i
    pos[i] = position of chicken i

    if s[i] > s[i - 1] then no problem, just check whether both can reach b within time or not.

    if s[i] < s[i - 1] then there is a chance that i can slow down i - 1.
    lets say s[i] = 1 m/sec and s[i - 1] = 2 m/sec and time limit is T and point to reach is B.

    for s[i] pos[i] can be at max B - T. if pos is greater than B-T it can not reach within Tsec.
    and for s[i - 1] pos[i - 1] can be at max (B-T)*2. if pos[i - 1] > (B-T)*2 it can not reach within Tsec.

    at T sec i will be at B and i - 1 will also be at B. at T - 1 i will be at B-T-1 and i-1 will be at B-T-2 and so on. as we can see i -1 will always be behind i. so there will not be any collision.

    if i is pos[i] < B-T then i can reach B before T sec and it will not cause any problem .

    problem may occur if pos[i - 1]< (B -T)*2 as it can meet i at some point and i can slow it down. so lets say both i and i-1 meet at some time t sec(t < T). so pos[i - 1] + 1 = pos[i]. within remaining T - t time i can reach B, so i - 1 can also reach B. at time T - 1 i will be at B-T-1 and i -1 will be at B-T-2 and next sec both can reach B because s[i-1] > s[i].

    and if i and i -1 meet at t sec (t > T) then it is not a problem at all.
    so if a chicken can reach B with in T sec then other chicken need not be replaced. if a chicken cannot reach B within T sec the it has to be swapped.
*/

#include <iostream>

using namespace std;

int main()
{
    int c;
    long long n, k, b, t;
    long long pos[51], speed[51];
    cin >> c;

    for(int i = 1; i <= c; i++)
    {
        cin >> n >> k >> b >> t;
        for(int j = 0; j < n; j++)
        {
            cin >> pos[j];
        }

        for(int j = 0; j < n; j++)
        {
            cin >> speed[j];
        }

        long num = 0;
        long result = 0;
        long swap = 0;

        for(int j = n - 1; j >= 0; j--)
        {
            long long distanceCover = speed[j] * t;
            long long distanceToCover = b - pos[j];

            if(distanceToCover <= distanceCover)
            {
                num++;

                if(swap > 0)
                {
                    result += swap;
                }
            }
            else
            {
                swap++;
            }

            if(num == k)
                break;
        }

        if(num < k)
        {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        }
        else
        {
             cout << "Case #" << i << ": " << result << endl;
        }

    }
    return 0;
}