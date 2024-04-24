#include "HashMap.h"

int main()
{
	HashMap HM;

	HM.Add(1, 1);
	HM.Add(31, 2);
	HM.Add(11, 3);
	HM.Add(31, 4);

	HM.Add(22, 3);
	HM.Add(32, 4);

	HM.View(1);

}