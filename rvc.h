#ifndef HEADER_H
# define HEADER_H

extern bool FrontSensorInput;
extern bool RightSensorInput;
extern bool LeftSensorInput;
extern bool DustSensorInput;

void CleanerInterface(char CleanerCommand);
void MotorInterface(char MotorCommand);

bool FrontSensorInterface();
bool RightSensorInterface();
bool LeftSensorInterface();
bool DustSensorInterface();

bool *DetermineObstacleLocation();
bool DetermineDustExistence();

void MoveForward(bool Enable);
void TurnLeft();
void TurnBack();
void PowerUp();
void Cleaner(bool On);

void activateRVC();

#endif
