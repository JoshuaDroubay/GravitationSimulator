#ifndef GSIM_MASS_H
#define GSIM_MASS_H

#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using std::vector, std::string, std::sqrt;


class mass {
public:
    mass();
    mass(string, double, vector<double>, vector<double>);
    vector<double> get_position();
    vector<double> get_prev_position();
    vector<double> get_velocity();
    double get_gravity();
    double get_mass();
    string get_name();
    void reset_gravity();
    void update_gravity(mass &);
    void update_position(double &);
    void update_prevPosition();
   
private:
    vector<double> position;
    vector<double> prevPosition;
    vector<double> velocity;
    vector<double> accGravity;
    double MASS;
    string name;
    double G = 1;
};


#endif //GSIM_MASS_H
