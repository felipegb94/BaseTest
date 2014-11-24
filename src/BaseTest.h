/*
 * BaseTest.h
 *
 *  Created on: Nov 23, 2014
 *      Author: felipegb94
 */

#ifndef BaseTest_H_
#define BaseTest_H_

#include <fstream>
#include <iostream>
#include <string>
#include "/Users/felipegb94/helper_libraries/rapidjson/include/rapidjson/document.h"
#include "/Users/felipegb94/helper_libraries/rapidjson/include/rapidjson/stringbuffer.h"
#include "/Users/felipegb94/helper_libraries/rapidjson/include/rapidjson/prettywriter.h"

using namespace std;


class BaseTest{

public:
	string name; /* Name of test */
	string projectName; /* Name of the project: e.g: chrono, chronoRender, etc. */
	bool passed; /* Did the test pass or fail? */
	rapidjson::Document TestJson;

	BaseTest(string testName, string testProjectName)
		:name(testName),
 		projectName(testProjectName),
 		passed(false)
 	{
 		std::cout << "Contructing Base Test" <<std::endl;
 	}

	virtual ~BaseTest(){};

	/* Print */
	virtual void print(){ 
		cout << "Test Information: " << endl;
		cout << "Test Name =  " << name << endl;
		cout << "Project Name = " << projectName << endl;
	};

	/* Contains Test. Returns if test passed or failed */
	virtual int execute(int argc, char *argv[]){
		return 0;
	} 

	virtual void generateJson(){

		/* Initialize JSON object */
		TestJson.SetObject();
		rapidjson::Document::AllocatorType& allocator = TestJson.GetAllocator();

		rapidjson::Value jsonName;
		rapidjson::Value jsonProject;
		rapidjson::Value jsonPassed;

		/* Set Values to json elements */
		jsonName.SetString(name.c_str());
		jsonProject.SetString(projectName.c_str());
		jsonPassed.SetBool(passed);

		/* Add values to JSON*/
		TestJson.AddMember("name", jsonName, allocator);
		TestJson.AddMember("project_name", jsonProject, allocator);
		TestJson.AddMember("passed", jsonPassed, allocator);
	}

	void saveJson(){

		string filename = name + ".json"; 

		/* Write Json to file */
		rapidjson::StringBuffer strbuf;
		rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
		TestJson.Accept(writer);

		string jsonString = strbuf.GetString();
		ofstream dataFile (filename);

		if (dataFile.is_open()){
			dataFile << jsonString;
			dataFile.close();
   		}
   		else cout << "Unable to open file";
   	}

};




#endif /* BaseTest_H_ */
