#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"

class Personnage
{
    public:

    Personnage();
    Personnage(std::string nom, std::string nomArme, int degatsArme);
    ~Personnage();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    void afficherEtat();
    std::string getPersonnageName();
    int getPersonnageHealth();
    void magie(Personnage &cible);
    private:

    int m_vie;
    int m_mana;
    Arme m_arme;
    std::string m_nom;
};

#endif
