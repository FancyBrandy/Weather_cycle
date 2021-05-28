#include "Area.h"
#include "Weather.h"
using namespace std;
void Weather::changeweather(int hum)
{
    if(hum>70)
        _name="Rainy";
    else if((hum>40)&&(hum<=70))
    {
        rain_chance=(hum-30)*0.033;
        _name="Cloudy";
    }
    else
        _name="Sunny";
}
