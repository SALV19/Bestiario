#ifndef REPTIL_H
#define REPTIL_H

#include "Bestia.h"
#include <iostream>

class Reptil : public Bestia
{
private:
    bool escamas;
    int alas;
    std::string elemento;

public:
    Reptil();
    Reptil(std::string _nombre,
           int _nivel, int _mana, int _patas);
    Reptil(std::string _nombre,
           int _nivel, int _mana, int _patas,
           bool _escamas, std::string _elemento, int _alas);

    int get_escamass() { return escamas; }
    std::string get_elemento() { return elemento; }

    void set_escamas(int _escamas) { escamas = _escamas; }
    void set_elemento(std::string _elemento) { elemento = _elemento; }

    std::string atacar();
    void comer();
    void habilidad_esp();
    void moverse();
};

Reptil::Reptil(std::string _nombre,
               int _nivel, int _mana, int _patas)
    : Bestia(_nombre, _nivel, _mana, _patas) { set_raza("reptil"); }
Reptil::Reptil(std::string _nombre,
               int _nivel, int _mana, int _patas,
               bool _escamas, std::string _elemento, int _alas)
    : Bestia(_nombre, _nivel, _mana, _patas)
{
    escamas = _escamas;
    elemento = _elemento;
    alas = _alas;
    set_raza("reptil");
}
#endif