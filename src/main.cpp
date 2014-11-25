
#include "Test.h"


int main(int argc, char *argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Test t("testName","chrono");
	t.print();
	t.execute(argc, argv);
	t.generateJson();
	t.saveJson();

	return 0;
}
