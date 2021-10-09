#include <iostream>
#include <fstream>

using namespace std;

class Note_muzicale
{
public:
	string v[9] = { "", "do", "re", "mi", "fa", "sol", "la", "si", "do" };
	int m, x[7]{}, p[7]{};

	void afis() {
		for (int i = 1; i <= m; i++)
			cout << v[x[i]] << " ";
		cout << "\n";
	}

	void back(int k) {
		for (int i = 1; i <= 8; i++){
			x[k] = i;
			if (k == m)
				afis();
			else back(k + 1);
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> m;
		back(1);
	}
};

