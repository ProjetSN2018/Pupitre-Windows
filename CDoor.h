#pragma once

class CDoor
{
private:
	bool m_bState; //True = Verouill�e ; False = Non-Verouill�e
	bool m_bPos; //True = Ouvert ; False = Ferm�e

public:
	CDoor();
	~CDoor();
	void SetState(bool state);
	void SetPos(bool pos);
};
