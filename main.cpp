#include <iostream>
#include <string>
#include "Personnage.h"
#include <stdlib.h> /* atoi */

using namespace std;

int main()
{
    string nomUn, nomDeux, armeUn, armeDeux;
    int degatArmeUn, degatArmeDeux;
    int const xArme(2);
    int const yArme(2);
    int a, b;

    // CONSTITUTION DU TABLEAU
    std::string tableauArme[xArme][yArme];
    tableauArme[0][0] = "Hache";
    tableauArme[0][1] = "10"; // Case au dessus de [0][0]
    tableauArme[1][0] = "Epee" ;// Case à droite de [0][0]
    tableauArme[1][1] = "20" ;// Case au dessus de [1][0]
    // CONVERSION STRING EN INT
    a = atoi(tableauArme[0][1].c_str());
    b = atoi(tableauArme[1][1].c_str());

    cout << a << endl << b << endl ;



    //PREMIER COMBATTANT
    cout << "Nommez votre premier combattant" << endl;
    cin >> nomUn ;
    cout << "Choisissez votre arme parmis les suivantes " << endl << tableauArme[0][0] << endl << tableauArme[1][0] << endl;
    do
    {
        cout << "go" << endl;
        cin >> armeUn;

    } while (armeUn != tableauArme[0][0] || armeUn != tableauArme[1][0]);

    cout << "Choix confirme" << endl;


    if (armeUn == tableauArme[0][0])
    {
            cout << "Vous avez selectionne " << tableauArme[0][0] << endl;
    }
    else if (armeUn == tableauArme[1][0])
    {
            cout << "Vous avez selectionne " << tableauArme[1][0] << endl;
    }


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
    /* premierperso.changerArme("Double hache tranchante vénéneuse de la mort", 40); */
    deuxiemeperso.attaquer(premierperso);

    // Temps mort ! Voyons voir la vie de chacun...
    cout << "David" << endl;
    premierperso.afficherEtat();
    cout << endl << "Goliath" << endl;
    deuxiemeperso.afficherEtat();

    return 0;
}
