/*
* BaseTest.h
*
*  Created on: Nov 23, 2014
*      Author: felipegb94
*/


//   Better yet:
//     - initialize JSON document in constructor
//     - add a collection of addMetric functions, each taking a value of different types
//     - a function addMetric directly appends to the JSON document
//     - with this, we can have values of any (supported) type
//     - we do not need to cache the metric key-value pairs



#ifndef BaseTest_H_
#define BaseTest_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/rapidjson/document.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/prettywriter.h"


class BaseTest {

public:

  /// Constructor: Every test has to have a name and an associated project to it.
  BaseTest(const std::string& testName, const std::string& testProjectName)
  : m_name(testName),
    m_projectName(testProjectName),
    m_passed(false)
  {}

  virtual ~BaseTest() {}

  /// Main function for running the test
  void run() {
    m_passed = execute();
    generateJSON();
    saveJSON();
  }

  /// Add a test-specific metric (a key-value pair)
  void addMetric(const std::string& metricName,
                 double             metricValue) {
    m_metricKeys.push_back(metricName);
    m_metricValues.push_back(metricValue);
  }

  /*
  void addMetric(const std::string& metricName,
                 int                metricValue) {
    // append to JSON document
  }

  void addMetric(const std::string& metricName,
                 const std::string& metricValue) {
    // append to JSON document
  }
  */

  /// Contains Test. Returns if test passed or failed
  virtual bool execute() = 0;

  /// Return total execution time for this test.
  virtual double getExecutionTime() const = 0;

  /// Print
  void print() {
    std::cout << "Test Information: " << std::endl;
    std::cout << "Test Name =  " << m_name << std::endl;
    std::cout << "Project Name = " << m_projectName << std::endl;
  };

private:

  std::string m_name;        ///< Name of test
  std::string m_projectName; ///< Name of the project: e.g: chrono, chronoRender, etc.
  bool        m_passed;      ///< Did the test pass or fail?

  /// Metrics that are being tested (key-value pairs)
  std::vector<std::string> m_metricKeys;   ///< Name of metric
  std::vector<double>      m_metricValues; ///< Value of metricKeys

  rapidjson::Document      m_testJson;     ///< JSON output of the test


  /// This function generate a json object and populates it.
  void generateJson() {

    // Initialize JSON object
    m_testJson.SetObject();
    rapidjson::Document::AllocatorType& allocator = m_testJson.GetAllocator();

    rapidjson::Value jsonName;
    rapidjson::Value jsonProject;
    rapidjson::Value jsonPassed;
    rapidjson::Value jsonMetricKeys(rapidjson::kArrayType);
    rapidjson::Value jsonMetricValues(rapidjson::kArrayType);

    // Set Values to json elements
    jsonName.SetString(m_name.c_str());
    jsonProject.SetString(m_projectName.c_str());
    jsonPassed.SetBool(m_passed);

    for (vector<string>::iterator itr = m_metricKeys.begin(); itr != m_metricKeys.end(); ++itr){
      jsonMetricKeys.PushBack(itr->c_str(), allocator);
    }
    for (vector<double>::iterator itr = m_metricValues.begin(); itr != m_metricValues.end(); ++itr){
      jsonMetricValues.PushBack(*itr, allocator);
    }

    // Add values to JSON File
    TestJson.AddMember("name", jsonName, allocator);
    TestJson.AddMember("project_name", jsonProject, allocator);
    TestJson.AddMember("passed", jsonPassed, allocator);
    TestJson.AddMember("metric_keys", jsonMetricKeys, allocator);
    TestJson.AddMember("metric_values", jsonMetricValues, allocator);

  }

  /// This function writes the json object to a file
  void saveJson() {

    std::string filename = m_name + ".json";

    // Write Json to file
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    TestJson.Accept(writer);

    std::string jsonString = strbuf.GetString();
    std::ofstream dataFile(filename);

    if (dataFile.is_open()) {
      dataFile << jsonString;
      dataFile.close();
    }
    else
      std::cout << "Unable to open file" << std::endl;
  }

};



#endif // BaseTest_H_
