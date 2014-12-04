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
#include <vector>

#include "../include/rapidjson/document.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/prettywriter.h"

using namespace std;


class BaseTest{

public:
	string name; /* Name of test */
	string projectName; /* Name of the project: e.g: chrono, chronoRender, etc. */
	bool passed; /* Did the test pass or fail? */

	/* Metrics that are being tested. metricKeys and metricValues have 
	   a 1 to 1 correspondance. */
	vector<string> metricKeys; /* Name of metric */
	vector<double> metricValues; /* Value of metricKeys */

	vector<string> parameters; /* Test arguments/parameters */

	rapidjson::Document TestJson; /* Output JSON of the test */

	/* Constructor: Every test has to have a name and an associated project 
	   to it. */ 
	BaseTest(string testName, string testProjectName)
		:name(testName),
 		projectName(testProjectName),
 		passed(false)
 	{
 		cout << "Contructing Base Test" << endl;
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

	/* This function generate a json object and populates it. */
	virtual void generateJson(){

		/* Initialize JSON object */
		TestJson.SetObject();
		rapidjson::Document::AllocatorType& allocator = TestJson.GetAllocator();

		rapidjson::Value jsonName;
		rapidjson::Value jsonProject;
		rapidjson::Value jsonPassed;
		rapidjson::Value jsonMetricKeys(rapidjson::kArrayType);
		rapidjson::Value jsonMetricValues(rapidjson::kArrayType);


		/* Set Values to json elements */
		jsonName.SetString(name.c_str());
		jsonProject.SetString(projectName.c_str());
		jsonPassed.SetBool(passed);

		for (vector<string>::iterator itr = metricKeys.begin(); itr != metricKeys.end(); ++itr){
			jsonMetricKeys.PushBack((*itr).c_str(),allocator);
		}
		for (vector<double>::iterator itr = metricValues.begin(); itr != metricValues.end(); ++itr){
			jsonMetricValues.PushBack(*itr,allocator);
		}

		/* Add values to JSON File*/
		TestJson.AddMember("name", jsonName, allocator);
		TestJson.AddMember("project_name", jsonProject, allocator);
		TestJson.AddMember("passed", jsonPassed, allocator);
		TestJson.AddMember("metric_keys", jsonMetricKeys, allocator);
		TestJson.AddMember("metric_values", jsonMetricValues, allocator);

	}

	/* This function writes the json object to a file */
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
