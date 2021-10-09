#include <iostream>
#include <fstream>

using namespace std;

class Pb4
{
public:
	int n, x[11]{}, p[11]{};

	void afis() {
		for (int i = 1; i <= n; i++, cout << '\n')
			for (int j = 1; j <= n; j++)
				(j == x[i]) ? cout << "1 " : cout << "0 ";
		cout << '\n';
	}
	void back(int k) {
		for(int i = 1; i<=n; i++)
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
		fin >> n;
		back(1);
	}
};

