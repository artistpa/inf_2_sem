#include <iostream>
#include <cmath>
#include "Astro.hpp"
using namespace std;

astro_object::astro_object(float m, float T){
    mass = m;
    temperature = T;
}

float astro_object::get_mass(){
    cout << 'Mass: ' << mass;
    return(mass);
}

float astro_object::get_temperature(){
    cout << 'Temperature: ' << temperature;
    return(temperature);
}

float astro_object::get_density(){
    cin >> volume;
    cout << 'Average density: ' << mass / volume;
    return(mass / volume);
}

Universe::Universe(float a, float r, float m, float T): astro_object(m, T){
    age = a;
    radius = r;
}

float Universe::get_age(){
    return(age);
}

float Universe::get_radius(){
    return(radius);
}

Planet::Planet(float d, float s, float t, float T, float n, bool a, bool b, float m, float temp): astro_object(m, temp){
    diameter = d;
    Sun_distance = s;
    t_day = t;
    T_year = T;
    satellite_number = n;
    atmosphere = a;
    Solar_system = b;
}

float Planet::get_volume(){
    return(4 * 3.14 * (diameter/2) * (diameter/2) * (diameter/2) / 3);
}

float Planet::orbital_speed(){
    if (Solar_system == true)
        return(2 * 3.14 * Sun_distance / T_year);
        return 0;
}

float Planet::own_rotation_speed(){
    return(2* 3.14 / t_day);
}

Star::Star(float L, float a, float r, float m, float T): Universe(a, r, m, T){
    luminosity = L;
}

void Star::get_type(){
    if (radius > 6950000000 and radius < 6950000000 and luminosity > 3.827 * 10260 and luminosity < 3.827 * 1026000)
        cout << 'Giant';
    if (mass > 2 * pow(10, 30) * 0.012 and mass < 2 * pow(10, 30) * 0.0767)
        cout << 'Dwarf';
}

Galaxy::Galaxy(float td, float L, float a, float r, float m, float T): Star(L, a, r, m, T){
    thickness_of_disk = td;
}

float Galaxy::get_removal_rate (float R){
    return(2.2 * pow(10,-18) * R);
}

float Galaxy::get_rot_speed(){
    return(pow(mass * 6.67 * pow(10,-11) / radius / 2,0.5));
}

Nebula::Nebula(float c, float m, float T): astro_object(m, T){
    concentration = c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> *(type + i);
}

float Nebula::get_particle_number() {
    cin >> volume;
    return(volume * concentration);
}

void dwarf_star::get_true_colour(){
    if (temperature > 30000 and temperature < 60000)
        cout << 'Blue';
    if (temperature > 10000 and temperature < 30000)
        cout << 'White-Blue';
    if (temperature > 7500 and temperature < 10000)
        cout << 'White';
    if (temperature > 6000 and temperature < 7500)
        cout << 'Yellow-white';
    if (temperature > 5000 and temperature < 6000)
        cout << 'Yellow';
    if (temperature > 3500 and temperature < 5000)
        cout << 'Orange';
    if (temperature > 2000 and temperature < 3500)
        cout << 'Red';
}

void dwarf_star::get_visible_colour(){
    if (temperature > 30000 and temperature < 60000)
        cout << 'Blue';
    if (temperature > 10000 and temperature < 30000)
        cout << 'White-blue and white';
    if (temperature > 7500 and temperature < 10000)
        cout << 'White';
    if (temperature > 6000 and temperature < 7500)
        cout << 'White';
    if (temperature > 5000 and temperature < 6000)
        cout << 'Yellow';
    if (temperature > 3500 and temperature < 5000)
        cout << 'Yellow-orange';
    if (temperature > 2000 and temperature < 3500)
        cout << 'Orange-red';
}


