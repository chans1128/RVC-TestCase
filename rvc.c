#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "rvc.h"

bool FrontSensorInput = false;
bool RightSensorInput = false;
bool LeftSensorInput = false;
bool DustSensorInput = false;

char CleanerInterface(char CleanerCommand);
char MotorInterface(char MotorCommand);

//1
bool FrontSensorInterface()
{
	// 프론트 센서의 값을 읽어 반환합니다.
	return FrontSensorInput;
}

//2
bool RightSensorInterface()
{
	// 오른쪽 센서의 값을 읽어 반환합니다.
	return RightSensorInput;
}

//3
bool LeftSensorInterface()
{
	// 왼쪽 센서의 값을 읽어 반환합니다.
	return LeftSensorInput;
}

//4
bool DustSensorInterface()
{
	// 먼지 센서의 값을 읽어 반환합니다.
	return DustSensorInput;
}

//5
bool *DetermineObstacleLocation()
{
	bool ObstacleLocation[3] = {false, false, false}; // 전방, 좌측, 우측
	
	if (FrontSensorInterface())
	{
		printf("Obstacle Location: Front\n");
		ObstacleLocation[0] = true;
	}
	if (LeftSensorInterface())
	{
		printf("Obstacle Location: Left\n");
		ObstacleLocation[1] = true;
	}
	if (RightSensorInterface())
	{
		printf("Obstacle Location: Right\n");
		ObstacleLocation[2] = true;
	}
	return ObstacleLocation;
}

//6
bool DetermineDustExistence()
{
	if (DustSensorInterface())
	{
		return true;
	}
	return false;
}

//7
char MoveForward(bool Enable)
{
	if(Enable) {
		("MoveForward : Motor 전달\n");
		return MotorInterface('F');
	}else{
		return MotorInterface('S');
	}
}

//8
char TurnLeft()
{
	printf("Turn Left : Motor 전달\n");
	return MotorInterface('L');
}

//9
char TurnRight()
{
	printf("Turn Right : Motor 전달\n");
	return MotorInterface('R');
}

//10
char TurnBack()
{
	printf("Turn Back : Motor 전달\n");
	return MotorInterface('B');
}

//11
char PowerUp()
{
	printf("Power Up : Cleaner 전달\n");
	return CleanerInterface('U');
}

//12
char Cleaner(bool On)
{
	if (On)
	{
		printf("Turn on : Cleaner 전달\n");
		return CleanerInterface('O');
	}
	else
	{
		printf("Turn off : Cleaner 전달\n");
		return CleanerInterface('F');
	}
}

//13
char CleanerInterface(char CleanerCommand)
{
	switch (CleanerCommand)
	{
		case 'O' :
			//Cleaner On 작동
			printf("On Cleaner\n");
			return CleanerCommand;
		case 'F' :
			//Cleaner OFf 작동
			printf("Off Cleaner\n");
			return CleanerCommand;
		case 'U' :
			//Cleaner Power Up 작동
			return CleanerCommand;
		default:
			return 'E';
	}
}

//14
char MotorInterface(char MotorCommand)
{
	switch (MotorCommand)
	{
		case 'F':
			//모터 '앞으로 전진' 작동
			printf("Move Forward\n");
			return MotorCommand;
		case 'L':
			//Tick*5동안 왼쪽으로 회전 작동
			printf("Turn Left\n");
			return MotorCommand;
		case 'R':
			//Tick*5동안 오른쪽으로 회전 작동
			printf("Turn Right\n");
			return MotorCommand;
		case 'B':
			//Tick*10동안 왼쪽으로 회전 작동해서 180도 돌기
			printf("Turn Back\n");
			return MotorCommand;
		case 'S' :
			//Motor 중지
			printf("Motor Disable\n");
			return MotorCommand;
		default:
			return 'E';
	}
}
