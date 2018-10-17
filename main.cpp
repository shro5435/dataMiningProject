#include "ElectoralMap.h"
#include "TextUI.h"
#include <time.h>
#include <string>


int main()
{
	//Electoral Map R = new ElectoralMap();
	srand(static_cast<int>(time(0)));
	ElectoralMap &R = ElectoralMap::GetInstance();

	TextUI main;
	main.RouteChoice(R);

	return 0;

}
