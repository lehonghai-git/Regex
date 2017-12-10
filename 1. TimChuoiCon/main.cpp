#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	// Tìm một chuỗi con trong chuỗi cha.
	string source = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book";

	regex pattern("standard");
	bool result = regex_search(source, pattern);
	if (result)
		cout << "Tim thay" << endl;
	else
		cout << "Khong tim thay" << endl;

	system("pause");
	return 0;
}