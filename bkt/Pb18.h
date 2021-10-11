#include <fstream>
#include <iostream>

using namespace std;

class Pb18
{
public:
	int n, x[11]{}, p[11]{};
	bool ok = false;

	void afis() {
		for (int i = 1; i <= n; i++, cout << '\n')
			for (int j = 1; j <= n; j++)
				(j == x[i]) ? cout << "R" : cout << ".";
		cout << '\n';
	}
	void back(int k) {
		for(int i = 1; i<=n; i++)
			if (!p[i]) {
				p[i] = 1;
				x[k] = i;
				ok = true;
				for (int row = 1; row < k; row++)
					if (k - row == abs(x[k] - x[row]))
						ok = false, row = k;
				if (k == n && ok)
					afis();
				else if (ok) back(k + 1);
				p[i] = 0;
			}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		back(1);
	}
};

