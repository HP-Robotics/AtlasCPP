#include <string>
#include "frc/Joystick.h"

class AxisButton {
    public:
        AxisButton (frc::Joystick *stick, int num, std::string name);
        std::string GetName();
        double GetState();
        bool Held();
        bool Changed();
        void Update();
        void Reset();
        void ToggleOff();
    private:
        bool held = false;	//stands for 'held', true if the Button is being actively held down
	    double state = 0.0;	//stands for 'state', true if the Button is pressed
	    double lastState = 0.0;	//stands for 'last state', stores the previous state of the Button
	    bool changed = false;	//stands for 'changed', true if the Button's previous state does not match its current state
	    double lastAxisTriggered = 0.0;
	    double fudgeAxis = 0.0;
	    double abutton;
	    std::string name;
	    frc::Joystick *stick;
        int num;
};