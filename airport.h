#pragma once
#include <string>
using namespace std;

class Airport {
    public:
        string ID_;
        string name_;
        string lat_;
        string lon_;
        Airport();
        Airport(string ID, string name, string lat, string lon);
        double rad(double d);
        int distance(Airport a);
};