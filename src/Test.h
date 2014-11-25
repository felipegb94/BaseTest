

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
	}
};


