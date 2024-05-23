#include <iostream>
#include <vector>

#include "Bestiario.h"

int main()
{
    Bestiario m_bestiario;
    m_bestiario.hacer_ejemplos();
    std::vector<Bestia *> m_bestias = m_bestiario.recuperar_bestias();
    for (Bestia *e : m_bestias)
    {
        std::cout << e->get_nombre() << std::endl;
    }

    return 0;
}