#include"GameFlow.h"
#include<ctype.h>
void GameFlow::set_variables()
{
	temp_hand = "";
	 num = "";
	 v.clear();
}

void GameFlow :: GameStart(std::string Hand)
{
	set_variables();
	set_hand(Hand);
	int j = 0, k = 0;;
	for (int i = 0; i < Hand.size(); i++)
	{
		/*if ((temp_hand.at(i) <= 'A' && temp_hand.at(i) >= 'Z') || (temp_hand.at(i) <= 'a' && temp_hand.at(i) >= 'z'))
		{
			temp_hand.at(j) = temp_hand.at(i);
			j++;
		}*/
		if (isalpha(hand.at(i)))
		{
			temp_hand = temp_hand + hand.at(i);
			num = num + " ";
		}
		else
		{
			num = num + hand.at(i);
		}
	}
	num = num + " ";
	std::string temp;
	
	for (int i = 1; i < num.size(); i++)
	{
		if (!isspace(num.at(i)))
		{
			temp = temp+num.at(i);
		}
		else
		{
			v.push_back(atoi(temp.c_str()));
			temp = "";
		}	
	}
	std::cout<< "\n";
	hand_result();
}

bool GameFlow::check_card_Hand()
{
	char card_shape = temp_hand.at(0);
	bool b = false;
	for (int i = 0; i < temp_hand.size(); i++)
	{
		if (card_shape != temp_hand.at(i))
		{
			return false;
		}
		else
		{
			b = true;
		}
	}
	return b;
}

bool GameFlow::flush()
{
	bool b = false;
	for (int i = 0; i < v.size()-1; i++)
	{
		if (v.at(i) - v.at(i + 1) == 1)
		{
			b = true;
		}
		else
			return false;
	}
	return b;
}

int GameFlow::samekind()
{
	int count1 = 0, high = v.at(0);
	for (int i = 0; i < v.size(); i++)
	{
		int count = 0;
		if (high < v.at(i))
		{
			high = v.at(i);
		}
		for (int j = 0; j < v.size(); j++)
		{
			if (v.at(i) == v.at(j))
			{
				count++;
			}
		}
		if (count == 5)
		{
			std::cout << "Five-of-a-kind " << hand << "\n";
			return 0;
		}
		else if (count == 4)
		{
			std::cout << "Four-of-a-kind " << hand << "\n";
			return 0;
		}
		else if (count == 3)
		{
			if ((v.at(0) == v.at(1) && v.at(1) == v.at(2) && v.at(3) == v.at(4)) || (v.at(0) == v.at(1) && v.at(2) == v.at(3) && v.at(3) == v.at(4)))
			{
				std::cout << "Full House " << hand << "\n";
				return 0;
			}
			else
			{
				std::cout << "Three-of-a-kind " << hand << "\n";
				return 0;
			}
		}
		if (count == 2)
		{
			count1++;
		}
	}
	if (count1 == 4)
	{
		std::cout << "Two Pair  " << hand << "\n";
		return 0;
	}
	else if (count1 == 2)
	{
		std::cout << "One  Pair  " << hand << "\n";
		return 0;
	}
	else
	{
		std::cout << "HighCard  " << hand << "\n";
		return 0;
	}
}	

int GameFlow::hand_result()
{
	int result = 0;
	if (check_card_Hand())
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (v.at(i) == Royal_flush.at(i))
			{
				result = 1;
			}
			else
			{
				result = 0;
				break;
			}
		}
		if (result == 1 && check_card_Hand())
		{
			std::cout << "Royal Flush " << hand << "\n";
			return 0;
		}
	}
	if (check_card_Hand() && flush())
	{
		std::cout << "Straight Flush " << hand << "\n";
		return 0;
	}
	if (check_card_Hand() && !flush())
	{
		std::cout << " Flush " << hand << "\n";
		return 0;
	}
	if (flush())
	{
		std::cout << " Straight " << hand << "\n";
		return 0;
	}
	samekind();

}
