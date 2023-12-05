#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "rvc.h"

// 테스트 케이스 함수
void testcase1() {

}


int main() {
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("testSuite1", NULL, NULL);

	CU_add_test(suite, "Test case 1", test_case1);
	CU_add_test(suite, "Test case 2", test_case2);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}
