#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class scorer
{
private:
	float score;
	int max;
	int qs_answered;
public:
	scorer(int m)
	{
		score = 0;
		max = m;
		qs_answered = 0;
	}
	
	void check(int c, int a)
	{
		if(c == a) inc_score();
		return;
	}

	float get_score() { return score; }
	void inc_score() { score++; }
	float calc_final() { return ((score / max) * 100);}
	void inc_qs() { qs_answered++; }
	int get_qs_total() { return qs_answered; }
	void reset() 
	{
		score = 0;
		max = 0;
		qs_answered = 0;
	}
};
