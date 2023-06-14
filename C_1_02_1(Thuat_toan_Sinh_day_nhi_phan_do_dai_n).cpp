//phần khai báo
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

const ll MOD = 1e9+7;
const ll base = 31;

//phần nhập dữ liệu vào
ll n, x[1000001];//khai báo biến n chứa độ dài và dãy x chứa cấu hình nhị phân 
void input()
{
	cin >> n;//nhập vào độ dài của dãy nhị phân cần sinh 
}

//phần thuật toán
void solve()
{
	int i; //khai báo biến i cần dùng
	do
	{
		for (i = 1; i <= n; i++) cout << x[i]; //in ra cấu hình hiện tại (VD: n = 3 | 000)
		 // xuống hàng
		i = n; //cho i xuống cuối dãy (VD: n = 3 | i = 3)
		cout << "\n";
		
		while(i > 0 && x[i] == 1) i--;// nếu vị trí thứ i đã là số 1 thì dời i lên cho đến khi vị trí đó khác số 1
		// (VD: cấu hình hiện tại = 001 | n = 3)
		// b1: i = n; (i = 3)
		// do i > 0 (3 > 0) và x[3] == 1 nên i được dời lên 1 đơn vị (i = 2)
		// lúc này mặc dù i > 0 (2 > 0) nhưng x[2] != 1 nên thoát vòng lặp. i = 2;
		
		//lưu ý: đừng nhầm lẫn ở chỗ (i > 0) thì i không bằng 0 được nha vì cái này kiểm tra trước 1 bước. Ví dụ nè
		/*
			cấu hình: 111 | n = 3
			i = n = 3;
			(3 > 0) && (x[3] == 1) i-- (i = 2)
			(2 > 0) && (x[2] == 1) i-- (i = 1)
			(1 > 0) && (x[1] == 1) i-- (i = 0)
			
			(0 > 0) && (x[0] == 1) i-- (i = 0) không thực hiện vì (0 > 0) false và x[0] cũng không bằng 1 vì bắt đầu mảng là 1 
		*/
		
		if (i > 0) 
		// kiểm ta xem i có bằng 0 hay không vì nếu bằng 0 tức là toàn bộ dãy đã là 1, 
		// là cấu hình cuối cùng (VD n = 3| cấu hình cuối cùng 111)
		{
			x[i] = 1; // cho vị trí i bằng 1
			for (int j = i+1; j <= n; j++) x[j] = 0; // cho tất cả vị trí sau i bằng 0
		}
	}
	while(i != 0); // lí do phải sài vòng lặp do-while vì mình muốn in ra cấu hình đầu tiên (n = 3| 000) còn không thì phải in thủ công
	// nếu i == 0 (cấu hình cuối cùng) thì dừng
}
/*
VD n = 3
output:
000
001
010
011
100
101
110
111
*/


//phần chạy thuật toán
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK+".INP","r",stdin);
	//freopen(TASK+".OUT","w",stdout);
	int t = 1; //cin >> t;
	while (t--)
	{
		input(), solve();
	}
}
