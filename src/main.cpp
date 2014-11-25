
#include "Test.h"


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Test t("testName","chrono");
	t.print();
	t.generateJson();
	t.saveJson();

	return 0;
}
