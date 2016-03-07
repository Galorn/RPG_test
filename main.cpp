#include <iostream>
#include <string>
#include "Personnage.h"
#include <stdlib.h> /* atoi */

using namespace std;

int main()
{
    std::string nomUn, nomDeux, armeUn, armeDeux;
    int degatArmeUn, degatArmeDeux;
    int const xArme(2);
    int const yArme(2);
    int a, b;

    // CREATION TABLEAU D'OBJET ARME
    Arme listeArmes[2];
    listeArmes[0] = Arme("Hache", 10);
    listeArmes[1] = Arme("Epee", 20);

    nomUn = listeArmes[0].getArmeName();
    cout << nomUn << endl ;

    //PREMIER COMBATTANT
    cout << "Nommez votre premier combattant" << endl;
    cin >> nomUn ;
    cout << "Choisissez votre arme parmis les suivantes " << endl << listeArmes[0].getArmeName() << endl << listeArmes[1].getArmeName() << endl;
    cin >> armeUn;

    // PROBLEME BOUCLE WHILE
    while (armeUn.compare(listeArmes[0].getArmeName()) != 0 && armeUn.compare(listeArmes[1].getArmeName()) !=0 )
    {
        cout << "Faux" << armeUn << " est invalide." << endl;
        cin >> armeUn;
    }

    cout << "Choix confirme" << endl;

    if (armeUn.compare(listeArmes[0].getArmeName()) == 0)
    {
            cout << "Vous avez selectionne " << listeArmes[0].getArmeName() << endl;
            degatArmeUn = listeArmes[0].getDegats();
            cout << "Wow " << degatArmeUn << " dommages." << endl;
    }
    else if (armeUn.compare(listeArmes[1].getArmeName()) == 0)
    {
            cout << "Vous avez selectionne " << listeArmes[1].getArmeName() << endl;
            degatArmeUn = listeArmes[1].getDegats();
            cout << "Wow " << degatArmeUn << " dommages." << endl;
    }

    //DEUXIEME COMBATTANT
    cout << "Nommez votre deuxième combattant" << endl;
    cin >> nomDeux ;
    cout << "Choisissez votre arme" << endl << listeArmes[0].getArmeName() << endl << listeArmes[1].getArmeName() << endl;

    do
    {
        cin >> armeDeux;
        cout << "Faux" << armeDeux << " est invalide." << endl;

    } while (armeDeux.compare(listeArmes[0].getArmeName()) != 0 && armeDeux.compare(listeArmes[1].getArmeName()) !=0 );

    if (armeDeux.compare(listeArmes[0].getArmeName())==0)
    {
            cout << "Vous avez selectionne " << listeArmes[0].getArmeName() << endl;
            degatArmeDeux = listeArmes[0].getDegats();
            cout << "Wow " << degatArmeDeux << " dommages." << endl;
    }
    else if (armeDeux.compare(listeArmes[1].getArmeName()) == 0)
    {
            cout << "Vous avez selectionne " << listeArmes[1].getArmeName() << endl;
            degatArmeDeux = listeArmes[1].getDegats();
            cout << "Wow " << degatArmeDeux << " dommages." << endl;
    }



    // Création des personnages
    Personnage deuxiemeperso (nomUn, armeUn, degatArmeUn),premierperso(nomDeux, armeDeux, degatArmeDeux);

    // Au combat !
    premierperso.attaquer(deuxiemeperso);
    deuxiemeperso.boirePotionDeVie(20);
    premierperso.attaquer(deuxiemeperso);
    deuxiemeperso.attaquer(premierperso);
    deuxiemeperso.attaquer(premierperso);

    // Temps mort ! Voyons voir la vie de chacun...
    cout << "David" << endl;
    premierperso.afficherEtat();
    cout << endl << "Goliath" << endl;
    deuxiemeperso.afficherEtat();

    return 0;
}
