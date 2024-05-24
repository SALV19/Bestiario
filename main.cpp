#include <iostream>
#include <vector>

#include "Bestiario.h"

int main()
{
    Bestiario m_bestiario;
    m_bestiario.hacer_ejemplos();
    m_bestiario.imprimir_ejemplos();
    std::cout << std::endl;

    std::vector<Bestia *> nivel_6 = m_bestiario.recuperar_bestias(6);
    for (Bestia *b : nivel_6)
    {
        std::cout << b->get_nombre() << " es nivel 6" << std::endl;
    }
    std::vector<Bestia *> aves = m_bestiario.recuperar_bestias("ave");
    for (Bestia *b : aves)
    {
        std::cout << b->get_nombre() << " es tipo ave" << std::endl;
    }

    std::cout << std::endl
              << aves[0]->get_stats();

    return 0;
}