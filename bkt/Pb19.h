#include <iostream>
#include <fstream>

using namespace std;

class Pb19
{
public:
	int n, f[11][11]{}, x[11]{}, p[11]{};
	string v[11]{};

	void afis() {
		for (int i = 1; i <= n; i++)
			cout << v[x[i]] << " ";
		cout << '\n';
	}
	void back(int k) {
		for(int i = 1; i<=n; i++)
			if (!p[i] && !f[i][x[k - 1]]) {
				p[i] = 1;
				x[k] = i;
				if (k == n)
					afis();
				else if (k < n) back(k + 1);
				p[i] = 0;
			}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		for (int i = 1; i < n; i++)
			f[i][i + 1] = f[i + 1][i] = 1;
		back(1);
	}
};

