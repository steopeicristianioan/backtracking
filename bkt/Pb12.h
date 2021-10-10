#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Pb12
{
public:
	int n, m, x[11]{};
	char v[11]{};

	void afis() {
		for (int i = 1; i <= m; i++)
			cout << v[x[i]];
		cout << " ";
	}
	void back(int k) {
		for (int i = x[k - 1] + 1; i <= n - m + k; i++){
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
		sort(v + 1, v + n + 1);
		back(1);
	}
};

