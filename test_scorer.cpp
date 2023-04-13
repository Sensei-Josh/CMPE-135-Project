#include <iostream>
#include "scorer.h"
using namespace std;

int main()
{
	scorer tally(10);

	cout << "start: " << tally.get_score() << endl;

	tally.inc_score();
	tally.inc_score();
	tally.inc_score();

	cout << "+3: " << tally.get_score() << endl;

	tally.inc_score();
	tally.inc_score();
	tally.inc_score();
	tally.inc_score();

	cout << "+4: " << tally.get_score() << endl;
	cout << "Final score: " << tally.calc_final() << endl;

	return 0;
}