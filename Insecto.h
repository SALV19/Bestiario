#ifndef INSECTO_H
#define INSECTO_H

#include "Bestia.h"

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
    void comer();
    void habilidad_esp();
    void moverse();
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

#endif