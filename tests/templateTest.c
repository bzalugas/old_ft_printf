#include "../includes/ft_printf.h"
#include "CuTest.h"

void	xTest(CuTest *tc)
{
	/* void CuAssert(CuTest* tc, char* message, int condition); */
	/* void CuAssertTrue(CuTest* tc, int condition); */
	/* void CuAssertStrEquals(CuTest* tc, char* expected, char* actual); */
	/* void CuAssertIntEquals(CuTest* tc, int expected, int actual); */
	/* void CuAssertPtrEquals(CuTest* tc, void* expected, void* actual); */
	/* void CuAssertPtrNotNull(CuTest* tc, void* pointer); */
}

CuSuite	*intermediaryGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, xTest);
	return (suite);
}
