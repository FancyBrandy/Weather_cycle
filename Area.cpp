#include "Area.h"
#include "Weather.h"

using namespace std;

// implementation of class Sand
Plain* Plain::_instance = nullptr;
Plain* Plain::instance()
{
    if(_instance == nullptr) {
        _instance = new Plain();
    }
    return _instance;
}
Area* Plain::change()
{
    if(water>20)
        return Grassland::instance();
        else
            return Plain::instance();
}


Area* Plain::waterchange(Sunny* p)
{
        humidity+=5;
        water-=3;
            p->changeweather(humidity);

    return this;
}
Area* Plain::waterchange(Cloudy* p)
{
        humidity+=5;
        water-=1;
        p->changeweather(humidity);

    return this;
}
Area* Plain::waterchange(Rainy* p)
{
        humidity+=5;
        water+=20;
        p->changeweather(humidity);

    return this;
}


// implementation of class Grass
Grassland* Grassland::_instance = nullptr;
Grassland* Grassland::instance()
{
    if(_instance == nullptr) {
        _instance = new Grassland();
    }
    return _instance;
}
Area* Grassland::change()
{
    if (water>50)
        return Lake::instance();
    else if(water<16)
        return Plain::instance();
        else
            return Grassland::instance();
}

Area* Grassland::waterchange(Sunny* p)
{
       humidity+=10;
        water-=6;
        p->changeweather(humidity);

    return this;
}
Area* Grassland::waterchange(Cloudy* p)
{
       humidity+=10;
        water-=2;
        p->changeweather(humidity);

    return this;
}
Area* Grassland::waterchange(Rainy* p)
{
        humidity+=10;
        water+=15;
        p->changeweather(humidity);

    return this;
}


// implementation of class Marsh
Lake* Lake::_instance = nullptr;
Lake* Lake::instance()
{
    if(_instance == nullptr) {
        _instance = new Lake();
    }
    return _instance;
}
Area* Lake::change()
{
    if(water<51)
        return Grassland::instance();
    else
            return Lake::instance();
}

Area* Lake::waterchange(Sunny* p)
{
        humidity+=15;
        water-=10;
p->changeweather(humidity);
    return this;
}
Area* Lake::waterchange(Cloudy* p)
{
        humidity+=15;
        water-=3;
p->changeweather(humidity);
    return this;
}
Area* Lake::waterchange(Rainy* p)
{
       // humidity+=15;
        water+=20;
p->changeweather(humidity);
    return this;
}



