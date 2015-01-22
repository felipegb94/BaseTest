#include "BaseTest.h"

class SampleTest : public BaseTest{
public:
  SampleTest(const std::string& testName, const std::string& testProjectName)
  : BaseTest(testName, testProjectName),
    m_execTime(-1)
  {
    std::cout << "Constructing Derived Test" << std::endl;
  }
  ~SampleTest() {}
  
  virtual bool execute();
  virtual double getExecutionTime() const { return m_execTime; }

private:
  double m_execTime;
};

bool SampleTest::execute()
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
   * IMPORTANT: METRIC Key String should be less than 21 characters. For some 
   * reason longer strings fail to get written correctly by rapidjson.
   */ 
  addMetric("DoubleMetricKey1", 1.31234);
  addMetric("DoubleMetricKey2", 2.131);
  addMetric("IntMetricKey", 12);
  addMetric("StringMetricKey", "String Metric Value"); // Strings should be less than 21 chars
  addMetric("VectorMetricKey", doubleVec); //Vector needs to be composed of doubles.
  addMetric("BooleanMetricKey", true);

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
  SampleTest t("sampleTestName", "sampleProjectName");
  t.print();  // optional
  t.run();

  return 0;
}
