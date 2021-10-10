#include <iostream>
#include <fstream>

using namespace std;

class Pb10
{
public:
    int n, sum, x[11]{}, v[11]{};
    bool gasit = false;

    void afis(int ct) {
        if (!gasit) {
            ct++;
            gasit = true;
        }
        for (int i = 1; i <= n; i++) {
            if (x[i]) {
                cout << x[i] << "*" << v[i] << " ";
                ct--;
                if (ct > 0) cout << "+ ";
            }
        }
        cout << '\n';
    }
    void back(int k, int s, int ct) {
        for (int i = 0; s + i * v[k] <= sum; i++) {
            x[k] = i;
            if (k == n && s + i * v[k] == sum)
                afis(ct);
            else if (k < n) back(k + 1, s + i * v[k], (i) ? ct + 1 : ct);
        }
    }
	void solve() {
		ifstream fin("fin.txt");
		fin >> sum >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		back(1, 0, 0);
	}
};

