#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include "rvc.h"

// Test case 1.1
void test_FrontSensorInterface_NoObstacle(void) {
	FrontSensorInput = false;
	CU_ASSERT_FALSE(FrontSensorInterface());
}
// Test case 1.2
void test_FrontSensorInterface_ObstaclePresent(void) {
	FrontSensorInput = true;
	CU_ASSERT_TRUE(FrontSensorInterface());
}
// Test case 1.3
void test_RightSensorInterface_NoObstacle(void) {
	RightSensorInput = false;
	CU_ASSERT_FALSE(RightSensorInterface());
}
// Test case 1.4
void test_RightSensorInterface_ObstaclePresent(void) {
	RightSensorInput = true;
	CU_ASSERT_TRUE(RightSensorInterface());
}
// Test case 1.5
void test_LeftSensorInterface_NoObstacle(void) {
	LeftSensorInput = false;
	CU_ASSERT_FALSE(LeftSensorInterface());
}
// Test case 1.6
void test_LeftSensorInterface_ObstaclePresent(void) {
	LeftSensorInput = true;
	CU_ASSERT_TRUE(LeftSensorInterface());
}
// Test case 1.7
void test_DustSensorInterface_NoDust(void) {
	DustSensorInput = false;
	CU_ASSERT_FALSE(DustSensorInterface());
}
// Test case 1.8
void test_DustSensorInterface_DustPresent(void) {
	DustSensorInput = true;
	CU_ASSERT_TRUE(DustSensorInterface());
}

// Test case 2.1
void test_DetermineObstacleLocation(void) {
	FrontSensorInput = true;
	LeftSensorInput = true;
	RightSensorInput = false;

	bool *result = DetermineObstacleLocation();
	if (result == NULL) {
		return;
	}
	CU_ASSERT_TRUE(result[0]);
	CU_ASSERT_TRUE(result[1]);
	CU_ASSERT_FALSE(result[2]);
	free(result);
}

// Test case 3.1
void test_DetermineDustExistence_true(void) {
	DustSensorInput = true;
	CU_ASSERT_TRUE(DetermineDustExistence());
}
// Test case 3.2
void test_DetermineDustExistence_false(void) {
	DustSensorInput = false;
	CU_ASSERT_FALSE(DetermineDustExistence());
}

// Test case 4.1
void test_MoveForward_enable(void) {
	CU_ASSERT_EQUAL(MoveForward(true), 'F');
}
// Test case 4.2
void test_MoveForward_disable(void) {
	CU_ASSERT_EQUAL(MoveForward(false), 'S');
}
// Test case 4.3
void test_TurnLeft(void) {
	CU_ASSERT_EQUAL(TurnLeft(), 'L');
}
// Test case 4.4
void test_TurnRight(void) {
	CU_ASSERT_EQUAL(TurnRight(), 'R');
}
// Test case 4.5
void test_TurnBack(void) {
	CU_ASSERT_EQUAL(TurnBack(), 'B');
}

// Test case 5.1
void test_PowerUp(void) {
	CU_ASSERT_EQUAL(PowerUp(), 'U');
}

// Test case 6.1
void test_Cleaner_On(void) {
	CU_ASSERT_TRUE(Cleaner(true));
}
// Test case 6.2
void test_Cleaner_Off(void) {
	CU_ASSERT_TRUE(Cleaner(false));
}

// Test case 7.1
void test_CleanerInterface_TurnOn(void) {
	CU_ASSERT_EQUAL(CleanerInterface('O'), 'O');
}
// Test case 7.2
void test_CleanerInterface_TurnOff(void) {
	CU_ASSERT_EQUAL(CleanerInterface('F'), 'F');
}
// Test case 7.3
void test_CleanerInterface_PowerUp(void) {
	CU_ASSERT_EQUAL(CleanerInterface('U'), 'U');
}
// Test case 7.4
void test_CleanerInterface_Exception(void) {
	CU_ASSERT_EQUAL(CleanerInterface('A'), 'E');
}
// Test case 7.5
void test_MotorInterface_MoveForward(void) {
	CU_ASSERT_EQUAL(MotorInterface('F'), 'F');
}
// Test case 7.6
void test_MotorInterface_TurnLeft(void) {
	CU_ASSERT_EQUAL(MotorInterface('L'), 'L');
}
// Test case 7.7
void test_MotorInterface_TurnRight(void) {
	CU_ASSERT_EQUAL(MotorInterface('R'), 'R');
}
// Test case 7.8
void test_MotorInterface_TurnBack(void) {
	CU_ASSERT_EQUAL(MotorInterface('B'), 'B');
}
// Test case 7.9
void test_MotorInterface_StopMotor(void) {
	MotorInterface('S');
	CU_ASSERT_EQUAL(MotorInterface('S'), 'S');
}
// Test case 7.10
void test_MotorInterface_Exception(void) {
	CU_ASSERT_EQUAL(MotorInterface('A'), 'E');
}

