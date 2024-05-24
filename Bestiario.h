#ifndef BESTIARIO_H
#define BESTIARIO_H

#include <vector>
#include <map>
#include <memory>
#include "Bestia.h"
#include "Ave.h"
#include "Insecto.h"
#include "Reptil.h"
#include "Mamifero.h"

class Bestiario
{
private:
    std::map<std::string, std::vector<Bestia *>> bestias;

public:
    Bestiario() {}
    void registrar_bestia(Bestia *_bestia);
    std::vector<Bestia *> recuperar_bestias();
    std::vector<Bestia *> recuperar_bestias(std::string _raza);
    std::vector<Bestia *> recuperar_bestias(int _nivel);

    void hacer_ejemplos();
    void imprimir_ejemplos();
};

void Bestiario::registrar_bestia(Bestia *_bestia)
{
    bestias[_bestia->get_raza()].push_back(_bestia);
}

std::vector<Bestia *> Bestiario::recuperar_bestias()
{
    std::vector<Bestia *> bestias_regresar;
    for (auto e : bestias)
    {
        for (Bestia *k : e.second)
        {
            bestias_regresar.push_back(k);
        }
    }
    return bestias_regresar;
}
std::vector<Bestia *> Bestiario::recuperar_bestias(std::string _raza)
{
    return bestias[_raza];
}
std::vector<Bestia *> Bestiario::recuperar_bestias(int _nivel)
{
    std::vector<Bestia *> bestias_regresar;
    for (auto e : bestias)
    {
        for (Bestia *k : e.second)
        {
            if (k->get_nivel() == _nivel)
            {
                bestias_regresar.push_back(k);
            }
        }
    }
    return bestias_regresar;
}

void Bestiario::hacer_ejemplos()
{
    Insecto *mite = new Insecto("Mite", 1, 7, 6, 2, true, true);
    Insecto *arach = new Insecto("Arach", 6, 45, 8, 0, false, false);
    Ave *strix = new Ave("Strix", 4, 29, 2, true);
    Ave *chamrosh = new Ave("Chamrosh", 5, 35, 4, false);
    Reptil *salamander = new Reptil("Salamander", 5, 45, 4, false, "fuego", 0);
    Reptil *wyvern = new Reptil("Wyvern", 15, 105, 2, true, "viento", 2);
    Mamifero *canid = new Mamifero("Canid", 7, 48, 4, 1, "azul");
    Mamifero *vulpid = new Mamifero("Vulpid", 6, 42, 4, 3, "naranja");

    bestias[mite->get_raza()].push_back(mite);
    bestias[arach->get_raza()].push_back(arach);
    bestias[strix->get_raza()].push_back(strix);
    bestias[chamrosh->get_raza()].push_back(chamrosh);
    bestias[salamander->get_raza()].push_back(salamander);
    bestias[wyvern->get_raza()].push_back(wyvern);
    bestias[canid->get_raza()].push_back(canid);
    bestias[vulpid->get_raza()].push_back(vulpid);
    std::cout << "Ejemplos Creados" << std::endl;
}

void Bestiario::imprimir_ejemplos()
{

    for (auto r : bestias)
    {
        for (Bestia *b : r.second)
        {
            std::cout << b->habilidad_esp() << std::endl;
        }
    }
}

#endif