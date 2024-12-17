#include "chambre.h"
#include <iostream>
#include <vector>

std::vector<Chambre> chambres;
Chambre::Chambre() : numeroChambre(0), numeroTelephone("") {}

Chambre::Chambre(int numero, const std::string& telephone) : numeroChambre(numero), numeroTelephone(telephone) {}

void Chambre::saisir() {
    std::cout << "Entrez le numéro de la chambre: ";
    std::cin >> numeroChambre;
    std::cout << "Entrez le numéro de téléphone: ";
    std::cin >> numeroTelephone;
}

void Chambre::afficher() const {
    if (estLibre)
    {
        std::cout << "Chambre numéro: " << numeroChambre << ", Téléphone: " << numeroTelephone << std::endl;
        std::cout << "Chambre libre" << std::endl;
    }
    else
    {
        std::cout << "Chambre numéro: " << numeroChambre << ", Téléphone: " << numeroTelephone << std::endl;
        std::cout << "Chambre occupée" << std::endl;
    }
}

int Chambre::getNumeroChambre() const {
    return numeroChambre;
}

void Chambre::setNumeroChambre(int num) {
    numeroChambre = num;
}

std::string Chambre::getNumeroTelephone() const {
    return numeroTelephone;
}

void Chambre::setNumeroTelephone(const std::string& tel) {
    numeroTelephone = tel;
}

bool Chambre::getEstLibre() const {
    return estLibre;
}

void Chambre::setEstLibre(bool libre) {
    estLibre = libre;
}

bool Chambre::operator==(const Chambre& autre) const {
    return this->numeroChambre == autre.numeroChambre;
}