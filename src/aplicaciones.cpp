/* 5088530 */

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"


TCadena insertarAlFinal(nat natural, double real, TCadena cad) {
  return cadenaSiguiente(insertarAlInicio(natural,real,cad));
}

TCadena removerPrimero(TCadena cad) {
  return removerDeCadena(natInfo(primeroEnCadena(cad)),cad);
}


TCadena copiaCadena(TCadena cad) {
  if (cad != NULL) {
    TCadena aux = cad;
    TCadena nueva = NULL;
    do {
     nueva = insertarAlFinal(natInfo(primeroEnCadena(aux)),realInfo(primeroEnCadena(aux)),nueva);
     aux = cadenaSiguiente(aux);
    } while (aux != cad);
    return nueva;
  }
  else {return NULL;}
}

void auxiliarIterador(TIterador iter, TIterador nuevo) {
  if (estaDefinidaActual(iter)) {
    nat n = actualEnIterador(iter);
    avanzarIterador(iter);
    auxiliarIterador(iter,nuevo);
    agregarAIterador(n,nuevo);
  }
}

TIterador reversoDeIterador(TIterador iter) {
  reiniciarIterador(iter);
  TIterador nuevo = crearIterador();
  auxiliarIterador(iter,nuevo);
  return nuevo;
}