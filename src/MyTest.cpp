#include "BaseTest.h"

class Test :public BaseTest{
public:
  Test(const std::string& testName, const std::string& testProjectName)
  : BaseTest(testName, testProjectName),
    m_execTime(-1)
  {
    std::cout << "Constructing Derived Test" << std::endl;
  }
  ~Test() {}
  virtual bool execute();
  virtual double getExecutionTime() const { return m_execTime; }

private:
  double m_execTime;
};

bool Test::execute()
{
  // YOUR TEST GOES HERE.
  cout << "Test is being executed" << endl;

  // The metric are the values you want to measure in the tesy
  // and eventually want to store in the database. This can be:
  // - Runtimes. Example: How long it takes to update all forces.
  // - Average values.
  // - Etc..
  // Note that metricKeys have a 1 to 1 correspondance to metricValues.
  addMetric("Name of metric 1", 1.31234);
  addMetric("Name of metric 2", 2.131);

  // The test should have some way to know if it passed or failed.
  // Return true or false.
  bool testPassed = false;

  // Cache the execution time
  m_execTime = 10.0;

  return testPassed;

}

int main(int argc, char *argv[]) {

  // To construct a test you need to provide the name of your test
  // and the name of the project it is under. By project name it can
  // be Chrono, Chrono Parallel, SPIKE, etc.
  Test t("sampleTestName", "sampleProjectName");
  t.print();  // optional
  t.run();

  return 0;
}
