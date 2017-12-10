#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	string email;
	cout << "Nhap dia chi email: "; getline(cin, email);

	regex pattern("[a-zA-Z0-9_\.]+@[a-zA-Z]+\.[a-zA-Z]+(\.[a-zA-Z]+)*");

	// Hàm regex_match() dùng để kiểm tra TOÀN BỘ chuỗi
	// Hàm regex_search() dùng để kiểm tra CHUỖI CON trong chuỗi

	if (regex_match(email, pattern))
		cout << "Email hop le!" << endl;
	else
		cout << "Email khong hop le!" << endl;
	/*
	*** Phân tích:
	- Cú pháp: Tên Email + @ + Tên miền
	+ Tên Email: Ký tự hoa, ký tự thường, chữ số, dấu gạch dưới, và dấu chấm
	=> Gom thành một nhóm: [a-zA-Z0-9_\.]
	+ Ký tự @
	+ Tên miền: Ký tự hoa, ký tự thường, có dấu chấm để phân cách
	# [a-zA-Z]+\.[a-zA-Z]: chỉ hợp lệ với: gmail.com, yahoo.com. outlook.com,.. Còn các tên miền như: outlook.com.vn, yahoo.com.vn,.. thì sao?
	# Giải quyết bằng cách cộng thêm (\.[a-zA-Z]+)* dấu * thể hiện rằng nhóm (\.[a-zA-Z]+) có thể có hoặc không
	*/

	system("pause");
	return 0;
}
/*
***ECMAScript***
.:		đại diện cho bất kì kí tự nào ngoại trừ \
[abc]:	khớp với 1 kí tự trong nhóm kí tự a, b hoặc c
[a-z]:	khớp với 1 kí tự trong vùng từ a-z, ngăn cách bằng dấu –
[^abc]: khớp với 1 kí tự ngoại trừ nhóm kí tự a, b và c
\d:		kí tự chữ số tương đương [0-9]
\D:		kí tự không phải chữ số
\s:		kí tự khoảng trắng (space)
\S:		kí tự không phải khoảng trắng
\w:		kí tự word (gồm chữ cái, chữ số và dấu _), tương đương [a-zA-Z0-9_]
\W:		tương đương [^a-zA-Z0-9_]
^:		bắt đầu 1 chuỗi hay 1 dòng
$:		kết thúc 1 chuỗi hay 1 dòng
\:		biểu diễn 1 kí tự đặc biệt trong regex thành kí tự thường (ví dụ \. sẽ khớp với dấu chấm, nếu thiếu \ sẽ hiểu nhầm là kí tự đại diện . phía trên mình đã nói)
|:		kí tự tương đương phép or (sử dụng nhiều trong cặp móc tròn)
():		khớp với 1 nhóm các kí tự (ví dụ Ste(v|ph)en sẽ khớp với Steven hoặc Stephen)
?:		khớp với kí tự đứng trước 0 – 1 lần (ví dụ S?even sẽ khớp Seven hoặc even)
*:		khớp với kí tự đứng trước từ 0 lần trở lên (ví dụ Te*n sẽ khớp Tn, Ten, Teen, Teeen, Teeeen,…)
+:		khớp với kí tự đứng trước từ 1 lần trở lên (ví dụ Te+n sẽ khớp Ten, Teen, Teeen,…)
{<n>}:	khớp đúng với <n> kí tự trước đó (ví dụ Te{2}n sẽ khớp Teen)
{<n>,}: khớp với <n> kí tự trước đó trở lên (ví dụ Te{2,}n sẽ khớp Teen, Teeen, Teeeen,…)
{<n>,<m>}: khớp từ <n> đến <m> kí tự trước đó (ví dụ Te{1,3}n sẽ khớp Ten, Teen, Teeen,…)
*/