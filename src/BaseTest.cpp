
#include "BaseTest.h"




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	BaseTest t("testName","chrono");
	t.print();
	t.generateJson();
	t.saveJson();

	return 0;
}
