#include <iostream>
#include <vector>

#include "Bestiario.h"

/* Crea bestia
    Permite al usuario a definir una nueva bestia que será asignada al bestiario.
    Al elegir una raza va a hacer las preguntas pertinentes para cubrir todas las características que tiene
    dicha especie antes de mandar a llamar el constructor indicado desde la clase bestiario.
*/
void crear_bestia(Bestiario *m_bestiario)
{
    std::string nombre, color, elemento;
    int raza, nivel, mana, patas, colas, alas, vn_verificacion, escamas_verificacion,
        caparazon_verificacion, aguijon_verificacion;
    bool caparazon, aguijon, vn, escamas;

    std::cout << "Elige una raza" << std::endl;
    std::cout << "1. Mamifero" << std::endl
              << "2. Ave" << std::endl
              << "3. Reptil" << std::endl
              << "4. Insecto" << std::endl;

    std::cin >> raza;

    std::cout << "Nombre de la especie a registrar: ";
    std::cin >> nombre;
    std::cout << "Nivel de la criatura: ";
    std::cin >> nivel;
    std::cout << "Mana de la criatura: ";
    std::cin >> mana;
    std::cout << "Numero de patas: ";
    std::cin >> patas;

    switch (raza)
    {
    case 1:
        std::cout << std::endl
                  << "Numero de colas: ";
        std::cin >> colas;
        std::cout << std::endl
                  << "Color: ";
        std::cin >> color;

        m_bestiario->crear_bestia(nombre, nivel, mana, patas, colas, color);
        break;
    case 2:
        std::cout << "Cuenta con vision nocturna: " << std::endl
                  << "1. Si" << std::endl
                  << "2. No" << std::endl;
        std::cin >> vn_verificacion;

        if (vn_verificacion == 1)
        {
            vn = true;
        }
        else
        {
            vn = false;
        }
        m_bestiario->crear_bestia(nombre, nivel, mana, patas, vn);

        break;
    case 3:
        std::cout << "Cual es el elemento que tiene: ";
        std::cin >> elemento;
        std::cout << "Cuantas alas tiene (pueden ser 0): ";
        std::cin >> alas;
        std::cout << "Cuenta con escamas: " << std::endl
                  << "1. Si" << std::endl
                  << "2. No" << std::endl;
        std::cin >> escamas_verificacion;
        if (escamas_verificacion == 1)
        {
            escamas = true;
        }
        else
        {
            escamas = false;
        }

        m_bestiario->crear_bestia(nombre, nivel, mana, patas, escamas, elemento, alas);
        break;
    case 4:
        std::cout << "Cuantas alas tiene: ";
        std::cin >> alas;
        std::cout << "Cuenta con caparazon: " << std::endl
                  << "1. Si" << std::endl
                  << "2. No" << std::endl;
        std::cin >> caparazon_verificacion;
        std::cout << "Cuenta con aguijon: " << std::endl
                  << "1. Si" << std::endl
                  << "2. No" << std::endl;
        std::cin >> aguijon_verificacion;

        if (caparazon_verificacion == 1)
        {
            caparazon = true;
        }
        else
        {
            caparazon = false;
        }
        if (aguijon_verificacion == 1)
        {
            aguijon = true;
        }
        else
        {
            aguijon = false;
        }

        m_bestiario->crear_bestia(nombre, nivel, mana, patas, alas, caparazon, aguijon);
        break;
    }
    return;
}

/* Ver Bestias
    Imprime en una lista el nombre de todas las especies en el bestiario.
*/
std::vector<Bestia *> ver_bestias(Bestiario *m_bestiario)
{
    std::vector<Bestia *> bestias = m_bestiario->recuperar_bestias();
    if (bestias.size() <= 0)
    {
        std::cout << "No hay bestias registradas." << std::endl;
        return bestias;
    }
    for (int i = 0; i < bestias.size(); i++)
    {
        std::cout << std::endl
                  << i + 1 << ". " << bestias[i]->get_nombre() << " - " << bestias[i]->get_raza();
    }
    std::cout << std::endl;
    return bestias;
}

/* Ver Bestias Especie
    Te permite seleccionar una de las especies del bestiario e imprime en una lista sus nombres
*/

