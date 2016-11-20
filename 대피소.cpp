#include <stdio.h>
#include <vector>
#include <set>

#define INFINITE 2100000000

using namespace std;

void sub()
{
	int n, m, k;
	int sum_dist = 0, sum_vertex = 0;

	scanf("%d %d %d", &n, &m, &k);

	vector<int> s(n + 1, 0);
	vector< vector< pair<int, int> > > g(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	for (int i = 0; i < k; ++i)
	{
		int shelter;
		scanf("%d", &shelter);
		s[shelter] = 1;
	}

	for (int beg = 1; beg <= n; ++beg)
	{
		int m = 0;
		set< pair<int, int> > pq;
		vector<int> dist(n + 1, INFINITE);

		dist[beg] = 0;
		pq.insert(make_pair(0, beg));

		while (!pq.empty())
		{
			pair<int, int> top = *pq.begin();
			pq.erase(top);

			int current = top.second;
			if (s[current] && dist[current] < dist[m]) m = current;

			const vector< pair<int, int> > &edges = g[current];

			for (int i = 0; i < edges.size(); ++i)
			{
				int next = edges[i].first;

				if (dist[next] > dist[current] + edges[i].second)
				{
					pq.erase(make_pair(dist[next], next));
					pq.insert(make_pair(dist[current] + edges[i].second, next));
					dist[next] = dist[current] + edges[i].second;
				}
			}
		}

		sum_dist += dist[m];
		sum_vertex += m;
	}

	printf("%d\n%d\n", sum_dist, sum_vertex);
}

int main()
{
	setbuf(stdout, NULL);

	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; ++i)
	{
		printf("Case #%d\n", i);
		sub();
	}
	return 0;
}