#ifndef INSECTO_H
#define INSECTO_H

#include "Bestia.h"
#include <iostream>

class Insecto : public Bestia
{
private:
    bool caparazon, aguijon;
    int alas;

public:
    Insecto() {}
    Insecto(std::string _nombre,
            int _nivel, int _mana, int _patas);
    Insecto(std::string _nombre,
            int _nivel, int _mana, int _patas,
            int _alas, bool _caparazon, bool _aguijon);

    bool get_caparazon() { return caparazon; }
    bool get_aguijon() { return aguijon; }
    int get_alas() { return alas; }

    void set_caparazon(bool _caparazon) { caparazon = _caparazon; }
    void set_aguijon(bool _aguijon) { aguijon = _aguijon; }
    void set_alas(int _alas) { alas = _alas; }

    std::string atacar();
    std::string comer();
    std::string habilidad_esp();
    std::string moverse();

    std::string get_stats();
};

Insecto::Insecto(std::string _nombre,
                 int _nivel, int _mana, int _patas)
    : Bestia(_nombre, _nivel, _mana, _patas) { set_raza("insecto"); }
Insecto::Insecto(std::string _nombre,
                 int _nivel, int _mana, int _patas,
                 int _alas, bool _caparazon, bool _aguijon)
    : Bestia(_nombre, _nivel, _mana, _patas)
{
    alas = _alas;
    caparazon = _caparazon;
    aguijon = _aguijon;
    set_raza("insecto");
}

std::string Insecto::atacar()
{
    std::string ataque = get_nombre() + " puede usar su mandibula para morder";
    return ataque;
}
std::string Insecto::comer()
{
    std::string comida = get_nombre() + " come plantas y algunos insectos más pequeños.";
    return comida;
}
std::string Insecto::habilidad_esp()
{
    if (aguijon && caparazon)
    {
        return get_nombre() + " es resistente a los ataques gracias a su caparazon y tiene un aguijón capaz de paralizar a su presa";
    }
    else if (caparazon)
    {
        return get_nombre() + " es resistente a los ataques gracias a su caparazon\n";
    }
    else if (aguijon)
    {
        return get_nombre() + " tiene un aguijón capaz de paralizar a su presa\n";
    }
    else if (!caparazon && !aguijon)
    {
        return get_nombre() + " no tiene habilidades especiales";
    }
    return "";
}
std::string Insecto::moverse()
{
    if (alas >= 2)
    {
        return get_nombre() + " puede caminar y escalar por árboles y es capaz de volar";
    }
    return get_nombre() + " puede caminar y escalar por árboles";
}

std::string Insecto::get_stats()
{
    return Bestia::get_stats() + "\nCaparazon: " + std::to_string(caparazon) + "\nAguijon: " + std::to_string(aguijon) + "\nAlas:" + std::to_string(alas);
}
#endif