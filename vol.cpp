#include "vol.h"

void Vol::afegeixSeients(string* codiSeients, int nSeients)
{
	for (int i = 0; i < nSeients; i++)
	{
		m_seients[m_nSeients] = codiSeients[i];
		m_nSeients++;
	}
	//m_nSeients = 0;
}

bool Vol::afegeixPassatger(const string& codiSeient, const string& dni, const string& nom)
{
bool afegirPassatger = false;
int j = 0;

		while(!afegirPassatger && j < MAX_SEIENTS){
			if(m_seients[j].getCodi() == codiSeient){
				if(m_seients[j].assignaPassatger(dni, nom)){
					afegirPassatger = true;
					m_nSeients++;
				}else{
					j++;
				}
			}else{
				j++;
			}
		}

return afegirPassatger;
}

bool Vol::cancelaReserva(const string& codiSeient)
{
	bool reservaCancelada = false;
	int i = 0;
	while(i < MAX_SEIENTS && !reservaCancelada) {
		if(m_seients[i].getCodi() == codiSeient){
			return reservaCancelada = m_seients[i].eliminaPassatger();
		}
		else{
			i++;
		}
	}
}

Passatger* Vol::recuperaPassatger(const string& codiSeient)
{
	Passatger* recupPassatger = nullptr;
	bool trobatPasstager = false;
	int i = 0;
	while(!trobatPasstager && i < MAX_SEIENTS){
		if(m_seients[i].getCodi() == codiSeient){
			recupPassatger = m_seients[i].getPassatger();
			i++;
		}else{
			i++;
		}
	}

	return recupPassatger;
}

bool Vol::modificaReserva(const string& codiSeientOriginal, const string& codiSeientNou)
{
	bool reservaModificada = false;
	bool reservaCancelada = false;
	int i = 0;
	int j = 0;
	string dni = " ";
	string nom = " ";


	while(i < MAX_SEIENTS && !reservaCancelada){
		if(m_seients[i].getCodi() == codiSeientOriginal){
			if(m_seients[j].getCodi() == codiSeientNou){
				if(m_seients[i].getPassatger() != nullptr){
					dni = m_seients[i].getPassatger()->getDni();
					nom = m_seients[i].getPassatger()->getNom();
					reservaModificada = afegeixPassatger(codiSeientNou, dni, nom);
				}
				if(reservaModificada){
					reservaCancelada = cancelaReserva(codiSeientOriginal);
				}else
				{
					return reservaModificada;
				}
			}
			else{
				j++;
			}
		}else
		{
			i++;
		}
	}

	if(m_seients[j].getPassatger() == nullptr)
	{
		return false;
	}else
	{
		return reservaCancelada;
	}

}
