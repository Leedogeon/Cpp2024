#include "Quad.h"


int main()
{
	Quad* qd = new Quad;
	qd->AddData(1, 3, 100);
	qd->AddData(2, 3, 106);
	qd->AddData(3, 6, 120);
	qd->AddData(6, 1, 110);
	qd->AddData(1, 255, 111);
	qd->AddData(2, 254, 121);
	qd->AddData(2, 255, 127);

	qd->FindAll();
	qd->PrintAll(qd->rootNode);

}