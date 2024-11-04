#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar==0) return 0;

    unsigned int ilosc_Zaglowcow = 0;

    Stocznia stocznia{};
    while (stocznia.getTotalCap() < towar){
        Statek* s1 = stocznia();

        if(dynamic_cast<Zaglowiec*>(s1)){
            ilosc_Zaglowcow = ilosc_Zaglowcow +1;
        }

        unsigned int transportowanyTowar = s1->transportuj();
        delete s1;
    }
    return ilosc_Zaglowcow;
}