#include <iostream>
#include <fstream>

using namespace std;

class Pb2
{
public:
	int n, x[11]{};

	void afis() {
		if (x[1] == x[n] && x[n] == 1)
			return;
		for(int i = 1; i<=n; i++)
			(x[i]) ? cout << "-" : cout << ".";
		cout << "\n";
	}
	void back(int k) {
		for (int i = 0; i <= 1; i++) {
			x[k] = i;
			if (k == n)
				afis();
			else back(k + 1);
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		back(1);
	}
};

