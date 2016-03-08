#include "Personnage.h"
using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string nom, string nomArme, int degatsArme) : m_nom(nom), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

Personnage::~Personnage()
{

}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
        cout << endl << "Rekt ! " << m_nom << " est mort ! " << endl;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cout << "Le personnage " << m_nom << " attaque à " << m_arme.getDegats() << " dommages le personnage " << cible.getPersonnageName() << " ." <<endl;
    cible.recevoirDegats(m_arme.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100)
    {
        m_vie = 100;
        cout << "Full life baby !" << endl ;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
    cout << endl << "SWITCHeuh" << endl;
}

bool Personnage::estVivant()
{
    if (m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Personnage::afficherEtat()
{

    cout << "Nom : " << m_nom << endl;
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}

std::string Personnage::getPersonnageName()
{
    return m_nom;
}

int Personnage::getPersonnageHealth()
{
    return m_vie;
}

void Personnage::magie(Personnage &cible)
{
    // SPELL DE BASE 10 DGTS MAGIQUES
    cible.recevoirDegats(10);
    cout << "Le personnage " << m_nom << " lance une attaque magique a " << 10 << " dommages sur le personnage " << cible.getPersonnageName() << " ." <<endl;

}

