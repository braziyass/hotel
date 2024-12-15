#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>


class Client {
private:
    int id;
    std::string name;
    std::string surname;
    std::string address;
    int numreservations = 0;

public:
    // Default constructor
    Client();

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    int getNumReservations() const;

    // Setters
    void setId(int newId);
    void setName(const std::string& newName);
    void setSurname(const std::string& newSurname);
    void setAddress(const std::string& newAddress);
    void setNumReservations(int newNumReservations);

    // Method to display client information
    void display() const;
    void inputClientInfo();
};

extern std::vector<Client> clients;

#endif // CLIENT_H