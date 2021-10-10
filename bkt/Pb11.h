#include <iostream>
#include <fstream>

using namespace std;

class Pb11
{
public:
	int n, sum, v[11]{}, x[11]{};
	char c[4] = { '.', '*', '+', '-' };
	//1-inmultire, 2-adunare, 3-scadere

	int result(int s, int op, int value) {
		if (op == 1)
			return s * value;
		if (op == 2)
			return s + value;
		return s - value;
	}
	void afis() {
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = result(res, x[i], v[i]);
		if (res == sum) {
			for (int i = 1; i <= n; i++)
				cout << c[x[i]] << v[i];
			cout << '\n';
		}
	}
	void back(int k) {
		for (int i = 1; i <= 3; i++) {
			x[k] = i;
			if (x[1] != 1) {
				if (k == n)
					afis();
				else back(k + 1);
			}
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> sum >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		back(1);
	}
};

