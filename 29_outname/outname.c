#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outname = malloc((strlen(inputName)+10)*sizeof(* outname));
  strcpy(outname, inputName);
  strcat(outname, ".counts");
  return outname;
}

