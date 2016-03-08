#include <iostream>
#include <string>
#include "Personnage.h"
#include <stdlib.h> /* atoi, rand */
#include <cstdlib> /* Exit */

using namespace std;

int main()
{
    // INITIALISATION PARAMETRES
    std::string nomUn, nomDeux, armeUn, armeDeux, jouer;
    int degatArmeUn, degatArmeDeux, commandeJoueur, attaquePNJ, commandeJoueurDeux;

    // CREATION TABLEAU D'OBJET ARME
    Arme listeArmes[2];
    listeArmes[0] = Arme("Hache", 10);
    listeArmes[1] = Arme("Epee", 20);

    // ACCUEIL
    cout << "BIENVENUE SUR LE SIMULATEUR DE COMBAT BIG BOSS vs COOP ! " << endl << "LET'S FUCKING BEGIN" << endl << "Voulez vous jouer ?" << endl << "OUI ou NON " << endl ;
    cin >> jouer;
    while (jouer.compare("OUI")!= 0 && jouer.compare ("NON")!=0)
    {
        cout << endl << "Tu sais pas ecrire ?" << endl << "Tu veux jouer ? OUI ou NON " << endl ;
        cin >> jouer;
    }
    while (jouer.compare("OUI")== 0)
    {

        //PREMIER COMBATTANT
        cout << "Nommez votre premier combattant." << endl;
        cin >> nomUn ;
        cout << endl << "Choisissez votre arme parmis les suivantes " << endl << listeArmes[0].getArmeName() << endl << listeArmes[1].getArmeName() << endl;
        cin >> armeUn;

        while (armeUn.compare(listeArmes[0].getArmeName()) != 0 && armeUn.compare(listeArmes[1].getArmeName()) !=0 )
        {
            cout << endl << "Faux " << armeUn << " est invalide." << endl;
            cin >> armeUn;
        }

        if (armeUn.compare(listeArmes[0].getArmeName()) == 0)
        {
                cout << endl << "Vous avez selectionne " << listeArmes[0].getArmeName() << " ." << endl;
                degatArmeUn = listeArmes[0].getDegats();
                cout << "Wow " << degatArmeUn << " dommages." << endl;
        }
        else if (armeUn.compare(listeArmes[1].getArmeName()) == 0)
        {
                cout << endl << "Vous avez selectionne " << listeArmes[1].getArmeName() << " ." << endl;
                degatArmeUn = listeArmes[1].getDegats();
                cout << "Wow " << degatArmeUn << " dommages." << endl;
        }
        cout << "Choix confirme ." << endl;

        //DEUXIEME COMBATTANT
        cout << endl << "Nommez votre deuxieme combattant ." << endl;
        cin >> nomDeux ;
        cout << endl << "Choisissez votre arme" << endl << listeArmes[0].getArmeName() << endl << listeArmes[1].getArmeName() << endl;
        cin >> armeDeux;

        while (armeDeux.compare(listeArmes[0].getArmeName()) != 0 && armeDeux.compare(listeArmes[1].getArmeName()) !=0 )
        {
            cin >> armeDeux;
            cout << endl << "Faux " << armeDeux << " est invalide." << endl;

        }

        if (armeDeux.compare(listeArmes[0].getArmeName())==0)
        {
                cout << endl << "Vous avez selectionne " << listeArmes[0].getArmeName() << " ." << endl;
                degatArmeDeux = listeArmes[0].getDegats();
                cout << "Wow " << degatArmeDeux << " dommages." << endl;
        }
        else if (armeDeux.compare(listeArmes[1].getArmeName()) == 0)
        {
                cout << endl << "Vous avez selectionne " << listeArmes[1].getArmeName() << " ." << endl;
                degatArmeDeux = listeArmes[1].getDegats();
                cout << "Wow " << degatArmeDeux << " dommages." << endl;
        }

        // CREATION DES OBJETS PERSONNAGE
        Personnage premierPerso (nomUn, armeUn, degatArmeUn),deuxiemePerso(nomDeux, armeDeux, degatArmeDeux);
        Personnage personnageNonJoueur("Big Boss", "sa bite ", 50);

        // ACTION
        // BOUCLE DE VERIFICATION SI LES PERSONNAGES SONT ENCORE VIVANT
        while (personnageNonJoueur.getPersonnageHealth()>0 && premierPerso.getPersonnageHealth()>0 && deuxiemePerso.getPersonnageHealth()>0)
        {
            // SELECTION ACTION JOUEUR
            do
            {
                cout << endl << "Joueur 1 que voulez-vous faire ? Selectionner 1, 2, 3, 4" << endl << "1.Attaque" << endl << "2.Magie" << endl << "3.Potion de vie 10 PV" << endl << "4.Changer d'arme" << endl;
                cin >> commandeJoueur;
            }while(commandeJoueur != 1 && commandeJoueur != 2 && commandeJoueur != 3 && commandeJoueur !=4);
            // EXECUTION COMMANDE JOUEUR
            switch(commandeJoueur)
            {
                case 1:
                    cout << endl << "Attaque !" << endl;
                    premierPerso.attaquer(personnageNonJoueur);
                    break;

                case 2:
                    cout << endl << "Magie !" << endl;
                    premierPerso.magie(personnageNonJoueur);
                    break;

                case 3:
                    cout << endl << "Potion !" << endl;
                    premierPerso.boirePotionDeVie(10);
                    break;
                case 4:
                    // PROCEDURE DE CHANGEMENT D'ARME
                    cout << endl << "Choisissez votre nouvelle arme parmis les suivantes " << endl << listeArmes[0].getArmeName() << endl << listeArmes[1].getArmeName() << endl;
                    cin >> armeUn;

                    while (armeUn.compare(listeArmes[0].getArmeName()) != 0 && armeUn.compare(listeArmes[1].getArmeName()) !=0 )
                    {
                        cout << endl << "Faux " << armeUn << " est invalide ." << endl;
                        cin >> armeUn;
                    }

                    if (armeUn.compare(listeArmes[0].getArmeName()) == 0)
                    {
                            cout << endl << "Vous avez selectionne " << listeArmes[0].getArmeName() << endl;
                            degatArmeUn = listeArmes[0].getDegats();
                            cout << "Wow " << degatArmeUn << " dommages ." << endl;
                    }
                    else if (armeUn.compare(listeArmes[1].getArmeName()) == 0)
                    {
                            cout << endl << "Vous avez selectionne " << listeArmes[1].getArmeName() << endl;
                            degatArmeUn = listeArmes[1].getDegats();
                            cout << "Wow " << degatArmeUn << " dommages ." << endl;
                    }
                    cout << "Choix confirme" << endl;
                    premierPerso.changerArme(armeUn, degatArmeUn);
                    break;
            }

            // AU TOUR DU BOSS
            cout << endl <<  "Big Boss attaque !" << endl;
            attaquePNJ = rand() %5 +1;
            // LE BOSS ATTAQUE DE MANIERE ALEATOIRE AVEC SOIT SON ARME SOIT SA MAGIE LE JOUEUR UN OU DEUX OU SE BLESSE
            switch(attaquePNJ)
            {
                case 1:
                    cout << endl << "Big Boss attaque le premier joueur avec son arme ." << endl;
                    personnageNonJoueur.attaquer(personnageNonJoueur);
                    break;

                case 2:
                    cout << endl << "Big Boss attaque le premier joueur avec sa magie ." << endl;
                    personnageNonJoueur.magie(premierPerso);
                    break;

                case 3:
                    cout << endl << "Big Boss attaque le deuxieme joueur avec son arme ." << endl;
                    personnageNonJoueur.attaquer(deuxiemePerso);
                    break;

                case 4:
                    cout << endl << "Big Boss attaque le deuxieme joueur avec sa magie ." << endl;
                    personnageNonJoueur.magie(deuxiemePerso);
                    break;

                case 5:
                    cout << endl << "Big Boss tombe par terre et se fait mal ." << endl;
                    personnageNonJoueur.recevoirDegats(10);
                    break;
            }

            // AU TOUR DU JOUEUR 2
            do
            {
                cout << endl << "Joueur 2 que voulez-vous faire ? Selectionner 1, 2, 3, 4 ." << endl << "1.Attaque" << endl << "2.Magie" << endl << "3.Potion de vie 10 PV" << endl << "4.Changer d'arme" <<endl;
                cin >> commandeJoueurDeux;
            }while(commandeJoueurDeux != 1 && commandeJoueurDeux != 2 && commandeJoueurDeux != 3 && commandeJoueurDeux != 4);

            switch(commandeJoueurDeux)
            {
                case 1:
                    cout << endl << "Attaque !" << endl;
                    deuxiemePerso.attaquer(personnageNonJoueur);
                    break;

                case 2:
                    cout << endl << "Magie !" << endl;
                    deuxiemePerso.magie(personnageNonJoueur);
                    break;

                case 3:
                    cout << endl << "Potion !" << endl;
                    deuxiemePerso.boirePotionDeVie(10);
                    break;

                case 4:
                    cout << endl << "Choisissez votre nouvelle arme parmis les suivantes " << endl << listeArmes[0].getArmeName() << endl << listeArmes[1].getArmeName() << endl;
                    cin >> armeDeux;

                    while (armeDeux.compare(listeArmes[0].getArmeName()) != 0 && armeDeux.compare(listeArmes[1].getArmeName()) !=0 )
                    {
                        cout << endl << "Faux " << armeDeux << " est invalide." << endl;
                        cin >> armeDeux;
                    }

                    if (armeDeux.compare(listeArmes[0].getArmeName()) == 0)
                    {
                            cout << endl << "Vous avez selectionne " << listeArmes[0].getArmeName() << endl;
                            degatArmeDeux = listeArmes[0].getDegats();
                            cout << "Wow " << degatArmeDeux << " dommages." << endl;
                    }
                    else if (armeDeux.compare(listeArmes[1].getArmeName()) == 0)
                    {
                            cout << endl << "Vous avez selectionne " << listeArmes[1].getArmeName() << endl;
                            degatArmeDeux = listeArmes[1].getDegats();
                            cout << "Wow " << degatArmeDeux << " dommages." << endl;
                    }
                    cout << "Choix confirme ." << endl;
                    deuxiemePerso.changerArme(armeDeux, degatArmeDeux);
            }

            // ETAT DES JOUEURS ET DU PNJ

            cout << endl << nomUn << endl;
            premierPerso.afficherEtat();
            cout << endl << nomDeux << endl;
            deuxiemePerso.afficherEtat();
            cout << endl << personnageNonJoueur.getPersonnageName() << endl;
            personnageNonJoueur.afficherEtat();


        }
            // ETAT FINAL
            cout << endl << "UN MORT " << endl << "ETAT EN FIN DE COMBAT " << endl << nomUn << endl;
            premierPerso.afficherEtat();
            cout << endl << nomDeux << endl;
            deuxiemePerso.afficherEtat();
            cout << endl << personnageNonJoueur.getPersonnageName() << endl;
            personnageNonJoueur.afficherEtat();

        cout << endl << "Voulez vous recommencer ?" << endl << " OUI ou NON " << endl;
        cin >> jouer;
        while (jouer.compare("OUI")!= 0 && jouer.compare ("NON")!=0)
    {
        cout << endl << "Tu sais pas ecrire ?" << endl << "Tu veux jouer ? OUI ou NON " << endl ;
        cin >> jouer;
    }

    }
    cout << endl << "CIAO !" << endl;
        return 0;

}
