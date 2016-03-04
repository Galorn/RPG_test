#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;

int main()
{

    // Cr�ation des personnages
    Personnage deuxiemeperso ("Jacques", "son poing", 10),premierperso("Paul", "Ep�e aiguis�e", 20);

    // Au combat !
    premierperso.attaquer(deuxiemeperso);
    deuxiemeperso.boirePotionDeVie(20);
    premierperso.attaquer(deuxiemeperso);
    deuxiemeperso.attaquer(premierperso);
    premierperso.changerArme("Double hache tranchante v�n�neuse de la mort", 40);
    deuxiemeperso.attaquer(premierperso);

    // Temps mort ! Voyons voir la vie de chacun...
    cout << "David" << endl;
    premierperso.afficherEtat();
    cout << endl << "Goliath" << endl;
    deuxiemeperso.afficherEtat();

    return 0;
}
