#include "reservation.h"

#include "chambre.h"

#include "client.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>

// std::vector<Reservation> reservations;

std::vector<Reservation> reservations;
extern std::vector<Chambre> chambres;
extern std::vector<Client> clients;

#define MAX_CHAMBRES 10 // Define the maximum number of rooms

Reservation::Reservation() : reservationCode(0), numberOfRooms(0), reservationState(false) {}

void Reservation::saisirReservation() {
    std::cout << "Entrez le code de réservation: ";
    std::cin >> reservationCode;
    std::cout << "Entrez le nombre de chambres réservées: ";
    std::cin >> numberOfRooms;
    for (int i = 0; i < numberOfRooms; i++)
    {
        std::cout << "Entrez le numero de chambres que vous voulez réservé: ";
        int numeroChambre;
        std::cin >> numeroChambre;
        for (auto& chambre : chambres) {
            if (chambre.getNumeroChambre() == numeroChambre) {
                chambre.setEstLibre(false);
                reservedRooms.push_back(chambre);
                break;
            }
        }
    }
    std::cout << "Entrez le numero de client qui veux effectuer la reservation: ";
    int idClient;
    std::cin >> idClient;
    for (auto& client : clients) {
        if (client.getId() == idClient) {
            this->client = &client;
            client.setNumReservations(client.getNumReservations() + 1);
            break;
        }
    }
    
    // Saisir les dates de début et de fin
    std::cout << "Entrez la date de début (jj mm aaaa hh:mm): ";
    std::cin >> startDate.tm_mday >> startDate.tm_mon >> startDate.tm_year >> startDate.tm_hour >> startDate.tm_min;
    startDate.tm_year -= 1900; // Ajustement pour tm_year
    std::cout << "Entrez la date de fin (jj mm aaaa hh:mm): ";
    std::cin >> endDate.tm_mday >> endDate.tm_mon >> endDate.tm_year >> endDate.tm_hour >> endDate.tm_min;
    endDate.tm_year -= 1900; // Ajustement pour tm_year
}

bool Reservation::verifierChambreReserve(const Chambre& chambre) {
    for (const auto& c : reservedRooms) {
        if (c == chambre) {
            return true;
        }
    }
    return false;
}

bool Reservation::ajouterChambre(const Chambre& chambre) {
    if (numberOfRooms < MAX_CHAMBRES && !verifierChambreReserve(chambre)) {
        reservedRooms.push_back(chambre);
        numberOfRooms++;
        return true;
    }
    return false;
}

void Reservation::afficherReservation() {
    std::cout << "Code de réservation: " << reservationCode << std::endl;
    std::cout << "Client: " << client->getName() << " " << client->getSurname() << std::endl;
    std::cout << "Chambres réservées: " << std::endl;
    for (const auto& chambre : reservedRooms) {
        chambre.afficher();
    }
    std::cout << "Date de début: " << std::asctime(&startDate);
    std::cout << "Date de fin: " << std::asctime(&endDate);
    std::cout << "État de la réservation: " << (reservationState ? "Validée" : "Annulée") << std::endl;
}

double Reservation::calculerDuree() {
    std::tm start = startDate;
    std::tm end = endDate;
    std::time_t debut = std::mktime(&start);
    std::time_t fin = std::mktime(&end);
    return std::difftime(fin, debut) / (60 * 60 * 24); // Durée en jours
}

bool Reservation::supprimerChambre(const Chambre& chambre) {
    auto it = std::find(reservedRooms.begin(), reservedRooms.end(), chambre);
    if (it != reservedRooms.end()) {
        reservedRooms.erase(it);
        numberOfRooms--;
        return true;
    }
    std::cout << "Erreur: La chambre n'est pas réservée." << std::endl;
    return false;
}

void Reservation::validerReservation() {
    reservationState = true;
}

void Reservation::annulerReservation() {
    reservationState = false;
}

int Reservation::getReservationCode() const {
    return reservationCode;
}

void Reservation::setReservationCode(int code) {
    reservationCode = code;
}

int Reservation::getNumberOfRooms() const {
    return numberOfRooms;
}

void Reservation::setNumberOfRooms(int number) {
    numberOfRooms = number;
}

Client* Reservation::getClient() const {
    return client;
}

void Reservation::setClient(Client* client) {
    this->client = client;
}

bool Reservation::getReservationState() const {
    return reservationState;
}

void Reservation::setReservationState(bool state) {
    reservationState = state;
}

std::string Reservation::getStartDate() const {
    char buffer[80];
    strftime(buffer, 80, "%d-%m-%Y %H:%M", &startDate);
    return std::string(buffer);
}

void Reservation::setStartDate(const std::string& date) {
    std::istringstream ss(date);
    ss >> std::get_time(&startDate, "%d-%m-%Y %H:%M");
}

std::string Reservation::getEndDate() const {
    char buffer[80];
    strftime(buffer, 80, "%d-%m-%Y %H:%M", &endDate);
    return std::string(buffer);
}

void Reservation::setEndDate(const std::string& date) {
    std::istringstream ss(date);
    ss >> std::get_time(&endDate, "%d-%m-%Y %H:%M");
}