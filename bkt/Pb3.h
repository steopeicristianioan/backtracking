#include <iostream>
#include <fstream>

using namespace std;

class Pb3
{
public:
	int n, x[11]{}, p[11]{};
	int v[10] = { 0,1,2,3,4,5,6,7,8,9 };

	void afis() {
		for (int i = 1; i <= n; i++)
			cout << v[x[i]];
		cout << endl;
	}
	void back(int k, int parAl, int imparAl) {
		for (int i = 0; i <= 9; i++) {
			if (parAl == 2 && i % 2 == 0);
			else if (imparAl == 2 && i % 2 == 1);
			else if(parAl <= 2 && imparAl <= 2){
				x[k] = i;
				if (v[x[1]]) {
					if (k == n)
						afis();
					else{
						if (i % 2 == 0) {
							if(x[k - 1] % 2 == 0)
								back(k + 1, parAl + 1, imparAl);
							else back(k + 1, 1, imparAl);
						}
						else {
							if (x[k - 1] % 2 == 1)
								back(k + 1, parAl, imparAl + 1);
							else back(k + 1, parAl, 1);
						}
					}
				}
			}
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		back(1, 0, 0);
	}
};

