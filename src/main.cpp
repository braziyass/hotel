#include <iostream>
#include <vector>
#include "client.h"
#include "chambre.h"
#include "reservation.h"

void afficherMenu() {
    std::cout << "Menu de gestion de l'hôtel:" << std::endl;
    std::cout << "1. Saisir les informations d'un client" << std::endl;
    std::cout << "2. Afficher les informations d'un client" << std::endl;
    std::cout << "3. Afficher les informations de tout les clients" << std::endl;
    std::cout << "4. Saisir les informations d'une chambre" << std::endl;
    std::cout << "5. Afficher les informations d'une chambre" << std::endl;    
    std::cout << "6. Afficher les informations de toutes les chambres" << std::endl;
    std::cout << "7. Menu de réservation" << std::endl;
    std::cout << "0. Quitter" << std::endl;
}
void afficherMenuReservation() {
    std::cout << "Menu de Reservation:" << std::endl;
    std::cout << "1. Saisir une reservation" << std::endl;
    std::cout << "2. Modifier une reservation" << std::endl;
    std::cout << "3. Afficher une reservation" << std::endl;
    std::cout << "4. Afficher toutes les reservations" << std::endl;
    std::cout << "5. Supprimer reservation" << std::endl;    
    std::cout << "6. Teseter si un client a deja effectuer une reservation" << std::endl;
    std::cout << "7. Afficher les reservations effectue aujourd'hui" << std::endl;
    std::cout << "8. Afficher les reservations qui seront expire aujourd'hui" << std::endl;
    std::cout << "9. Menu Principal" << std::endl;
    std::cout << "0. Quitter" << std::endl;
}

int main() {
    std::cout << "Bienvenue dans le système de gestion d'hôtel!" << std::endl;

    std::vector<Client> clients; // Declare and initialize the clients vector
    std::vector<Chambre> chambres; // Declare and initialize the chambres vector
    std::vector<Reservation> reservations; // Declare and initialize the reservations vector

    int choix;
    do {
        afficherMenu();
        std::cout << "Entrez votre choix: ";
        std::cin >> choix;

        system("clear");

        switch (choix) {
            case 1:
                {
                    Client client;
                    client.inputClientInfo();
                    clients.push_back(client);
                }
                system("clear");
                break;

            case 2:
                std::cout << "Quelle client cherchez vous (ID): " << std::endl;
                int id;
                std::cin >> id;
                for (const auto& client : clients) {
                    if (client.getId() == id) {
                        client.display();
                    }
                }
                
                break;
            case 3:
                std::cout << "Informations de tout les clients:" << std::endl;
                for (const auto& client : clients) {
                    client.display();
                    std::cout << std::endl;
                    std::cout << std::endl;
                       
                }
                
                break;
            case 4:
                {
                    Chambre chambre;
                    chambre.saisir();
                    chambres.push_back(chambre);
                }
                system("clear");
                break;

            case 5:
                std::cout << "Quelle chambre cherchez vous (ID): " << std::endl;
                int idChambre;
                std::cin >> idChambre;
                for (const auto& chambre : chambres) {
                    if (chambre.getNumeroChambre() == idChambre) {
                        chambre.afficher();
                    }
                }
                break;                
            case 6:
                std::cout << "Informations de tout les chambres:" << std::endl;
                for (const auto& chambre : chambres) {
                    chambre.afficher();
                }
                
                break;
            case 7:
                {
                    
                    int choixres;
                    
                    do{
                        afficherMenuReservation();
                        std::cout << "Entrez votre choix: ";
                        std::cin >> choixres;
                        
                        switch (choixres) {
                            case 1:
                            {
                                Reservation reservation;
                                reservation.saisirReservation();
                                reservations.push_back(reservation);
                            }
                            break;
                            case 2:
                            
                                std::cout << "Quelle reservation cherchez vous (ID): " << std::endl;
                                int idReservation;
                                std::cin >> idReservation;
                                for (auto& reservation : reservations) {
                                    if (reservation.getReservationCode() == idReservation) {
                                        reservation.afficherReservation();
                                    }
                                }
                            
                            break;
                            case 3:
                            
                        
                                for (auto& reservation : reservations) {
                                    
                                    reservation.afficherReservation();
                                    std::cout << std::endl;
                                    std::cout << std::endl;
                                    
                                }
                            
                            break;
                            case 0:
                                std::cout <<"Retour au menu principal" << std::endl;
                                break;
                        }
                    }while(choixres != 0);
                    
                    
                }
                
                break;
            case 8:
                {
                    Reservation reservation;
                    reservation.saisirReservation();
                    reservations.push_back(reservation);
                }
                system("clear");
                break;
            case 9:
                for (auto& reservation : reservations) {
                    reservation.afficherReservation();
                }
                system("clear");
                break;
            case 0:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide, veuillez réessayer." << std::endl;
        }
    } while (choix != 0);

    return 0;
}