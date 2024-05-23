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
    void comer();
    void habilidad_esp();
    void moverse();
};

Mamifero::Mamifero(std::string _nombre,
                   int _nivel, int _mana, int _patas)
    : Bestia(_nombre, _nivel, _mana, _patas) { set_raza("mamifero"); }
Mamifero::Mamifero(std::string _nombre,
                   int _nivel, int _mana, int _patas,
                   int _colas, std::string _color_pelo)
    : Bestia(_nombre, _nivel, _mana, _patas)
{
    colas = _colas;
    color_pelo = _color_pelo;
    set_raza("mamifero");
}

#endif