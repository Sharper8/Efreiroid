//
// Created by Sharper8 on 07/09/2023.
//

#ifndef SDLTEST_SPACESHIP_H
#define SDLTEST_SPACESHIP_H


class Spaceship {

    double x;
    double y;
    double shipSize;
    double angle;
    double xSpeed;
    double ySpeed;
    double speed;

    public:
    ///////////////
    // Constructeur
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet

    Spaceship(double x, double y, double size, double xSpeed, double ySpeed);

    // destructeur
    ~Spaceship();

    //////////
    // Getters
        double GetX();
        double GetY();
        double GetXSpeed();
        double GetYSpeed();
        double GetAngle();
        double GetSpeed();

    //////////
    // Setters
        void SetX(double xSpeed);
        void SetY(double ySpeed);
        void SetXSpeed(double xSpeed);
        void SetYSpeed(double ySpeed);
        void SetAngle(double size);
        void SetSpeed(double speed);

    /////////////////////////
    // Déplacement de l'objet
    // déplace selon le vecteur de vitesse de l'objet
        void Move();

    ///////////////////////////////////////
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    // * screenWidth, screenHeight : taille de l'écran
        void Move(double screenWidth, double screenHeight);

    void updateSpeed();

    Spaceship(double x, double y, double angle, double size, double xSpeed, double ySpeed);
};


#endif //SDLTEST_SPACESHIP_H
