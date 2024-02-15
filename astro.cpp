#include <iostream>
#include <cmath>
#include "Astro.hpp"
using namespace std;

astro_object(float m, float T){
    mass = m;
    temperature = T;
}

float get_mass(){
    cout << 'Mass: ' << mass;
    return(mass);
}

float get_temperature(){
    cout << 'Temperature: ' << temperature;
    return(temperature);
}

float get_density(){
    cin >> volume;
    cout << 'Average density: ' << mass / volume;
    return(mass / volume);
}

Universe(float a, float r){
    age = a;
    radius = r;
}

float get_age(){
    return(age);
}

float get_radius(){
    return(radius);
}

Planet(float d, float s, float t, float T, float n, bool a, bool b){
    diameter = d;
    Sun_distance = s;
    t_day = t;
    T_year = T;
    satellite_number = n;
    atmosphere = a;
    Solar_system = b;
}

float get_volume(){
    return(4 * 3.14 * (diameter/2) * (diameter/2) * (diameter/2) / 3);
}

float orbital_speed(){
    if (Solar_system == true)
        return(2 * 3.14 * Sun_distance / T_year);
        return 0;
}

float own_rotation_speed(){
    return(2* 3.14 / t_day);
}

Star(float L){
    luminosity = L;
}

void get_type(){
    if (radius > 6950000000 and radius < 6950000000 and luminosity > 3.827 * 10260 and luminosity < 3.827 * 1026000)
        cout << 'Гигант';
    if (mass > 2 * pow(10, 30) * 0.012 and mass < 2 * pow(10, 30) * 0.0767)
        cout << 'Карлик';
}

Galaxy(float td){
    thickness_of_disk = td;
}

float get_removal_rate (float R){
    return(2.2 * pow(10,-18) * R);
}

float get_rot_speed(){
    return(pow(mass * 6.67 * pow(10,-11) / radius / 2,0.5));
}

Nebula(float c){
    concentration = c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> *(type + i);
}

float get_particle_number() {
    cin >> volume;
    return(volume * concentration);
}

void get_true_colour(){
    if (temperature > 30000 and temperature < 60000)
        cout << 'Голубой';
    if (temperature > 10000 and temperature < 30000)
        cout << 'Бело-голубой';
    if (temperature > 7500 and temperature < 10000)
        cout << 'Белый';
    if (temperature > 6000 and temperature < 7500)
        cout << 'Жёлто-белый';
    if (temperature > 5000 and temperature < 6000)
        cout << 'Жёлтый';
    if (temperature > 3500 and temperature < 5000)
        cout << 'Оранжевый';
    if (temperature > 2000 and temperature < 3500)
        cout << 'Красный';
}

void get_visible_colour(){
    if (temperature > 30000 and temperature < 60000)
        cout << 'Голубой';
    if (temperature > 10000 and temperature < 30000)
        cout << 'Бело-голубой и белый';
    if (temperature > 7500 and temperature < 10000)
        cout << 'Белый';
    if (temperature > 6000 and temperature < 7500)
        cout << 'Белый';
    if (temperature > 5000 and temperature < 6000)
        cout << 'Жёлтый';
    if (temperature > 3500 and temperature < 5000)
        cout << 'Желтовато-оранжевый';
    if (temperature > 2000 and temperature < 3500)
        cout << 'Оранжево-красный';
}


