#include <iostream>
#include <fstream>

using namespace std;

class Pb17
{
public:
	int n, v[26]{}, x[26]{};
	int ciur[101]{}, ct = 0;

	void eratostene() {
		ciur[0] = ciur[1] = 1;
		for(int i = 1; i*i <=10; i++)
			if (!ciur[i]) {
				for (int j = 2; j <= 100 / i; j++)
					ciur[i * j]++;
			}
	}
	void afis(int k) {
		for (int i = 1; i <= k; i++)
			cout << v[x[i]] << " ";
		cout << '\n';
	}
	void back(int k, int s) {
		for (int i = 1; i <= ct && s + v[i] <= n; i++) {
			x[k] = i;
			if (s + v[i] == n)
				afis(k);
			else back(k + 1, s + v[i]);
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		eratostene();
		for (int i = 2; i < n; i++)
			if (!ciur[i])
				v[++ct] = i;
		back(1, 0);
	}
};

