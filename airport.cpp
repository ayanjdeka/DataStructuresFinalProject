#include "airport.h"
#include <math.h>
#include <iostream>

Airport::Airport() {

}

Airport::Airport(string ID, string name, string lat, string lon) {
    ID_ = ID;
    name_ = name;
    lat_ = lat;
    lon_ = lon;
}

double Airport::rad(double d) {
	return d * M_PI / 180.0;
}

int Airport::distance(Airport a) {
	double lonfirst = stof(lon_);
	double lonsecond = stof(a.lon_);
	double latfirst  = stof(lat_);
	double latsecond  = stof(a.lat_);

	double d =  pow(sin(rad(latfirst - latsecond) / 2), 2) +
				pow(sin(rad(lonfirst - lonsecond) / 2), 2) *
				cos(rad(latsecond)) * cos(rad(latfirst));
	return (int) (2.0 * 3956 * asin(sqrt(d)));
}