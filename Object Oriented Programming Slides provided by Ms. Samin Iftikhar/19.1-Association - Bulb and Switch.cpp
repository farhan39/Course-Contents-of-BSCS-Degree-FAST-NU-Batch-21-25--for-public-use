#include <iostream>
using namespace std;
//--------------------------------------------------------------------------
//class Bulb starts here
//--------------------------------------------------------------------------
class Bulb
{
private:
	char color[10];
	bool state;
public:	
	Bulb(char*);
	void ChangeState();
	void PrintState();
	bool GetState();
};

Bulb::Bulb(char* bulbColor = "Red")
{
	state = false;
	strcpy_s(color, bulbColor);
}
bool Bulb::GetState()
{
	return state;
}
void Bulb::ChangeState()
{
	if (state == false)
		state = true;
	else
		state = false;
}
void Bulb::PrintState()
{
	if (state == true)
	{
		cout << color << " Bulb in On\n";
	}		
	else
	{
		cout << color << "Bulb in Off\n";
	}
}
//--------------------------------------------------------------------------
//end of class Bulb
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//class Switch starts here
//--------------------------------------------------------------------------
class Switch
{
private:
	Bulb* bulb;
public:
	Switch();
	void Connect(Bulb&);
	void Disconnect();
	void Flick();
	~Switch(){ Disconnect(); }
};

Switch::Switch()
{
	//switch is not associated with any bulb in start
	bulb = 0;
}
void Switch::Connect(Bulb& b)
{
	if (bulb == 0)
	{
		bulb = &b;
	}
	else
	{
		cout << "Switch is already connected.\n";
	}
}
void Switch::Disconnect()
{
	if (bulb->GetState())
	{
		bulb->ChangeState();
	}
	bulb = 0;
}
void Switch::Flick()
{
	if (bulb == 0)
	{
		cout << "No Bulb is connected.\n";
	}
	else
	{
		bulb->ChangeState();
	}
}
//--------------------------------------------------------------------------
//end of class Switch
//--------------------------------------------------------------------------
void main()
{
	Switch s1;
	Bulb redBulb;

	s1.Flick();
	s1.Connect(redBulb);	//Red bulb is associated with switch 1.
	s1.Flick();
	redBulb.PrintState();
	s1.Flick();
	redBulb.PrintState();

	s1.Disconnect();		//Red bulb and s1 are no more associated

	Bulb greenBulb("Green");

	s1.Connect(greenBulb);	//Green bulb is associated with s1 now
	s1.Flick();
	greenBulb.PrintState();

	Switch s2;
	s2.Connect(redBulb);	//Red bulb is associated with switch 2 now
	s2.Flick();
	redBulb.PrintState();
}