#include <iostream>
#include <fstream>

#include "att1.h"

using namespace std;

class ClToken
   {
public:
   ClToken();
   char const *start() { if (tokenStart != NULL) return tokenStart; else return ""; }
   char const *end() { if (tokenEnde != NULL) return tokenEnde; else return ""; }
   char const *inhalt() { if (tokenInhalt != NULL) return tokenInhalt; else return ""; }
   int getToken(ifstream &datei);
   ClattToken att;
private:
   char *tokenStart;
   char *tokenEnde;
   char *tokenInhalt;
   } ;

enum zustand { istStartTag, istEndTag } ;

// siehe Vorlesung
