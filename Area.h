#pragma once

#include <string>


class Sunny;
class Cloudy;
class Rainy;


// class of the abstract Area
class Area{
protected:
    std::string _name;
    int water;
    int humidity;
    std::string owner;

public:
    //std::string weathertype;
    virtual Area* waterchange(Sunny* p) = 0;
    virtual Area* waterchange(Cloudy* p)=0;
    virtual Area* waterchange(Rainy* p)=0;
    virtual Area* change()=0;
    virtual ~Area() {}
    Area(){}
    Area(std::string type, std::string owner_,int water_){_name=type;owner=owner_;water=water_;};
    int getwater(){return water;}
    void setwater(int water_){water=water_;}
    std::string getowner(){return owner;}
    void setowner(std::string owner_){owner=owner_;}
    int gethumidity(){return humidity;}
    void sethumidity(int humidity_){humidity=humidity_;}
};

// class of sand
class Plain : public Area
{
public:
    static Plain* instance();
    Area* waterchange(Sunny* p) override;// the humidity id also gonna effect the weather
    Area* waterchange(Cloudy* p) override;
    Area* waterchange(Rainy* p) override;
    Area* change() override;
    Plain(std::string type,std::string owner,int water_):Area(type,owner,water_){}

protected:
    Plain(){}
private:
    static Plain* _instance;
};

// class of grass
class Grassland : public Area
{
public:
    static Grassland* instance();
     Area* waterchange(Sunny* p) override;//in weather function area->area waterhange(sunny* p)
    Area* waterchange(Cloudy* p) override;
    Area* waterchange(Rainy* p) override;
    Area* change() override;
   Grassland(std::string type,std::string owner,int water_):Area(type,owner,water_){}
protected:
    Grassland(){}
private:
    static Grassland* _instance;
};

// class of marsh
class Lake : public Area
{
public:
    static Lake* instance();
     Area* waterchange(Sunny* p) override;
    Area* waterchange(Cloudy* p) override;
    Area* waterchange(Rainy* p) override;
    Area* change() override;
  Lake(std::string type,std::string owner,int water_):Area(type,owner,water_){}
protected:
    Lake(){}
private:
    static Lake* _instance;
};
