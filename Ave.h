#ifndef AVE_H
#define AVE_H

#include "Bestia.h"
#include <random>

class Ave : public Bestia
{
private:
    bool vision_nocturna;

public:
    Ave() {}
    Ave(std::string _nombre,
        int _nivel, int _mana, int _patas);
    Ave(std::string _nombre,
        int _nivel, int _mana, int _patas,
        bool _vision_nocturna);

    bool get_pico() { return vision_nocturna; }

    void set_pico(bool _vision_nocturna) { vision_nocturna = _vision_nocturna; }

    std::string atacar();
    void comer();
    void habilidad_esp();
    void moverse();
};

Ave::Ave(std::string _nombre,
         int _nivel, int _mana, int _patas)
    : Bestia(_nombre, _nivel, _mana, _patas) { set_raza("ave"); }
Ave::Ave(std::string _nombre,
         int _nivel, int _mana, int _patas,
         bool _vision_nocturna)
    : Bestia(_nombre, _nivel, _mana, _patas)
{
    vision_nocturna = _vision_nocturna;
    set_raza("ave");
}

std::string Ave::atacar()
{
}
void Ave::comer()
{
}
void Ave::habilidad_esp()
{
}
void Ave::moverse()
{
}

#endif
