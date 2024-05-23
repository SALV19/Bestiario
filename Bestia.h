#ifndef BESTIA_H
#define BESTIA_H

#include <iostream>
#include <vector>

class Bestia
{
private:
    std::string nombre, raza;
    int nivel, mana, patas;

public:
    Bestia(){};
    Bestia(std::string _nombre,
           int _nivel, int _mana, int _patas);
    std::string get_nombre() { return nombre; }
    std::string get_raza() { return raza; }
    int get_nivel() { return nivel; }
    int get_mana() { return mana; }

    void set_nombre(std::string _nombre) { nombre = _nombre; }
    void set_nivel(int _nivel) { nivel = _nivel; }
    void set_mana(int _mana) { mana = _mana; }
    void set_raza(std::string _raza) { raza = _raza; }

    // virtual std::string atacar() = 0;
    // virtual void comer() = 0;
    // virtual void habilidad_esp() = 0;
    // virtual void moverse() = 0;
};

Bestia::Bestia(std::string _nombre,
               int _nivel, int _mana, int _patas)
{
    nombre = _nombre;
    nivel = _nivel;
    mana = _mana;
    patas = _patas;
}

#endif