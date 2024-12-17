#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include "chambre.h"
#include "client.h"

class Client; // Forward declaration

class Reservation {
private:
    int reservationCode;
    int numberOfRooms;
    Client* client; // Pointer to Client object
    bool reservationState; // True for valid, False for canceled
    std::tm startDate; // Format: day, month, year, hour
    std::tm endDate; // Format: day, month, year, hour
    std::vector<Chambre> reservedRooms; // List of reserved rooms

public:
    Reservation(); // Default constructor

    void saisirReservation(); // Input reservation details
    bool verifierChambreReserve(const Chambre& chambre); // Check if a room is reserved
    bool ajouterChambre(const Chambre& chambre); // Add a room to the reservation
    void afficherReservation(); // Display reservation details
    double calculerDuree(); // Calculate the duration of the reservation
    bool supprimerChambre(const Chambre& chambre); // Remove a room from the reservation
    void validerReservation(); // Validate the reservation
    void annulerReservation(); // Cancel the reservation

    // Getters and Setters
    int getReservationCode() const;
    void setReservationCode(int code);
    int getNumberOfRooms() const;
    void setNumberOfRooms(int number);
    Client* getClient() const;
    void setClient(Client* client);
    bool getReservationState() const;
    void setReservationState(bool state);
    std::tm getStartDate() const;
    void setStartDate(const std::string& date);
    std::tm getEndDate() const;
    void setEndDate(const std::string& date);
    std::vector<Chambre> getReservedRooms() const;
    void setReservedRooms(const std::vector<Chambre>& rooms);
};

extern std::vector<Reservation> reservations;
#endif // RESERVATION_H