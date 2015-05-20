#include "NewBaseTest.h"

class NewSampleTest : public NewBaseTest{
public:
  NewSampleTest(const std::string& testName, const std::string& testProjectName)
  : NewBaseTest(testName, testProjectName),
    m_execTime(-1)
  {
    std::cout << "Constructing Derived Test" << std::endl;
  }
  ~NewSampleTest() {}
  
  virtual bool execute();
  virtual double getExecutionTime() const { return m_execTime; }

private:
  double m_execTime;
};

bool NewSampleTest::execute()
{
  // YOUR TEST GOES HERE.
  std::cout << "Test is being executed" << std::endl;
  std::vector<double> doubleVec;
  doubleVec.push_back(2.2);
  doubleVec.push_back(3.12);
  doubleVec.push_back(12);

  /* The metric are the values you want to measure in the test
   * and eventually want to store in the database. This can be:
   * - Runtimes. Example: How long it takes to update all forces.
   * - Average values.
   * - Etc..
   * Note that the metric name (first argument) always has to be a string, but 
   * the metric value can be anything (string, double, int, boolean or vectors).
   * Keep string metrics short (there are still problems when the string is very 
   * long). Also the metric name should be 1 word.
   * 
   * Vector is not supported for the time being. I don't see a need yet for it.
   */ 
  addMetric("DoubleMetricKey1", 1.31234);
  addMetric("DoubleMetricKey2", 2.131);
  addMetric("IntMetricKey", 12);
  addMetric("StringMetricKey", "String Metric Velue"); 
  //addMetric("VectorMetricKey", doubleVec); //Vector needs to be composed of doubles.
  addMetric("BooleanMetricKey", true);
  addMetric("Uint64", (uint64_t)(55555555555));

  // The test should have some way to know if it passed or failed.
  // Return true or false.
  bool testPassed = true;

  // Cache the execution time. 
  m_execTime = 10.0;

  return testPassed;

}

int main(int argc, char *argv[]) {

  // To construct a test you need to provide the name of your test
  // and the name of the project it is under. By project name it can
  // be Chrono, Chrono Parallel, SPIKE, etc.
  NewSampleTest t("NewSampleTestName", "sampleProjectName");
  t.print();  // optional
  t.run();

  // Object o;
  // Object o2;

  // o.AddMember("DoubleKey", 23.23);
  // o.AddMember("DoubleKey", 23);
  // o.AddMember("BoolKey1", true);
  // o.AddMember("BoolKey2", false);

  // std::cout << o.GetObject() << std::endl;

  // o2.AddMember("StringKey", "HELLOWORLD");
  // // We want to send a reference to object here!  std::cout << o.GetObject() << std::endl;
  // o2.AddMember("EmbedObject", o);

  // o2.AddMember("BoolKey2", false);
  // std::cout << o2.GetObject() << std::endl;



  return 0;
}
