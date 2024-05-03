#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define MAXUSER 6

using namespace std;

typedef struct UserInfo
{
	string userName;
	int level;
	int money;
}USER;

//방에는 최대 6명까지 들어갈수 있음
//방에 들어온 유저 순서중 가장 먼저 들어온 유저가 방장이 됨

class GameRoom
{
private:
	//골라서 사용하세요.
	vector<USER> vectorUsers;
	list<USER> listUsers;
	map<string, USER> mapUsers;
public:
	//방에 유저 추가
	bool AddUser(USER& userInfo);
	//방에 있는 유저 삭제(이름으로) 만약에 방장이 나가면 새로운 방장 지정
	bool DelUser(string name);
	//방에 유저가 있는지 없는지 확인
	bool IsEmpty();
	//방이 풀방 인지 아닌지
	bool IsFull();
	//선택된(이름) 유저 정보 확인
	USER& GetUserInfo(string name);
	//지정된(index) 유저 정보 확인
	USER& GetUserInfo(int index);
	//방장 정보 확인
	USER& GetMasterUserInfo();
	//마지막 입장한 유저 확인
	USER& GetLastUserInfo();
	//특정 순서에 들어온 유저 퇴출
	bool BanUser(int index);
	//모든 유저 정보 삭제
	void Clear();
	//방 인원 체크
	int Count();
};