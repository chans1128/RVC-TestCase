#include <stdbool.h>
#include <stdio.h>
#include "rvc.h"

bool FrontSensorInput = false;
bool RightSensorInput = false;
bool LeftSensorInput = false;
bool DustSensorInput = false;

void CleanerInterface(char CleanerCommand);
void MotorInterface(char MotorCommand);

bool FrontSensorInterface()
{
    // 프론트 센서의 값을 읽어 반환합니다.
    return FrontSensorInput;
}
bool RightSensorInterface()
{
    // 오른쪽 센서의 값을 읽어 반환합니다.
    return RightSensorInput;
}
bool LeftSensorInterface()
{
    // 왼쪽 센서의 값을 읽어 반환합니다.
    return LeftSensorInput;
}
bool DustSensorInterface()
{
    // 먼지 센서의 값을 읽어 반환합니다.
    return DustSensorInput;
}

bool *DetermineObstacleLocation()
{
    bool ObstacleLocation[3] = {false, false, false};
    if (FrontSensorInterface())
    {
        printf("Obstacle Location: Front\n");
        ObstacleLocation[0] = true;
    }
    if (RightSensorInterface())
    {
        printf("Obstacle Location: Right\n");
        ObstacleLocation[1] = true;
    }
    if (LeftSensorInterface())
    {
        printf("Obstacle Location: Left\n");
        ObstacleLocation[2] = true;
    }
    return ObstacleLocation;
}

bool DetermineDustExistence()
{
    if (DustSensorInterface())
    {
        return true;
    }
    return false;
}
void MoveForward(bool Enable)
{
	if(Enable) {
		("MoveForward : Motor 전달\n");
		MotorInterface('F');
	}else{
		MotorInterface('S');
	}
}

void TurnLeft()
{
	printf("Turn Left : Motor 전달\n");
	MotorInterface('L');
}

void TurnRight()
{
    printf("Turn Right : Motor 전달\n");
	MotorInterface('R');
}

void TurnBack()
{
    printf("Turn Back : Motor 전달\n");
	MotorInterface('B');
}

void PowerUp()
{
    printf("Power Up : Cleaner 전달\n");
	CleanerInterface('U');
}

void Cleaner(bool On)
{
    if (On)
    {
        printf("Turn on : Cleaner 전달r\n");
		CleanerInterface('O');
    }
    else
    {
        printf("Turn off : Cleaner 전달\n");
		CleanerInterface('F');
    }
}

void CleanerInterface(char CleanerCommand)
{
    switch (CleanerCommand)
    {
		case 'O' :
			//Cleaner On 작동
        	printf("On Cleaner\n");
			break;
		case 'F' :
			//Cleaner OFf 작동
        	printf("Off Cleaner\n");
			break;
		case 'U' :
			//Cleaner Power Up 작동
			printf("Poer Up Cleaner\n");
    }
}

void MotorInterface(char MotorCommand)
{
    switch (MotorCommand)
    {
    case 'F':
		//모터 '앞으로 전진' 작동
		printf("Move Forward\n");
        break;
    case 'L':
		//Tick*5동안 왼쪽으로 회전 작동
		printf("Turn Left\n");
        break;
    case 'R':
		//Tick*5동안 오른쪽으로 회전 작동
		printf("Turn Right\n");
        break;
    case 'B':
		//Tick*10동안 왼쪽으로 회전 작동해서 180도 돌기
		printf("Turn Back\n");
        break;
	case 'S' :
		//Motor 중지
		printf("Motor Disable\n");
		break;
    }
}

void activateRVC() {
	
	while(true){
		bool * location = DetermineObstacleLocation();
		bool dustEx = DetermineDustExistence();
		bool enable = true;
		bool disable = false;

		if (location[0] && !location[1]){ //Turn Left 상태 변화
			MoveForward(disable);
			Cleaner(disable);
			TurnLeft();
			MoveForward(enable);
			Cleaner(enable);
		} else if(location[0] && location[1] && !location[2]){
			MoveForward(disable);
			Cleaner(disable);
			TurnRight();
			MoveForward(enable);
			Cleaner(enable);
		} else if(location[0] && location[1] && location[2]){
			MoveForward(disable);
			Cleaner(disable);
			TurnBack();
			MoveForward(enable);
			Cleaner(enable);
		}

		if(dustEx) {
			PowerUp();
		}else {
			Cleaner(enable);
		}
	}

}
