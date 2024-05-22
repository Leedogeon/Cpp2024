#include "star.h"

void star::Start(Node* sNode)
{
    sNode->find = 1;
}

void star::End(Node* fNode)
{
    fNode->find = 3;
}

Node* star::NewNode(int y, int x)
{
    return nullptr;
}

void star::Hole(Node* xNode)
{
    xNode->find = 99;
}

Node* star::FindDis(Node* nNode, Node* fNode)
{
    
    for (int i = -1; i <= 1; i++)
    {

        for (int j = -1; j <= 1; j++)
        {

            if (i == 0 && j == 0) continue;

            if (nNode->x + j < 0 || nNode->y + i < 0) continue;

            if (arr[nNode->y + i][nNode->x + j].find == 3)
            {
                arr[nNode->y + i][nNode->x + j].find = 4;
                return &arr[nNode->y + i][nNode->x + j];
            }

            if (arr[nNode->y + i][nNode->x + j].find != 0) continue;
            


            Node* cNode = &arr[nNode->y + i][nNode->x + j];
            if (abs(nNode->x - j) == 1 && abs(nNode->y - i) == 1)
            {
                Result(cNode, fNode, nNode->move + 14);
            }
            else
                Result(cNode, fNode, nNode->move + 10);
        
            cNode->parent = nNode;


        }
    }

    nNode = qN.top();
    if (nNode->dis == 0)return nNode;
    nNode->find = 1;
    qN.pop();

    return nNode;
}

void star::Result(Node* cNode, Node* fNode, int move)
{
    int resX = abs(cNode->x - fNode->x);
    int resY = abs(cNode->y - fNode->y);

    if (resX >= resY)
        cNode->dis = resY * 14 + (resX - resY) * 10;
    else
        cNode->dis = resX * 14 + (resY - resX) * 10;

    cNode->move = move;


    cNode->res = cNode->move + cNode->dis;
    cNode->find = 2;

    qN.emplace(cNode);
}

void star::eStart(Node* esNode)
{
    esNode->find = 10;
}

star::star()
{
    for (int i = 0; i < MaxY; i++)
    {
        for (int j = 0; j < MaxX; j++)
        {
            arr[i][j].x = j;
            arr[i][j].y = i;
            arr[i][j].find = 0;
            arr[i][j].parent = nullptr;
        }
    }

}

star::~star()
{
}
