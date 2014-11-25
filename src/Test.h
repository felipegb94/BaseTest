

#include "BaseTest.h"

class Test:public BaseTest{
public:

	Test(string testName, string testProjectName)
		: BaseTest(testName,testProjectName)
	{
		cout << "Constructing Derived Test" << endl;
	}
	~Test(){}

	virtual int execute(int argc, char *argv[]){
		/* test goes here. */ 
		cout << "Test is being executed" << endl;
		runtimes.push_back("Hello");
		runtimes.push_back("Hello2");

		return 0; 
	}
};


