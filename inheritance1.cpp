class ElasticMaterial: public Material{
    private:
        float E;
    public:
        ElasticMaterial(float elasticModulus){
            E = elasticModulus;
        }
        float getStress(float strain){
            return(this->E * strain);
        }
};

class PlasticMaterial: public Material{
    private:
        float E;
        float lim;
    public:
        PlasticMaterial(float elasticModulus, float strainLimit){
            E = elasticModulus;
            lim = strainLimit;
        }
        float getStress(float strain){
            if (strain <= this->lim) return(this->E * strain);
            return (this->E * lim);
        }
};
