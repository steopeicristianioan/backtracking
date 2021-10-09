#include <iostream>
#include <fstream>

using namespace std;

class Pb7
{
public:
	int n, m, x[11]{};
	int v[11]{};

	void getInput() {
		ifstream fin("fin.txt");
		fin >> n >> m;
		int f[10]{};
		while (n) {
			f[n % 10] ++;
			n /= 10;
		}
		int ct = 0;
		for (int i = 0; i < 10 && ct != m; i++)
			if (f[i])
				v[++ct] = i;
	}
	void afis(int size) {
		for (int i = 1; i <= size; i++)
			cout << v[x[i]];
		cout << " ";
	}
	void back(int k) {
		for (int i = 1; i <= m; i++) {
			x[k] = i;
			afis(k);
			if (k < m)
				back(k + 1);
		}
	}
	void solve() {
		getInput();
		back(1);
	}
};

