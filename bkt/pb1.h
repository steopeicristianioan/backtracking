#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Pb1
{
	public:
		int n, m, d[101]{}, x[11]{}, ct = 0;

		void getDiv() {
			for(int i = 1; i*i<=n; i++)
				if (n % i == 0) {
					d[++ct] = i;
					if (i * i < n)
						d[++ct] = n / i;
				}
		}
		void afis() {
			for (int i = 1; i <= m; i++)
				cout << d[x[i]] << " ";
			cout << endl;
		}
		void back(int k) {
			for (int i = x[k - 1] + 1; i <= ct - m + k; i++) {
				x[k] = i;
				if (k == m)
					afis();
				else back(k + 1);
			}
		}
		void solve() {
			ifstream f("fin.txt");
			f >> n >> m;
			getDiv();
			sort(d + 1, d + ct + 1);
			back(1);
		}

};

