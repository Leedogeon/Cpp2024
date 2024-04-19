#include<Windows.h>
#include "Stack.h"
using namespace std;

int main()
{	

	Stack<int> stk;
	stk.Push(10);
	stk.Check();
	
	return 0;
}