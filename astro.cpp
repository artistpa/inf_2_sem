#include <iostream>
#include <cmath>
using namespace std;

class astro_object {
protected:
    float mass;
    float volume;
    float temperature;
public:
    astro_object(float m, float v, float T){
        mass = m;
        temperature = T;
    }
    void get_mass(){
    cout << 'Mass: ' << mass;
    return(mass);
    }
    void get_volume(){
    cout << 'Volume: ' << volume;
    return(volume);
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
};
class Universe: public astro_object{
protected:
    float age;
    float radius;
public:
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
};
class Planet: public astro_object{
protected:
    float t_day;
    float T_year;
    float Sun_distance;
    float diameter;
    float satellite_number;
    bool atmosphere;
    bool Solar_system;
public:
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
};
class Star: public Universe{
protected:
    float luminosity;
public:
    Star(float L){
        luminosity = L;
    }
    void get_type(){
        if (radius > 6950000000 and radius < 6950000000 and luminosity > 3.827 * 10260 and luminosity < 3.827 * 1026000)
            cout << 'Гигант';
        if (mass > 2 * pow(10, 30) * 0.012 and mass < 2 * pow(10, 30) * 0.0767)
            cout << 'Карлик';
    }
};
class Galaxy: public Star{
protected:
    float thickness_of_disk;
public:
    Galaxy(float td){
        thickness_of_disk = td;
    }
    float get_removal_rate (float R){
        return(2.2 * pow(10,-18) * R);
    }
    float get_rot_speed(){
        return(pow(mass * 6.67 * pow(10,-11) / radius / 2,0.5));
    }
};
class Nebula: public astro_object{
protected:
    float concentration;
    char* type;
public:
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
};


