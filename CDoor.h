#pragma once

class CDoor
{
private:
	bool m_bState; //True = Verouillée ; False = Non-Verouillée
	bool m_bPos; //True = Ouvert ; False = Fermée

public:
	CDoor();
	~CDoor();
	void SetState(bool state);
	void SetPos(bool pos);
};
