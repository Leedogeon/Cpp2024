#include "GameRoom.h"

bool GameRoom::AddUser(USER& userInfo)
{
    listUsers.push_back(userInfo);
    return true;
}

bool GameRoom::DelUser(string name)
{
    if (listUsers.empty()) return false;
    list<USER>::iterator it = listUsers.begin();
    for (auto nick : listUsers)
    {

        if (nick.userName == name)
        {
           listUsers.erase(it);
           
           return true;
        }
        it++;
    }
    return true;
}

bool GameRoom::IsEmpty()
{
    if (listUsers.empty()) return true;
    return false;
}

bool GameRoom::IsFull()
{
    if (listUsers.size() == MAXUSER) return true;
    return false;
}

USER& GameRoom::GetUserInfo(string name)
{
    // TODO: insert return statement here
    
    for (auto nick : listUsers)
    {
        if (nick.userName == name)
        {
            cout << "name : " << nick.userName << endl;
            cout << "level : " << nick.level << endl;
            cout << "money : " << nick.money << endl;
            return nick;
        }
    }
    USER res;
    return res;
}

USER& GameRoom::GetUserInfo(int index)
{
    // TODO: insert return statement here
    int count = 0;
    for (auto nick : listUsers)
    {
        if (count == index)
        {
            cout << "name : " << nick.userName << endl;
            cout << "level : " << nick.level << endl;
            cout << "money : " << nick.money << endl;
            return nick;
        }

        count++;
    }
    USER res;
    return res;
}

USER& GameRoom::GetMasterUserInfo()
{
    return listUsers.front();
}

USER& GameRoom::GetLastUserInfo()
{
    return listUsers.back();
}

bool GameRoom::BanUser(int index)
{
    int count = 0;
    list<USER>::iterator it = listUsers.begin();
    for (auto nick : listUsers)
    {
        if (count == index)
        {
            listUsers.erase(it);
            return true;
        }
        it++;
        count++;
    }
    return false;
}

void GameRoom::Clear()
{
    listUsers.clear();
}

int GameRoom::Count()
{
    return listUsers.size();
}

