#include <iostream>
#include <fstream>

using namespace std;

class Sesiune
{
public:
	int n, m, x[11]{};

	void afis() {
		for (int i = 1; i <= m; i++)
			cout << x[i] << " ";
		cout << "\n";
	}
	void back(int k) {
		for (int i = x[k - 1] + 2; i <= n - m + k; i ++) {
			x[k] = i;
			if (k == m)
				afis();
			else back(k + 1);
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n >> m;
		x[0] = -1;
		back(1);
	}
};

