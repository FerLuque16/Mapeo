#ifndef Persona_H_INCLUDED
#define Persona_H_INCLUDED

typedef struct
{
    int id;
    char dominio[10];
    int anio;
    char tipo;

}Persona;
#endif

Persona* persona_new();
Persona* persona_newParametros(char* idStr,char* dominioStr,char* anioStr);
int persona_setId(Persona* this,int id);
int persona_setAnio(Persona* this,int anio);
int persona_setDominio(Persona* this,char* dominio);
int persona_getDominio(Persona* this,char* dominio);
int persona_getAnio(Persona* this,int* anio);
int persona_getId(Persona* this,int* id);
int persona_setTipo(Persona* this, char tipo);
int persona_getTipo(Persona* this, char *tipo);
int filtrarMotos(void* p);
int filtrarAutos(void* p);


