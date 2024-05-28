#include "RBT.h"

int main()
{
    RBT rbt;
    
    rbt.AddNode(20);
    rbt.Remove(20);
    rbt.AddNode(15);
    rbt.AddNode(3);
    rbt.AddNode(12);
    rbt.AddNode(5);
    rbt.AddNode(11);
    rbt.AddNode(6);
    rbt.AddNode(40);
    rbt.AddNode(25);
    rbt.AddNode(18);
    rbt.AddNode(17);
    rbt.AddNode(13);

    rbt.Print(rbt.rootNode);
    //cout << endl;
    //rbt.Remove(3);
    //rbt.Print(rbt.rootNode);
    //cout << endl;
    //rbt.Remove(12);
    //rbt.Print(rbt.rootNode);
    //cout << endl;
    

}