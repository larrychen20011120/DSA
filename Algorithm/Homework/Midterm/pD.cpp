#include<iostream>
#include<vector>
#include<string>

using namespace std;

int pro(string pwd, string target) {
	int plen = pwd.size();
	int tlen = target.size();
	int count = 0;
	int p = 0, t = 0;
	while (p < plen && t < tlen) {
		if (pwd[p] == target[t]) {
			count++;
			t++;
		}
		p++;
	}
	return (plen-count) + (tlen-count);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector <string> all_two_power;
	for (unsigned long long int i = 1; i <= 1e18; i *= 2) {
		all_two_power.push_back(to_string(i));
	}
	int N;
	cin >> N;
	for (int bomb = 0; bomb < N; bomb++) {
		string passwd;
		cin >> passwd;
		int ans = passwd.size() + 1; // all delete and add 1
		for (auto a : all_two_power) {
			ans = min(ans, pro(passwd, a));
		}
		cout << ans;
		cout << endl;
    }
	return 0;
}
