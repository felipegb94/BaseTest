
#include "Test.h"

int Test::execute(int argc, char *argv[]){

	/* test goes here. */ 
	cout << "Test is being executed" << endl;
	runtimes.push_back("Measure 1");
	runtimes.push_back("Measure 2");
	runtimeValues.push_back(1.31234);
	runtimeValues.push_back(2.131);

	return 0; 
	
}

int main(int argc, char *argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Test t("testName","chrono");
	t.print();
	t.execute(argc, argv);
	t.generateJson();
	t.saveJson();

	return 0;
}
