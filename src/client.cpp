#include "client.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<Client> clients;
Client::Client() : id(), name(""), surname(""), address("") {}
Client::Client(int id, const std::string& name, const std::string& surname, const std::string& address) : id(id), name(name), surname(surname), address(address) {}

void Client::setId(int id) {
    this->id = id;
}

int Client::getId() const {
    return id;
}

void Client::setName(const std::string& name) {
    this->name = name;
}

std::string Client::getName() const {
    return name;
}
int Client::getNumReservations() const {
    return numreservations;
}

void Client::setSurname(const std::string& surname) {
    this->surname = surname;
}

std::string Client::getSurname() const {
    return surname;
}

void Client::setAddress(const std::string& address) {
    this->address = address;
}

std::string Client::getAddress() const {
    return address;
}
void Client::setNumReservations(int numreservations) {
    this->numreservations = numreservations;
}


void Client::display() const {
    std::cout << "Client ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Address: " << address << std::endl;
}

void Client::inputClientInfo() {
    std::cout << "Enter Client ID: ";
    std::cin >> id;
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Surname: ";
    std::getline(std::cin, surname);
    std::cout << "Enter Address: ";
    std::getline(std::cin, address);
}