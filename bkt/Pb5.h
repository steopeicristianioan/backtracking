#include <iostream>
#include <fstream>

using namespace std;

class Pb5
{
public:
	int n, m, x[11]{}, p[11]{};
	int ciur[1001]{}, prime[50]{};

	void getPrime() {
		ciur[0] = ciur[1] = 1;
		for(int i = 2; i*i <= 1000; i++)
			if (!ciur[i]) {
				for (int j = 2; j <= 1000 / i; j++)
					ciur[i * j] = 1;
			}
	}
	void storePrime() {
		int ct = 0;
		for (int i = 11; i <= 1001 && ct != m; i++)
			if (!ciur[i])
				prime[++ct] = i;
	}
	void afis() {
		for (int i = 1; i <= n; i++)
			cout << prime[x[i]] << " ";
		cout << '\n';
	}
	void back(int k) {
		for(int i = 1; i<=m; i++)
			if (!p[i]) {
				p[i] = 1;
				x[k] = i;
				if (k == n)
					afis();
				else back(k + 1);
				p[i] = 0;
			}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n >> m;
		getPrime();
		storePrime();
		back(1);
	}
};

