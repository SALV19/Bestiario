#ifndef MAMIFERO_H
#define MAMIFERO_H

#include "Bestia.h"
#include <iostream>

class Mamifero : public Bestia
{
private:
    int colas;
    std::string color_pelo;

public:
    Mamifero();
    Mamifero(std::string _nombre,
             int _nivel, int _mana, int _patas);
    Mamifero(std::string _nombre,
             int _nivel, int _mana, int _patas,
             int _colas, std::string _color_pelo);

    int get_colas() { return colas; }
    std::string get_color_pelo() { return color_pelo; }

    void set_colas(int _colas) { colas = _colas; }
    void set_color_pelo(std::string _color) { color_pelo = _color; }

    std::string atacar();
    std::string comer();
    std::string habilidad_esp();
    std::string moverse();

    std::string get_stats();
};

Mamifero::Mamifero(std::string _nombre,
                   int _nivel, int _mana, int _patas)
    : Bestia(_nombre, _nivel, _mana, _patas) { raza = "mamifero"; }
Mamifero::Mamifero(std::string _nombre,
                   int _nivel, int _mana, int _patas,
                   int _colas, std::string _color_pelo)
    : Bestia(_nombre, _nivel, _mana, _patas)
{
    colas = _colas;
    color_pelo = _color_pelo;
    raza = "mamifero";
}

std::string Mamifero::atacar()
{
    std::string ataque = nombre + " tiene una mordida muy poderosa";
    return ataque;
}
std::string Mamifero::comer()
{
    std::string comida = nombre + " come carne.";
    return comida;
}
std::string Mamifero::habilidad_esp()
{
    std::string habilidad = nombre + " tiene " + std::to_string(colas) + " colas y es de color " + color_pelo;
    return habilidad;
}
std::string Mamifero::moverse()
{
    std::string mover = nombre + " puede correr muy rapido y es hagil";
    return mover;
}

std::string Mamifero::get_stats()
{
    return Bestia::get_stats() + "\nColas" + std::to_string(colas) + "\nColor" + color_pelo;
}

#endif