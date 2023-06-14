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
ll n, X[1000001];//khai báo biến n chứa độ dài và dãy x chứa cấu hình nhị phân 
void input()
{
	cin >> n;//nhập vào độ dài của dãy nhị phân cần sinh 
}

//phần in cấu hình hiện tại
void print()
{
	for (int i = 1; i <= n; i++)
		cout << X[i];
	cout << "\n";
}

void sinh_binary(int i)
{
	for (int v = 0; v <= 1; v++)
	{
		X[i] = v;
		if (i == n) print(); // nếu i == n (tức i == độ dài tối đa) thì gọi hàm in ra kết quả 
		else sinh_binary(i+1); // ngược lại tiếp tục gọi hàm sinh nhị phân với i được tăng lên 1 
	}
}
// cách sinh này thật ra là tạo 1 tree (cây)
// đầu tiên tạo tất cả dãy nhị phân độ dài 1 ta có (0,1) dễ dàng nhờ vào vòng for ở dòng 29
// do i chưa tiến đến giới hạn, nên dựa vào các dãy nhị phân độ dài 1 đã tạo ta dễ dàng tạo ra các dãy nhị phân độ dài 2 bằng cách lấy mỗi dãy độ dài 1 rồi chạy vòng for
// với dãy 0 ta tạo được 01, 00
// với dãy 1 ta tạo được 10, 11
//tương tự với n = 3, ta dùng các dãy độ dài 2 chạy vòng for
// 01 tạo ra 010 và 011
// 00 tạo ra 000 và 001
// 10 tạo ra 100 và 101
// 11 tạo ra 110 và 111
// do ta đã tạo ra cấu hình đủ độ dài nên ko tạo tiếp, in ra kết quả

void solve()
{
	sinh_binary(1);
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
