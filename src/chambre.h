#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
#include <iostream>


class Chambre {
private:
    int numeroChambre;
    std::string numeroTelephone;
    bool estLibre = true;


public:
    // Constructeur par défaut
    Chambre();
    Chambre(int numero, const std::string& telephone);
 

    // Getters
    int getNumeroChambre() const;
    std::string getNumeroTelephone() const;
    bool getEstLibre() const;

    // Setters
    void setNumeroChambre(int numero);
    void setNumeroTelephone(const std::string& telephone);
    void setEstLibre(bool libre);

    // Méthode d'affichage
    void afficher() const;

    // Méthode de saisie
    void saisir();

    // Méthode de comparaison
    bool operator==(const Chambre& autre) const;
};
extern std::vector<Chambre> chambres;

#endif // CHAMBRE_H