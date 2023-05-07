#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

/*
	scorer class responsible for holding game stats
*/

class scorer
{
private:
	float score;	//players score
	int max;	//max possible score
	int qs_answered;//number of questions answered
public:
	scorer(int m)
	{
		score = 0;
		max = m;
		qs_answered = 0;
	}
	
	void check(int c, int a)
	{
		if(c == a) score++;
		return;
	}

	float get_score() { return score; }
	int get_max() { return max; }
	void inc_score() { score++; }
	float calc_final() { return ((score / max) * 100);}
	void inc_qs() { qs_answered++; }
	int get_qs_total() { return qs_answered; }
	void reset() 
	{
		score = 0;
		qs_answered = 0;
	}
};
