#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Area.h"
#include "Weather.h"
using namespace std;

void create(const string &str, vector<Area*> &areas, Weather* &weather)
{
    ifstream f(str);
    if(f.fail()) { cout << "Wrong file name!\n"; exit(1);}

    int n; f >> n;
    areas.resize(n);
    for( int i=0; i<n; i++ ){
        string mr; string name; char ch;int water_;
        f >>mr>>name>>ch>>water_;
        switch(ch){
            case 'P' : areas[i] = new Plain("Plain",name,water_); break;
            case 'G' : areas[i] = new Grassland("Grassland",name,water_); break;
            case 'L' : areas[i] = new Lake("Lake",name,water_); break;//Lake::instance(); areas[i]->setowner(name); areas[i]->setwater(water_); cout<<3; break;
        }
    }

    int m; f >> m;
    for(int i=0;i<n;i++)
    {
        areas[i]->sethumidity(m);
    }
        if(m>70)
        weather=new Rainy("Rainy");
        else if((m>40)&&(m<=70))
            weather=new Cloudy("Cloudy");
        else
        weather=new Sunny("Sunny");
}

#define NORMAL_MODE
#ifdef NORMAL_MOD


int main()
{
    vector<Area*> areas;
    Weather* weather;
    create("input.txt",areas,weather);

    for(int i=0;i<10;i++)//10 stimulation
    {
        //we first need to see what weather we r dealing with and weather is only related to humidity.
    if(weather->getweather()=="Rainy")//create the constructor according to the humidity in the air.
    {
        for(int j=0;j<areas.size();j++)
        {

            new Rainy("Rainy");
            Rainy("Rainy").weatherchange(areas[j]);//in weatherchange function we call the waterchange function and we change the attributes in the Area class accordingly

            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }

    }
    else if(weather->getweather()=="Cloudy")
    {
        for(int j=0;j<areas.size();j++)
        {

            new Cloudy("Cloudy");
            Cloudy("Cloudy").weatherchange(areas[j]);
            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());

        }
    }
    else
    {
        for(int j=0;j<areas.size();j++)
        {

           new Sunny("Sunny");
        Sunny("Sunny").weatherchange(areas[j]);//weather change is going to call the water change function in Area
        //and it is gonna increase the water humidity and change the type of weather according to the humidity

          Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }
    }

}
int maxind=0;
for(int i=0;i<areas.size();i++)
{
     if(areas[i]->getwater()>areas[maxind]->getwater())
        {maxind=i;}
}

cout<<areas[maxind]->getowner()<<endl;

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("just one owner", "inp1.txt")
{
    vector<Area*> areas;
    Weather* weather;
    create("inp1.txt",areas,weather);
    for(int i=0;i<10;i++)//10 stimulation
    {
        //we first need to see what weather we r dealing with and weather is only related to humidity.
    if(weather->getweather()=="Rainy")//create the constructor according to the humidity in the air.
    {
        for(int j=0;j<areas.size();j++)
        {

            new Rainy("Rainy");
            Rainy("Rainy").weatherchange(areas[j]);//in weatherchange function we call the waterchange function and we change the attributes in the Area class accordingly

            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }

    }
    else if(weather->getweather()=="Cloudy")
    {
        for(int j=0;j<areas.size();j++)
        {

            new Cloudy("Cloudy");
            Cloudy("Cloudy").weatherchange(areas[j]);
            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());

        }
    }
    else
    {
        for(int j=0;j<areas.size();j++)
        {

           new Sunny("Sunny");
        Sunny("Sunny").weatherchange(areas[j]);//weather change is going to call the water change function in Area
        //and it is gonna increase the water humidity and change the type of weather according to the humidity

          Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }
    }

}
int maxind=0;
for(int i=0;i<areas.size();i++)
{
     if(areas[i]->getwater()>areas[maxind]->getwater())
        {maxind=i;}
}

    CHECK(areas[maxind]->getowner()=="Lee");

}

TEST_CASE("just one round of stimulation", "inp2.txt")
{
    vector<Area*> areas;
    Weather* weather;
    create("inp2.txt",areas,weather);
    if(weather->getweather()=="Rainy")//create the constructor according to the humidity in the air.
    {
        for(int j=0;j<areas.size();j++)
        {

            new Rainy("Rainy");
            Rainy("Rainy").weatherchange(areas[j]);//in weatherchange function we call the waterchange function and we change the attributes in the Area class accordingly

            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }

    }
    else if(weather->getweather()=="Cloudy")
    {
        for(int j=0;j<areas.size();j++)
        {

            new Cloudy("Cloudy");
            Cloudy("Cloudy").weatherchange(areas[j]);
            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());

        }
    }
    else
    {
        for(int j=0;j<areas.size();j++)
        {

           new Sunny("Sunny");
        Sunny("Sunny").weatherchange(areas[j]);//weather change is going to call the water change function in Area
        //and it is gonna increase the water humidity and change the type of weather according to the humidity

          Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }
    }
int maxind=0;
for(int i=0;i<areas.size();i++)
{
     if(areas[i]->getwater()>areas[maxind]->getwater())
        {maxind=i;}
}

    CHECK(areas[maxind]->getowner()=="Tean");

}

TEST_CASE("multiple land but no stimulation", "inp3.txt")
{
    vector<Area*> areas;
    Weather* weather;
    create("inp3.txt",areas,weather);
    while(0)
    {

    if(weather->getweather()=="Rainy")//create the constructor according to the humidity in the air.
    {
        for(int j=0;j<areas.size();j++)
        {

            new Rainy("Rainy");
            Rainy("Rainy").weatherchange(areas[j]);//in weatherchange function we call the waterchange function and we change the attributes in the Area class accordingly

            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }

    }
    else if(weather->getweather()=="Cloudy")
    {
        for(int j=0;j<areas.size();j++)
        {

            new Cloudy("Cloudy");
            Cloudy("Cloudy").weatherchange(areas[j]);
            Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());

        }
    }
    else
    {
        for(int j=0;j<areas.size();j++)
        {

           new Sunny("Sunny");
        Sunny("Sunny").weatherchange(areas[j]);//weather change is going to call the water change function in Area
        //and it is gonna increase the water humidity and change the type of weather according to the humidity

          Area* flag=areas[j];
            areas[j]=areas[j]->change();
            areas[j]->setowner(flag->getowner());
            areas[j]->setwater(flag->getwater());
            areas[j]->sethumidity(flag->gethumidity());
        }
    }
}
int maxind=0;
for(int i=0;i<areas.size();i++)
{
     if(areas[i]->getwater()>areas[maxind]->getwater())
        {maxind=i;}
}

    CHECK(areas[maxind]->getowner()=="Brunner");

}

#endif // NORMAL_MODE*/


