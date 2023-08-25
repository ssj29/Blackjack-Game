#pragma once
#include"FileRead.h"

class GameFlow {
public:
	std::string temp_hand="", hand="";
	std::string num="";
	std::vector<int> v;
	int samekind();
	void GameStart(std::string);
	bool check_card_Hand();
	int hand_result();
	bool flush();
	void set_variables();
	
	void set_hand(std::string hand1)
	{
		hand = hand1;
	}
	
private:
	std::vector<int> Royal_flush = {13,12,11,10,1};

};