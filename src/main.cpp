#include <iostream>
#include <vector>
#include "client.h"
#include "chambre.h"
#include "reservation.h"

extern std::vector<Client> clients; // Use the external declaration
extern std::vector<Chambre> chambres; // Use the external declaration
extern std::vector<Reservation> reservations; // Use the external declaration

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
    std::cout << "6. Tester si un client a deja effectué une reservation" << std::endl;
    std::cout << "7. Afficher les reservations effectuées aujourd'hui" << std::endl;
    std::cout << "8. Afficher les reservations qui seront expirées aujourd'hui" << std::endl;
    std::cout << "9. Valider Reservation" << std::endl;
    std::cout << "10. Menu Principal" << std::endl;
    std::cout << "0. Quitter" << std::endl;
}

int main() {
    std::cout << "Bienvenue dans le système de gestion d'hôtel!" << std::endl;

    int choix;

    Client client1(1, "yassine", "labrazi", "Sala al jadida");
    clients.push_back(client1);
    Client client2(2, "simo", "benazza", "Rabat");
    clients.push_back(client2);

    Chambre chambre1(1, "555-1234");
    chambres.push_back(chambre1);
    Chambre chambre2(2, "555-5678");
    chambres.push_back(chambre2);


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
                std::cout << "Quel client cherchez-vous (ID): " << std::endl;
                int id;
                std::cin >> id;
                for (const auto& client : clients) {
                    if (client.getId() == id) {
                        client.display();
                    }
                }
                break;

            case 3:
                std::cout << "Informations de tous les clients:" << std::endl;
                for (const auto& client : clients) {
                    client.display();
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
                std::cout << "Quelle chambre cherchez-vous (ID): " << std::endl;
                int idChambre;
                std::cin >> idChambre;
                for (const auto& chambre : chambres) {
                    if (chambre.getNumeroChambre() == idChambre) {
                        chambre.afficher();
                    }
                }
                break;

            case 6:
                std::cout << "Informations de toutes les chambres:" << std::endl;
                for (const auto& chambre : chambres) {
                    chambre.afficher();
                }
                break;

            case 7:
                {
                    int choixres;
                    do {
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
                                std::cout << "Quelle reservation cherchez-vous (ID): " << std::endl;
                                int idReservation;
                                std::cin >> idReservation;
                                for (auto& reservation : reservations) {
                                    if (reservation.getReservationCode() == idReservation) {
                                        reservation.afficherReservation();
                                        std::cout << "Voulez-vous modifier cette reservation? (O/N): ";
                                        char reponse;
                                        std::cin >> reponse;
                                        if (reponse == 'O' || reponse == 'o') {
                                            reservation.saisirReservation();
                                        }
                                    }
                                }
                                break;

                            case 3:
                                std::cout << "Quelle reservation cherchez-vous (ID): " << std::endl;
                                // int idReservation;
                                std::cin >> idReservation;
                                for (auto& reservation : reservations) {
                                    if (reservation.getReservationCode() == idReservation) {
                                        reservation.afficherReservation();
                                    }
                                }
                                break;

                            case 4:
                                for (auto& reservation : reservations) {
                                    reservation.afficherReservation();
                                    std::cout << std::endl;
                                }
                                break;


                            case 5:
                                std::cout << "Quelle reservation voulez-vous supprimer (ID): " << std::endl;
                                std::cin >> idReservation;
                                for (auto it = reservations.begin(); it != reservations.end(); ++it) {
                                    if (it->getReservationCode() == idReservation) {
                                        // Set estLibre to true for all reserved rooms
                                        for (auto& chambre : it->getReservedRooms()) {
                                            for (auto& c : chambres) {
                                                if (c.getNumeroChambre() == chambre.getNumeroChambre()) {
                                                    c.setEstLibre(true);
                                                    break;
                                                }
                                            }
                                        }
                                        reservations.erase(it);
                                        break;
                                    }
                                }
                                break;

                            case 6:
                                std::cout << "Quel client cherchez-vous (ID): " << std::endl;
                                int idClient;
                                std::cin >> idClient;
                                for (const auto& client : clients) {
                                    if (client.getId() == idClient) {
                                        if (client.getNumReservations() > 0) {
                                            std::cout << "Le client a effectué des réservations." << std::endl;
                                        } else {
                                            std::cout << "Le client n'a pas effectué de réservations." << std::endl;
                                        }
                                        
                                    }
                                    else {
                                        std::cout << "Client non trouvé." << std::endl;
                                    }
                                }
                                
                                break;

                            case 7:
                                std::cout << "Réservations effectuées aujourd'hui:" << std::endl;
                                for ( auto& reservation : reservations) {
                                    std::time_t now = std::time(0);
                                    std::tm* today = std::localtime(&now);
                                    if (today->tm_mday == reservation.getStartDate().tm_mday && today->tm_mon == reservation.getStartDate().tm_mon && today->tm_year == reservation.getStartDate().tm_year) {
                                        reservation.afficherReservation();
                                    }
                                }
                                break;

                            
                            case 8:
                                std::cout << "Réservations expirées aujourd'hui:" << std::endl;
                                for ( auto& reservation : reservations) {
                                    std::time_t now = std::time(0);
                                    std::tm* today = std::localtime(&now);
                                    if (today->tm_mday == reservation.getEndDate().tm_mday && today->tm_mon == reservation.getEndDate().tm_mon && today->tm_year == reservation.getEndDate().tm_year) {
                                        reservation.afficherReservation();
                                    }
                                }
                                break;
                            
                            case 9:
                                std::cout << "Quelle reservation voulez-vous valider (ID): " << std::endl;
                                std::cin >> idReservation;
                                for (auto& reservation : reservations) {
                                    if (reservation.getReservationCode() == idReservation) {
                                        reservation.validerReservation();
                                    }
                                }
                                break;

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;
                        }
                    } while (choixres != 0);
                }
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