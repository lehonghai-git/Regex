#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	string PhoneNumber;
	cout << "Nhap so dien thoai (VN): "; getline(cin, PhoneNumber);

	regex pattern("(\\+84|0)\\d{9,10}");
	if (regex_match(PhoneNumber, pattern))
		cout << "So dien thoai hop le" << endl;
	else
		cout << "So dien thoai khong hop le" << endl;

	/*
	*** Phân tích:
	1. Số điện thoại phần mở đầu có thể là +84 hoặc 0 => Đặt vào group và thêm dấu |
	2. Số điện thoại có thể là 10-11 chữ số nhưng không tính phần mở đầu nên chỉ còn 9-10 chữ số
	*/
	system("pause");
	return 0;
}