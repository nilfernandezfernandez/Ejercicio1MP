#include "seient.h"

bool Seient::assignaPassatger(const string& dni, const string& nom)
{
	bool passatgerAssignat = false;

	if(m_passatger == nullptr)
	{
		m_passatger = new Passatger;
		m_passatger->setDni(dni);
		m_passatger->setNom(nom);
		passatgerAssignat = true;
	}

	return passatgerAssignat;
}

bool Seient::eliminaPassatger()
{
	bool eliminat = false;

	if(m_passatger != nullptr){
		m_passatger = nullptr;
		delete m_passatger;
		eliminat = true;
	}

	return eliminat;
}
