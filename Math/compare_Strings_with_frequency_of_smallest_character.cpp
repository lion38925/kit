class Solution {
	public:

    // question of binary search 
		vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

			int n = words.size();
			vector<int>a(n);
			for(int i = 0;i<words.size();i++)
			{

				sort(words[i].begin(),words[i].end());
				int count = 0;
				for(auto x:words[i])
				{
					if(x!=words[i][0])
					{
						break;
					}
					count++;
				}
				a[i] = count;
			}
			sort(a.begin(),a.end());
			vector<int>res;
			for(int i = 0;i<queries.size();i++)
			{
				sort(queries[i].begin(),queries[i].end());
				int count = 0;
				for(auto x:queries[i])
				{
					if(x!=queries[i][0])
					{
						break;
					}
					count++;
				}
				int it = upper_bound(a.begin(),a.end(),count)-a.begin();
				res.push_back(n-it);
			}
			return res;
		}
	};