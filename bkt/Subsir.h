#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Subsir
{
public :
	int n, m, x[11]{}, v[11]{};

	void afis() {
		for (int i = 1; i <= m; i++)
			cout << v[x[i]] << " ";
		cout << "\n";
	}
	void back(int k) {
		for (int i = x[k - 1] + 1; i <= n - m + k; i++)
			if (v[i] > v[x[k - 1]]) {
				x[k] = i;
				if (k == m)
					afis();
				else back(k + 1);
			}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n >> m;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		x[1] = 1;
		sort(v + 2, v + n + 1);
		back(2);
	}
};

