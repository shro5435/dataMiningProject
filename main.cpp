//Eric Ha
#include "ElectoralMap.h"
#include "TextUI.h"
#include <time.h>
#include <string>


int main()
{
	srand(static_cast<int>(time(0)));
	ElectoralMap &R = ElectoralMap::GetInstance();

	TextUI main;
	main.RouteChoice(R);

	return 0;

}
