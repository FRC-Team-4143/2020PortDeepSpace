#pragma once
#include "controllers/IPositionMultiController.h"
#include <string>

class SwerveModule {
public:

	SwerveModule(IMultiController* driveMotor, IPositionMultiController* steerMotor, std::string configName); 

	void SetGeometry(double x, double y, double maxradius);
	void SetWheelOffset();
	void LoadWheelOffset();
	void SetDriveSpeed(float speed);
	double GetSteerPosition();
	double SetSteerDrive(double x, double y, double twist, bool operatorControl);

private:

	IMultiController* _drive; // speed controller for the drive motor
	IPositionMultiController* _steer; // speed controller for the steer motor
	std::string _configName;

	double _x;
	double _y;
	double _radius;
	double _offset;
	double _steerPosition;
	double _lastPow;
	int _inverse = 1;

	void SetOffset(float offset);
	void SetSteerSetpoint(float setpoint);
};
