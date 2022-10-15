#include <bits/stdc++.h>

using namespace std;

using ll = long long;


bool check_fibo(ll n){
	ll f[101];
	f[0] = 0; f[1] = 1;
	if (n == 0 || n ==  1) return true;
	for (int i = 2; i < 101; i++){
		f[i] = f[i-1] + f[i-2];
		if (f[i] == n) return true;
	}
	return false;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		ll a[n][m];
		map <int , ll> mp;
		map <ll, int> mp1;
		set <int> st;
		for (int i = 0;  i < n; i++){
			for (int j = 0; j < m ;j++){
				cin>> a[i][j];
			}
		}
		int ans  = INT_MIN;
		for (int j = 0; j < m; j++){
			int count = 0;
			ll sum = 0;
			for (int i = 0; i < n; i++){
				if (check_fibo(a[i][j])){
					count++;
				}	
			}
			ans = max(ans, count);
			mp.insert({j, count});
		}
		for (auto it = mp.begin(); it != mp .end(); it++){
			int tmp = it->second;
			if (tmp == ans){
				st.insert(it->first);
			}
		}
		for (auto it = st.begin(); it != st.end(); it++){
			ll sum = 0;
			int j = *it;
			for (int i = 0; i < n; i++){
				if (check_fibo(a[i][j])){
					sum+=a[i][j];
				}
			}
			mp1.insert({sum, j});
		}
		auto it = mp1.rbegin();
		int tmp = it->second;
		for (int i = 0; i < n; i++){
			if (check_fibo(a[i][tmp])) cout << a[i][tmp] <<" ";
		}
		
		mp.clear(); mp1.clear(); st.clear();
		cout << endl;
		
	}
	return 0;
}