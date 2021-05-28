#pragma once

#include <string>


class Area;
class Weather{
protected:
    std::string _name;
public:
    int rain_chance;
    std::string name() const { return _name; }//the getter of the name of the weather
    virtual void weatherchange(Area* &area) = 0;
    void changeweather(int hum);//the effect that the area humidity have on the weather
    virtual ~Weather () {}
    Weather (const std::string &str) :_name(str) {}
    std::string getweather(){return _name;}
};


class Sunny : public Weather {
public:
    Sunny(const std::string &str) : Weather(str){}//constructor inheritance
    void weatherchange(Area* &area) override {
            area=area->waterchange(this);
    }
};

// class of Dune beetles
class Cloudy : public Weather {
public:
    Cloudy(const std::string &str) : Weather(str){}
    void weatherchange(Area* &area) override {
        area=area->waterchange(this);
    }
};

class Rainy : public Weather {
public:
    Rainy(const std::string &str) : Weather(str){}
    void weatherchange(Area* &area) override{
        area=area->waterchange(this);
    }
};

