#include "iostream"
using namespace std;

int main()
{
	int num = 1;
	int score = 0;
	while(num <= 100)
	{
		score += num;
		num++;
	}
	cout << "从1累加到100的值是：" << score << endl;
	return 0;
}
