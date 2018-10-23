#include "Complex.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

using namespace std;
using namespace CppUnit;

class ComplexNumberTest: public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ComplexNumberTest);
	CPPUNIT_TEST(testAddition);
	//CPPUNIT_TEST(testAddition2);
	CPPUNIT_TEST_SUITE_END();

	public:
	
	protected:
		void testAddition(void);
		//void testAddition2(void);
};

/*void ComplexNumberTest::testAddition2()
{
	Complex c4(2,5);
	Complex c1(1,2); Complex c2(1,2);
	Complex c3 = c1.add(c1,c2);
	
	CPPUNIT_ASSERT(c4 == c3);
}*/

void ComplexNumberTest::testAddition()
{
	Complex c4(2,4);
	Complex c1(1,2); Complex c2(1,2);
	Complex c3 = c1.add(c1, c2);
	cout<<"Real is "<<c3.getReal()<<endl;
	cout<<"Imaginary is "<<c3.getImag()<<endl;

	CPPUNIT_ASSERT(c4 == c3);
}

CPPUNIT_TEST_SUITE_REGISTRATION(ComplexNumberTest);
int main()
{
    //informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;
    
    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);
    
    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);
    
    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);
    
    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();
    
    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();
    
    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;

    return 0;
}
