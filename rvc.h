#include <stdbool.h>
#ifndef HEADER_H
#define HEADER_H

extern bool FrontSensorInput;
extern bool RightSensorInput;
extern bool LeftSensorInput;
extern bool DustSensorInput;

char CleanerInterface(char CleanerCommand);
char MotorInterface(char MotorCommand);

bool FrontSensorInterface();
bool RightSensorInterface();
bool LeftSensorInterface();
bool DustSensorInterface();

bool *DetermineObstacleLocation();
bool DetermineDustExistence();

char MoveForward(bool Enable);
char TurnLeft();
char TurnBack();
char PowerUp();
char Cleaner(bool On);

#endif
