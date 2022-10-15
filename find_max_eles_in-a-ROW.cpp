#include <bits/stdc++.h>

using namespace std;

int a[505][505];

void nhap(int n, int m){
	for (int i = 0; i < n ;i++){
		for (int j = 0; j < m ;j++){
			cin >> a[i][j];
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		
		nhap(n , m);
		multimap <int , int> mp;
		set<int> st;
		int sum = 0;
		int ans = INT_MIN;
		for (int i = 0; i < n; i++){
			for (int j = 0; j< m; j++){
				sum+=a[i][j];
			}
			ans = max(ans, sum);
			mp.insert({sum, i});
			sum = 0;
			
		}
		cout << ans << endl;
		
		for (auto it = mp.begin(); it != mp.end(); it++){
			int tmp = it->first;
			if (tmp == ans){
				st.insert(it->second);
			}
		}
		cout << *st.begin() + 1 <<" " << *st.rbegin() + 1;
		mp.clear();
		st.clear();
		
		
	}
	return 0;
}