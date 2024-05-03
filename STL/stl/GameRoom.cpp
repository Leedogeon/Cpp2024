#include "GameRoom.h"

bool GameRoom::AddUser(USER& userInfo)
{
    listUsers.push_back(userInfo);
    return true;
}

bool GameRoom::DelUser(string name)
{
    if (listUsers.empty()) return false;
    
    for (auto nick : listUsers)
    {
        nick.userName == name;
    }
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
}

USER& GameRoom::GetUserInfo(int index)
{
    // TODO: insert return statement here
}

USER& GameRoom::GetMasterUserInfo()
{
    // TODO: insert return statement here
}

USER& GameRoom::GetLastUserInfo()
{
    // TODO: insert return statement here
}

bool GameRoom::BanUser(int index)
{
    return false;
}

void GameRoom::Clear()
{
}

int GameRoom::Count()
{
    return listUsers.size();
}

