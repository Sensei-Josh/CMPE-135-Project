#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class scorer
{
private:
	float score;
	int max;
public:
	scorer(int m)
	{
		score = 0;
		max = m;
	}

	float get_score() { return score; }
	void inc_score() { score++; }
	float calc_final() { return ((score / max) * 100); }
};