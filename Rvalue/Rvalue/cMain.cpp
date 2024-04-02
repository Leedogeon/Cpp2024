#include<iostream>
using namespace std;

static void Test(int&& num)
{
	cout << num << endl;
	num = 12;
	cout << num << endl;
}
int main()
{
	Test(5);
}