void ver_bestias_especie(Bestiario *m_bestiario)
{
    int especie;
    std::string nombre;
    std::cout << "Que especie quisieras conocer?" << std::endl
              << "1. Mamifero" << std::endl
              << "2. Ave" << std::endl
              << "3. Reptil" << std::endl
              << "4. Insecto" << std::endl;
    std::cin >> especie;
    switch (especie)
    {
    case 1:
        nombre = "mamifero";
        break;
    case 2:
        nombre = "ave";
        break;
    case 3:
        nombre = "reptil";
        break;
    case 4:
        nombre = "insecto";
        break;
    }
    std::vector<Bestia *> bestias = m_bestiario->recuperar_bestias(nombre);
    if (bestias.size() <= 0)
    {
        std::cout << "No se encuentras bestias registradas de la especie: " << nombre << std::endl;
        return;
    }
    for (int i = 0; i < bestias.size(); i++)
    {
        std::cout << std::endl
                  << i + 1 << ". " << bestias[i]->get_nombre();
    }
    std::cout << std::endl;
}

/* Ver Bestias Nivel
    Imprime el nombre de todas las bestias registradas con el nivel indicado
*/
void ver_bestias_nivel(Bestiario *m_bestiario)
{
    int nivel;
    std::cout << "Elige el nivel de las bestias que te interesa: ";
    std::cin >> nivel;
    std::vector<Bestia *> bestias = m_bestiario->recuperar_bestias(nivel);
    if (bestias.size() <= 0)
    {
        std::cout << "No hay bestias de nivel: " << nivel << std::endl;
        return;
    }
    for (int i = 0; i < bestias.size(); i++)
    {
        std::cout << std::endl
                  << i + 1 << ". " << bestias[i]->get_nombre();
    }
    std::cout << std::endl;
}

/* Ver estadisticas
    Llama a la función ver_bestias para conseguir el arreglo de objetos tipo bestia almacenados en el bestiario, posteriormente
    pregunta por la posición de la bestia de interés para mandar a llamar su función que dá a conocer las estadísticas de esta criatura
*/
void ver_estadisticas(Bestiario *m_bestiario)
{
    int bestia;
    std::vector<Bestia *> bestias = ver_bestias(m_bestiario);
    std::cout << "Bestias recuperadas";

    if (bestias.size() <= 0)
    {
        std::cout << "No hay bestias registradas" << std::endl;
        return;
    }

    std::cout << "Selecciona una de las especies que le interesaria conocer: " << std::endl;
    std::cin >> bestia;
    bestia--;

    std::cout << std::endl
              << bestias[bestia]->get_stats();
    std::cout << std::endl;
}
/*
    Hacer Ejemplos:
    Crea dos objetos de cada especie dentro del objeto bestiario, e imprime las habilidades de cada una.
    Posteriormente muestra el fincionamiento de las funciones de bestiario, que son:
        Imprimir todas las bestias de cierto nivel (6).
        Imprimir todas las bestias registradas de raza "ave".
        Imprime las estadísticas de una de las criaturas dentro del Bestiario.
*/
void hacer_ejemplos(Bestiario *m_bestiario)
{
    m_bestiario->hacer_ejemplos();
    m_bestiario->imprimir_ejemplos();

    std::cout << std::endl;

    std::vector<Bestia *> nivel_6 = m_bestiario->recuperar_bestias(6);
    for (Bestia *b : nivel_6)
    {
        std::cout << b->get_nombre() << " es nivel 6" << std::endl;
    }
    std::vector<Bestia *> aves = m_bestiario->recuperar_bestias("ave");
    for (Bestia *b : aves)
    {
        std::cout << b->get_nombre() << " es tipo ave" << std::endl;
    }

    std::cout << std::endl
              << aves[0]->get_stats()
              << std::endl;
}

int main()
{
    Bestiario m_bestiario;

    while (true)
    {
        std::cout << std::endl
                  << "Bienvenido al bestiario donde puedes anadir diferentes cruiaturas de diferentes especies," << "con sus atributos y descripcion" << std::endl;
        std::cout << "Para empezar puedes elegir que deseas hacer: " << std::endl
                  << "1. Registrar una nueva bestia" << std::endl
                  << "2. Ver bestias registradas" << std::endl
                  << "3. Ver las bestias de cierta raza" << std::endl
                  << "4. Ver las bestias de cierto nivel" << std::endl
                  << "5. Ver estadisticas de cierta especie" << std::endl
                  << "6. Hacer ejemplos" << std::endl
                  << "7. Salir" << std::endl;
        int opcion;
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            crear_bestia(&m_bestiario);
            break;
        case 2:
            ver_bestias(&m_bestiario);
            break;
        case 3:
            ver_bestias_especie(&m_bestiario);
            break;
        case 4:
            ver_bestias_nivel(&m_bestiario);
            break;
        case 5:
            ver_estadisticas(&m_bestiario);
            break;
        case 6:
            hacer_ejemplos(&m_bestiario);
            break;
        case 7:
            std::cout << "Gracias" << std::endl;
            return 0;
        }
    }

    return 0;
}