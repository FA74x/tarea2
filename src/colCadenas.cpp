/* 1234567 */

#include "../include/colCadenas.h"

struct _rep_colCadenas {
  TCadena c[CANT_CADS];
};

TColCadenas crearColCadenas() {
  TColCadenas col = new _rep_colCadenas;
  for (int i = 0; i < CANT_CADS; i++) {
    col->c[i] = NULL;
  }
  return col;
}

void liberarColCadenas(TColCadenas col) {
  for (int i = 0; i < CANT_CADS; i++) {
    liberarCadena(col->c[i]);
  }
  delete col; 
}

TCadena cadenaDeColCadenas(nat pos, TColCadenas col) {
  return col->c[pos];
}

nat cantidadColCadenas(nat pos, TColCadenas col) {
  return cantidadEnCadena(col->c[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
    return estaEnCadena(natural,col->c[pos]);
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos, TColCadenas col) {
  col->c[pos] = insertarAlInicio(natural,real,col->c[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return infoCadena(natural,col->c[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  col->c[pos] = removerDeCadena(natural,col->c[pos]);
  return col;
}
