class Plane {
protected:
    float weight;
    float static_ceiling;
    float dynamic_ceiling;
    float cruising_speed;
    float flight_range;
    float flight_duration;
public:
    Plane(int m, int sc, int dc, int cv, int s, int t);
    float get_flight_range();
    float get_cruising_speed();

};
