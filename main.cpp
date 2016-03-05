#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;

int main()
{
    string nomUn, nomDeux, armeUn, armeDeux;
    int degatArmeUn, degatArmeDeux;
    //PREMIER COMBATTANT
    cout << "Nommez votre premier combattant" << endl;
    cin >> nomUn ;
    cout << "Choisissez votre arme" << endl;
    cin >> armeUn;
    cout << "Combien de degats fait-elle ?" << endl;
    cin >> degatArmeUn;
    //DEUXIEME COMBATTANT
    cout << "Nommez votre deuxième combattant" << endl;
    cin >> nomDeux ;
    cout << "Choisissez votre arme" << endl;
    cin >> armeDeux;
    cout << "Combien de degats fait-elle ?" << endl;
    cin >> degatArmeDeux;
    // Création des personnages
    Personnage deuxiemeperso (nomUn, armeUn, degatArmeUn),premierperso(nomDeux, armeDeux, degatArmeDeux);

    // Au combat !
    premierperso.attaquer(deuxiemeperso);
    deuxiemeperso.boirePotionDeVie(20);
    premierperso.attaquer(deuxiemeperso);
    deuxiemeperso.attaquer(premierperso);
    premierperso.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    deuxiemeperso.attaquer(premierperso);

    // Temps mort ! Voyons voir la vie de chacun...
    cout << "David" << endl;
    premierperso.afficherEtat();
    cout << endl << "Goliath" << endl;
    deuxiemeperso.afficherEtat();

    return 0;
}
