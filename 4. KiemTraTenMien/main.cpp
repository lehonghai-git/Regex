#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	string url = "https://www.google.com.vn/";

	regex pattern("(http|https|ftp):\\/\\/(www\\.)?[\\w\\-]+\\.[\\w]+(\\.[\\w]+)*\\/?(([\\w\\-]+)\\/?)*([\\w\\-_]+\.(php|html|htm|jsp|aspx))?(\\?([\\w\\-]+=[\\w\\-]+)*(&([\\w\\-]+=[\\w\\-]+))*)?");
	if (regex_match(url, pattern))
		cout << "Ten mien hop le" << endl;
	else
		cout << "Ten mien khong hop le" << endl;

	/*
	*** Phân tích:
	1. Tên miền: (http|https|ftp):\\/\\/(www\\.)?[\\w\\-]+\\.[\\w]+(\\.[\\w]+)*\\/?
	2. Path: (([\\w\\-]+)\\/)*([\\w\\-_]+\\.(php|html|htm|jsp|aspx))?
	3. Biến: (\\?([\\w\\-]+=[\\w\\-]+)?(&([\\w\\-]+=[\\w\\-]+))*)?

	- Tên miền
	+ Protocol có thể là http hoặc https hoặc ftp,..
	+ Dấu hai chấm và hai dấu // nhưng vì nó là ký tự đặc biệt nên chỉnh thành: \\/\\/
	+ có thể có www hoặc không nên để trong group (www\\.)? để chỉ khớp 0 – 1 lần duy nhất.
	+ Cuối cùng là dấu / nhưng có thể không cần nên ta thêm ? vào
	- Path: http://trachanhso.net/thuat-toan/ hoặc http://trachanhso.net/index.php hoặc http://trachanhso.net/thuat-toan/index.php
	+ Bao gồm: ký tự chữ, số, gạch chân, dấu trừ, kết thúc có thể có / hoặc không: [\\w\\-]+)\\/?
	Tuy nhiên ta cần phải thêm dấu * trong các trường hợp như http://trachanhso.net/ hoặc http://trachanhso.net/thuat-toan/abc-xyz/dauan-tuongan/, như vậy sẽ trở thành ([\\w\\-]+)\\/)*
	+ Nếu URL có tên file, tên file có dạng <tên file>.<đuôi>, đuôi có thể là php, html, htm, aspx, jsp,… nhưng mình chỉ liệt kê 5 thằng trên. Do vậy tên file sẽ có regex pattern là [\\w\\-]+\\.(php|html|htm|jsp|aspx).
	Nhưng do có nhiều URL ẩn đi tên file để tránh lộ thông tin, nên gom pattern thành 1 group và thêm ? vào phía sau, trở thành ([\\w\\-_]+\\.(php|html|htm|jsp|aspx))?

	- Biến: VD: ?id=6 hay ?cat_name=lap_trinh&cat_id=4
	+ Đầu tiên ta phải có kí tự ? ở đầu
	+ Kế tiếp ta sẽ có dạng <tên biến>=<giá trị>, vì vậy regex pattern sẽ là [\\w\\-]+=[\\w\\-]+, ngoài ra ta còn phải thêm dấu ? phía sau, thành ([\\w\\-]+=[\\w\\-]+)?
	+ Nếu URL có nhiều biến, ta phải thêm kí tự & giữa các biến, vì vậy regex pattern sẽ là (&([\\w\\-]+=[\\w\\-]+))* (dấu * để biểu thị rằng biến có thể có nhiều hơn)
	+ Và cuối cùng, ta cần đặt 1 dấu ? cho toàn bộ regex pattern biến, để cho biết rằng phần biến có thể có hoặc không.

	*/
	system("pause");
	return 0;
}