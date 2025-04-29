#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
using namespace std;
ifstream fin("input.txt");
map<string, int>m;
bool cmp(string x, string y)
	{
		if (m[x] == m[y])
			return x < y;
		return m[x] < m[y];
	}
class compare {
public:
	bool operator()(string a, string b) 
	{
		if (m[a] == m[b]) 
		{
			return b < a;
		}
		return m[a] < m[b];
	}
};
int main()
{
	string s;
	vector<string> v;
	priority_queue<string,vector<string>,compare>pq;
	getline(fin, s);
	int n = s.size();
	for (int i = 0;i <= n;i++)
	{
		string cuv;
		int j = i;
		while (j <= n && (s[j] == ' ' || s[j] == '!' || s[j] == '?' || s[j] == '.' || s[j] == ','))j++;
		while (j <= n && s[j] != ' ' && s[j] != '!' && s[j] != '?' && s[j] != '.' && s[j] != ',')
		{
			cuv.push_back(s[j++]);
		}
		if (cuv.size() > 0&&j<=n)
		{
			int k = 0;
			int lg = cuv.size();
			while (k <= lg)
			{
				if (cuv[k] < 'a')cuv[k] = cuv[k] - 'A' + 'a';
				k++;
			}
			m[cuv]++;
			if (m[cuv] == 1)v.push_back(cuv);
			i = j;
		}
	}
	for (int i = 0;i < v.size();i++)
		pq.push(v[i]);
	while (!pq.empty())
	{
		cout << pq.top() << ' ' << m[pq.top()] << '\n';
		pq.pop();
	}
	return 0;
}