int main() {
	CU_initialize_registry();

	CU_pSuite suite = CU_add_suite("Suite1: Front/Right/Left/Dust Sensor Interface", NULL, NULL);
	CU_add_test(suite, "Test case 1.1", test_FrontSensorInterface_NoObstacle);
	CU_add_test(suite, "Test case 1.2", test_FrontSensorInterface_ObstaclePresent);
	CU_add_test(suite, "Test case 1.3", test_RightSensorInterface_NoObstacle);
	CU_add_test(suite, "Test case 1.4", test_RightSensorInterface_ObstaclePresent);
	CU_add_test(suite, "Test case 1.5", test_LeftSensorInterface_NoObstacle);
	CU_add_test(suite, "Test case 1.6", test_LeftSensorInterface_ObstaclePresent);
	CU_add_test(suite, "Test case 1.7", test_DustSensorInterface_NoDust);
	CU_add_test(suite, "Test case 1.8", test_DustSensorInterface_DustPresent);
	printf("\n");

	CU_pSuite suite2 = CU_add_suite("Suite2: DetermineObstacleLocation", NULL, NULL);
	CU_add_test(suite2, "Test case 2.1", test_DetermineObstacleLocation);
	printf("\n");
	
	CU_pSuite suite3 = CU_add_suite("Suite3: DetermineDustExistence", NULL, NULL);
	CU_add_test(suite3, "Test case 3.1", test_DetermineDustExistence_true);
	CU_add_test(suite3, "Test case 3.2", test_DetermineDustExistence_false);
	printf("\n");
	
	CU_pSuite suite4 = CU_add_suite("Suite4: MoveForward/TurnRight/TurnLeft/TurnBack", NULL, NULL);
	CU_add_test(suite4, "Test case 4.1", test_MoveForward_enable);
	CU_add_test(suite4, "Test case 4.2", test_MoveForward_disable);
	CU_add_test(suite4, "Test case 4.3", test_TurnLeft);
	CU_add_test(suite4, "Test case 4.4", test_TurnRight);
	CU_add_test(suite4, "Test case 4.5", test_TurnBack);
	printf("\n");
	
	CU_pSuite suite5 = CU_add_suite("Suite5: PowerUp", NULL, NULL);
	CU_add_test(suite5, "Test case 5.1", test_PowerUp);
	printf("\n");

	CU_pSuite suite6 = CU_add_suite("Suite6: Cleaner", NULL, NULL);
	CU_add_test(suite6, "Test case 6.1", test_Cleaner_On);
	CU_add_test(suite6, "Test case 6.2", test_Cleaner_Off);
	printf("\n");

	CU_pSuite suite7 = CU_add_suite("Suite7: CleanerInterface/MotorInterface", NULL, NULL);
	CU_add_test(suite7, "Test case 7.1", test_CleanerInterface_TurnOn);
	CU_add_test(suite7, "Test case 7.2", test_CleanerInterface_TurnOff);
	CU_add_test(suite7, "Test case 7.3", test_CleanerInterface_PowerUp);
	CU_add_test(suite7, "Test case 7.4", test_CleanerInterface_Exception);
	CU_add_test(suite7, "Test case 7.5", test_MotorInterface_MoveForward);
	CU_add_test(suite7, "Test case 7.6", test_MotorInterface_TurnLeft);
	CU_add_test(suite7, "Test case 7.7", test_MotorInterface_TurnRight);
	CU_add_test(suite7, "Test case 7.8", test_MotorInterface_TurnBack);
	CU_add_test(suite7, "Test case 7.9", test_MotorInterface_StopMotor);
	CU_add_test(suite7, "Test case 7.10", test_MotorInterface_Exception);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}
