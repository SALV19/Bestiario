# Bestiario
Problema: 
  Categorizar y acceder a la información de diferentes criaturas a travez de una aplicación estilo bestiario que sea capaz de ordenarlas por especie, nivel, o    acceder a la información de bestias individuales. 

  Esto lo logra mediante un componente Bestiario que almacena toda la información de las diferentes Bestias, que pueden ser Mamíferos, Reptiles, Insectos o Aves. Bestias sería la clase padre de las diferentes tipos de bestia, mienstras que aquellas tienen comportamientos o características similares. Mientras tanto, el Bestiario funcionaría simplemente como un contenedor de las criaturas, y se usaría para acceder a sus elementos. 
  

Donde puede fallar:
  Podría llegar a fallar si se crean diferentes objetos pero con el mismo nombre. O si en la entrada de valores se ingresa un valor diferente al valor esperado de enttrada. Ejemplo: Entrada de nivel es numérico, en cambio, si se ingresa un valor tipo string puede causar que el programa falle.  
