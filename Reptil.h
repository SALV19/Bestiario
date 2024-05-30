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
    std::string comer();
    std::string habilidad_esp();
    std::string moverse();

    std::string get_stats();
};

Reptil::Reptil(std::string _nombre,
               int _nivel, int _mana, int _patas)
    : Bestia(_nombre, _nivel, _mana, _patas) { raza = "reptil"; }
Reptil::Reptil(std::string _nombre,
               int _nivel, int _mana, int _patas,
               bool _escamas, std::string _elemento, int _alas)
    : Bestia(_nombre, _nivel, _mana, _patas)
{
    escamas = _escamas;
    elemento = _elemento;
    alas = _alas;
    raza = "reptil";
}

std::string Reptil::atacar()
{
    std::string atacar = nombre + " tiene una grán mordida y puede usar " + elemento;
    return atacar;
}
std::string Reptil::comer()
{
    std::string comer = nombre + " come insectos pequeños y pedazos de carne que pueda obtener";
    return comer;
}
std::string Reptil::habilidad_esp()
{
    if (alas > 0 && escamas)
    {
        return nombre + " puede volar por los aires y es resistente físicamente a diferentes cosas";
    }
    else if (alas > 0)
    {
        return nombre + " puede volar por los aires";
    }
    else if (escamas)
    {
        return nombre + " es resistente físicamente a diferentes cosas";
    }
    return nombre + " es resistente a " + elemento;
}
std::string Reptil::moverse()
{
    if (patas >= 4)
    {
        return nombre + "\nPuede correr a muy alta velocidad";
    }
    if (alas >= 2)
    {
        return nombre + "\nEs capaz de volar por los aires.";
    }
    return nombre + "\n";
}

std::string Reptil::get_stats()
{
    return Bestia::get_stats() + "\nEscamas" + std::to_string(escamas) + "\nAlas" + std::to_string(alas) + "\nElemento" + elemento;
}

#endif