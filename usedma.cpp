#include <iostream>
#include "dma.h"
int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << shirt << endl << endl;

	cout << balloon << endl << endl;

	cout << map << endl << endl;

	lacksDMA balloon2(balloon);
	cout << balloon2 << endl << endl;

	hasDMA map2;
	map2 = map;
	cout << map2 << endl;
	return 0;
}