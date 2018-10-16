#include "ElectoralMap.h"

int main()
{
	//Electoral Map R = new ElectoralMap();
	ElectoralMap &R = ElectoralMap::GetInstance();
	cout<<R;

	Candidate c(1, "John", Party::None);

	cout << c.Stringify() << endl;
	return 0;

}
