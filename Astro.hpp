class astro_object {
protected:
    float mass;
    float volume;
    float temperature;
public:
    astro_object(float m, float v, float T);
    void get_mass();
    void get_volume();
    void get_temperature();
    void get_density();
};
