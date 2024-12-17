#include "reservation.h"
#include "chambre.h"
#include "client.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>

std::vector<Reservation> reservations;
extern std::vector<Chambre> chambres;
extern std::vector<Client> clients;

#define MAX_CHAMBRES 10 // Define the maximum number of rooms

Reservation::Reservation() : reservationCode(0), numberOfRooms(0), client(nullptr), reservationState(false) {
    std::memset(&startDate, 0, sizeof(startDate));
    std::memset(&endDate, 0, sizeof(endDate));
}

void Reservation::saisirReservation() {
    std::cout << "Entrez le code de réservation: ";
    std::cin >> reservationCode;
    std::cout << "Entrez le nombre de chambres réservées: ";
    std::cin >> numberOfRooms;
    for (int i = 0; i < numberOfRooms; i++) {
        std::cout << "Entrez le numero de chambres que vous voulez réserver: ";
        int numeroChambre;
        std::cin >> numeroChambre;
        for (auto& chambre : chambres) {
            if (chambre.getNumeroChambre() == numeroChambre) {
                chambre.setEstLibre(false);
                this->reservedRooms.push_back(chambre);
                break;
            }
        }
    }
    std::cout << "Entrez le numero de client qui veux effectuer la reservation: ";
    int idClient;
    std::cin >> idClient;
    client = nullptr; // Initialize client pointer to nullptr
    for (auto& c : clients) { // Rename loop variable to 'c'
        if (c.getId() == idClient) {
            client = &c;
            c.setNumReservations(c.getNumReservations() + 1);
            break;
        }
    }
    if (client == nullptr) {
        std::cerr << "Erreur: Client non trouvé." << std::endl;
        return;
    }

    // Saisir les dates de début et de fin
    std::cout << "Entrez la date de début (jj mm aaaa hh:mm): ";
    std::cin >> startDate.tm_mday >> startDate.tm_mon >> startDate.tm_year >> startDate.tm_hour >> startDate.tm_min;
    startDate.tm_mon -= 1; // Adjust month from 1-12 to 0-11
    startDate.tm_year -= 1900; // Adjust year to be years since 1900
    startDate.tm_sec = 0; // Initialize seconds to 0

    std::cout << "Entrez la date de fin (jj mm aaaa hh:mm): ";
    std::cin >> endDate.tm_mday >> endDate.tm_mon >> endDate.tm_year >> endDate.tm_hour >> endDate.tm_min;
    endDate.tm_mon -= 1; // Adjust month from 1-12 to 0-11
    endDate.tm_year -= 1900; // Adjust year to be years since 1900
    endDate.tm_sec = 0; // Initialize seconds to 0
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
    if (client != nullptr) {
        std::cout << "Client: " << client->getName() << " " << client->getSurname() << std::endl;
    } else {
        std::cout << "Client: Non trouvé" << std::endl;
    }
    std::cout << "Chambres réservées: " << std::endl;
    for (const auto& chambre : reservedRooms) {
        chambre.afficher();
    }
    std::cout << "Date de début: " << std::asctime(&startDate);
    std::cout << "Date de fin: " << std::asctime(&endDate);
    std::cout << "État de la réservation: " << (reservationState ? "Validée" : "Pas encore validée") << std::endl;
    std::cout << "Durée de la réservation: " << calculerDuree() << " jours" << std::endl;
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

std::tm Reservation::getStartDate() const {
    return startDate;
}

void Reservation::setStartDate(const std::string& date) {
    std::istringstream ss(date);
    ss >> std::get_time(&startDate, "%d %m %Y %H:%M");
}


std::tm Reservation::getEndDate() const {
    return endDate;
}

void Reservation::setEndDate(const std::string& date) {
    std::istringstream ss(date);
    ss >> std::get_time(&endDate, "%d %m %Y %H:%M");
}

std::vector<Chambre> Reservation::getReservedRooms() const {
    return reservedRooms;
}

void Reservation::setReservedRooms(const std::vector<Chambre>& rooms) {
    reservedRooms = rooms;
}