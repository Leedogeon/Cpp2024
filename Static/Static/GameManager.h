#pragma once
class GameManager
{
private:
	static GameManager* instance;
public:
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager;
		}

		return instance;
	}
};

