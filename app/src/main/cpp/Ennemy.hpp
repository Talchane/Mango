#ifndef ENNEMY_HPP
#define ENNEMY_HPP

class Ennemy
{
public:
    Ennemy();

    // Méthode virtuelle pour permettre l'héritage et la surcharge
    virtual void actualize();

    // Méthode pour dessiner l'ennemi, marquée comme const car elle ne modifie pas l'état de l'objet
    void Draw() const;

protected:
    // Vous pouvez ajouter des membres protégés ici si nécessaire
};

#endif // ENNEMY_HPP
