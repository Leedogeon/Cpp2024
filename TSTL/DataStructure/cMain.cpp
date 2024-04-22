#include<Windows.h>
#include "Stack.h"
using namespace std;


int main()
{	
	Stack<int> stk;
	Stack<float> stk1;
	stk.Push(10);
	stk1.Push(1.1);
	stk.Check();
	stk1.Check();
	return 0;
}