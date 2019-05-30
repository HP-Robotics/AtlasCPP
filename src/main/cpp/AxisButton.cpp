#include "AxisButton.h"

AxisButton::AxisButton(frc::Joystick *j, int id, std::string n) {
    stick = j;
    num = id;
    name = n;
}

std::string AxisButton::GetName() {
    return name;
}

double AxisButton::GetState() {
    return state;
}

bool AxisButton::Held() {
    return held;
}

bool AxisButton::Changed() {
    return changed;
}

void AxisButton::Update() {
    abutton = stick->GetRawAxis(num);
    if(abutton >= -0.09 || abutton <= 0.09)
        fudgeAxis = 0.0;
    if(abutton > 0.5)
        fudgeAxis = 1.0;
    if(abutton < -0.5)
        fudgeAxis = -1.0;

    if(fudgeAxis != 0 && (fudgeAxis != lastState)  && fudgeAxis != lastAxisTriggered ) {
		state = fudgeAxis;
		changed = true;
		lastAxisTriggered = fudgeAxis;
		
	} else if(fudgeAxis != 0 && (fudgeAxis == lastState && fudgeAxis != lastAxisTriggered)) {
		state = 0.0;
		changed = true;
		lastAxisTriggered = fudgeAxis;
	}
	else if(fudgeAxis == 0){
		lastAxisTriggered = 0;
	}
	else
	{
		state = lastState;
		changed = false;
	}
	
	held = fudgeAxis != 0.0;
	lastState = state;
}

void AxisButton::Reset() {
    state = 0.0;
    lastState = 0.0;
    changed = false;
}

void AxisButton::ToggleOff() {
    Reset();
    Update();
}