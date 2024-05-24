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

    bool get_vision_nocturna() { return vision_nocturna; }

    void set_vision_nocturna(bool _vision_nocturna) { vision_nocturna = _vision_nocturna; }

    std::string atacar();
    std::string comer();
    std::string habilidad_esp();
    std::string moverse();

    std::string get_stats();
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
    std::string ataque = get_nombre() + " vuela en picada para dar un zarpazo.";
    return ataque;
}
std::string Ave::comer()
{
    std::string comida = get_nombre() + " le gusta comer carne y algunas semillas.";
    return comida;
}
std::string Ave::habilidad_esp()
{
    std::string habilidad;
    if (vision_nocturna)
    {
        habilidad = get_nombre() + " puede usar vision nocturna para cazar por la noche.";
    }
    else
    {
        habilidad = get_nombre() + " no tiene visión nocturna para ver por la noche";
    }
    return habilidad;
}
std::string Ave::moverse()
{
    if (get_patas() >= 4)
    {
        return get_nombre() + " puede volar por los aires y puede correr a altas velocidades.";
    }
    return get_nombre() + " puede volar por los aires";
}
std::string Ave::get_stats()
{
    return Bestia::get_stats() + "\nVision Nocturna: " + std::to_string(vision_nocturna);
}

#endif
