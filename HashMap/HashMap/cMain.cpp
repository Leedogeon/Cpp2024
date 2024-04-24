#include "HashMap.h"

int main()
{
	HashMap HM;

	HM.Add(1, 1);
	HM.Add(2, 20);
	HM.Add(2, 30);
	HM.Add(2, 40);
	HM.Add(2, 30);
	HM.Add(2, 30);
	HM.Add(2, 30);
	HM.Add(2, 50);
	HM.Add(2, 30);
	HM.Add(2, 60);
	
	HM.View();
	return 0;
}
