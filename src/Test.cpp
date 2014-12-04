
#include "Test.h"

int Test::execute(int argc, char *argv[]){

	/* YOUR TEST GOES HERE. */ 
	cout << "Test is being executed" << endl;

	/* The metric are the values you want to measure in the tesy
	and eventually want to store in the database. This can be:
		- Runtimes. Example: How long it takes to update all forces.
		- Average values.
		- Etc..
	Note that metricKeys have a 1 to 1 correspondance to metricValues.
	*/
	this->metricKeys.push_back("Name of Metric 1"); 
	this->metricValues.push_back(1.31234); //Value of metric 1

	this->metricKeys.push_back("Name of Metric 2");
	this->metricValues.push_back(2.131); //Value of metric 1

	/* 
	  The test should have some way to know if it passed or failed.
	  Once this is known, the variable passed from base test should
	  be set to either true or false.
	*/
	bool testPassed = false;
	this->passed = testPassed; // Did the test pass.

	return this->passed; 
	
}

int main(int argc, char *argv[]) {
	
	/* 
		To construct a test you need to provide the name of your test
		and the name of the project it is under. By project name it can
		be Chrono, Chrono Parallel, SPIKE, etc.
	*/
	Test t("sampleTestName","sampleProjectName");
	t.print();
	t.execute(argc, argv); // Execute test
	t.generateJson(); // Compiles all the output in a JSON format.
	t.saveJson(); // Writes the JSON into a file

	return 0;
}
