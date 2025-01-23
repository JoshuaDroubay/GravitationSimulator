#include "mass.h"

mass::mass() {
    throw std::invalid_argument("MASS WAS NOT PROPERLY INITIALIZED");
}

mass::mass(string givenName, double givenMass, vector<double> givenPosition, vector<double> givenVelocity) {
    int i;
   
    if (givenPosition.size() != 3 || givenVelocity.size() != 3) {
        throw std::invalid_argument("POSITION AND VELOCITY VECTORS MUST HAVE DIMENSION = 3");
    }
   
    name = givenName;
    MASS = givenMass;
   
    for (i = 0; i < 3; ++i) {
        position.push_back(givenPosition.at(i));
        prevPosition.push_back(givenPosition.at(i));
        velocity.push_back(givenVelocity.at(i));
        accGravity.push_back(0);
    }
}

vector<double> mass::get_position() {
    return position;
}

vector<double> mass::get_velocity() {
    return velocity;
}

string mass::get_name() {
    return name;
}

double mass::get_mass() {
    return MASS;
}

void mass::reset_gravity() {
    int i;

    for (i = 0; i < 3;  ++i) {
        accGravity.at(i) = 0;
    }
}

void mass::update_gravity(mass &givenMass) {
    double r;
    double rSquared;
    double FMag;
    double x = givenMass.get_prev_position().at(0) - position.at(0);
    double y = givenMass.get_prev_position().at(1) - position.at(1);
    double z = givenMass.get_prev_position().at(2) - position.at(2);

    rSquared = x * x + y * y + z * z;
    r = sqrt(rSquared);
    FMag = givenMass.get_mass() / rSquared;

    accGravity.at(0) = accGravity.at(0) + FMag * (x / r);
    accGravity.at(1) = accGravity.at(1) + FMag * (y / r);
    accGravity.at(2) = accGravity.at(2) + FMag * (z / r);
}

void mass::update_position(double &t) {
    double a_1 = accGravity.at(0) * G;
    double a_2 = accGravity.at(1) * G;
    double a_3 = accGravity.at(2) * G;

    velocity.at(0) = velocity.at(0) + (a_1 * t);
    velocity.at(1) = velocity.at(1) + (a_2 * t);
    velocity.at(2) = velocity.at(2) + (a_3 * t);

    double v_1 = velocity.at(0);
    double v_2 = velocity.at(1);
    double v_3 = velocity.at(2);

    position.at(0) = position.at(0) + (v_1 * t); //+ (.5 * a_1 * t * t);
    position.at(1) = position.at(1) + (v_2 * t); //+ (.5 * a_2 * t * t);
    position.at(2) = position.at(2) + (v_3 * t); //+ (.5 * a_3 * t * t);
}

void mass::update_prevPosition() {
    int i;

    for (i = 0; i < 3; ++i) {
        prevPosition.at(i) = position.at(i);
    }
}

vector<double> mass::get_prev_position() {
    return prevPosition;
}

double mass::get_gravity() {
    double Fg;

    Fg = G * G * (accGravity.at(0) * accGravity.at(0) + accGravity.at(1) * accGravity.at(1)
            + accGravity.at(2) * accGravity.at(2));

    return Fg;
}
