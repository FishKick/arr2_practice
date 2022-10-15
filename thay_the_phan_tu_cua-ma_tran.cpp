#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int a[n][m];
		int b[n][m];
		int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // chi so hàng 
		int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
		for (int i = 0; i < n;i++){
			for (int j= 0 ; j < m; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 0;i < n;i++){
			for (int j = 0; j < m; j++){
				int sum = a[i][j];
				for (int k = 0; k < 8; k++){
					int i_current = i + dx[k];
					int j_current = j + dy[k];
					if (i_current >= 0 && i_current < n && j_current >= 0 && j_current < m)
						sum+=a[i_current][j_current];
				}
				b[i][j] = sum;
			}
			
		}
		
		for (int i = 0; i < n;i++){
			for (int j = 0; j < m; j++){
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
		
		
	}
	return 0;
}