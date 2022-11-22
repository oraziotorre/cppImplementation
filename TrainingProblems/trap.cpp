#include <bits/stdc++.h>

using namespace std;

int N, L;

int main() {
//  uncomment the following lines if you want to read/write from files
  	ifstream ifs("input.txt");
 	ofstream ofs("output.txt");
	ios::sync_with_stdio(false);
	ifs.tie(0);
    cin >> N >> L;
    map<string,int> Ripetizioni;
    vector<string> Canzone;
    map <string,bool> check;
    for (int i=0; i<N; ++i) {
        check.clear();
        int M;
        cin >> M;

        for (int j=0; j<M; ++j) {
            string s;
            cin >> s;

            if (check.find(s) != check.end()) continue;

            if (i==0) {

                Canzone.push_back(s);
                if (Ripetizioni.find(s) == Ripetizioni.end()) {
                    Ripetizioni[s] = 0;
                }
            }

            else {

                if (Ripetizioni.find(s) != Ripetizioni.end()) {
                    Ripetizioni[s] = Ripetizioni[s] + 1;
                    check[s] = true;
                }
            }

        }
    }

    for (auto s : Canzone) {
        cout << Ripetizioni[s] << " ";
    }
    cout << "\n";

    return 0;
}