#include "iostream"
using namespace std;

int main()
{
	int grade1;
	cout << "请输入小明第一次考试的成绩：" << endl;
	cin >> grade1;
	int grade2;
	cout << "请输入小明第二次考试的成绩：" << endl;
	cin >> grade2;
	cout << "对小明的考试成绩进行判断，结果是：" << (grade1 < grade2 ? "买糖" : "不买糖") << endl;
	return 0;
}

