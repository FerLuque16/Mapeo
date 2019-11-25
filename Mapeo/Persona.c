#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Persona.h"

Persona* persona_new()
    {
        Persona *this;

        this=malloc(sizeof (Persona));

		return this;
    }

Persona* persona_newParametros(char* idStr,char* dominioStr,char* anioStr)

    {
        Persona *persona;
		int id;
		int anio;

		id=atoi(idStr);
		anio=atoi(anioStr);


		persona=persona_new();

		persona_setId(persona,id);
		persona_setDominio(persona,dominioStr);
		persona_setAnio(persona,anio);



		return persona;
    }

int persona_setId(Persona* this,int id)
    {
        int retorno=-1;
        if(this!=NULL && id>0)
            {
                this->id=id;
                retorno=0;

            }

        return retorno;
    }

int persona_getId(Persona* this,int* id)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *id=this->id;
                retorno=0;
            }

        return retorno;
    }

int persona_setDominio(Persona* this,char* dominio)
    {
        int retorno=-1;

        if(this!=NULL )
            {
                strcpy(this->dominio,dominio);
                retorno=0;

            }
        return retorno;
    }

int persona_getDominio(Persona* this,char* dominio)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                strcpy(dominio,this->dominio);
                retorno=0;
            }

        return retorno;
    }

/*int persona_setSexo(Persona* this,char* sexo)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                strcpy(this->sexo,sexo);
                retorno=0;
            }

        return retorno;

    }

int persona_getSexo(Persona* this,char* sexo)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                strcpy(sexo,this->sexo);
                retorno=0;
            }

        return retorno;
    }
*/

int persona_setAnio(Persona* this,int anio)
    {
        int retorno=-1;
        if(this!=NULL && anio>0)
            {
                this->anio=anio;
                retorno=0;

            }

        return retorno;
    }

int persona_getAnio(Persona* this,int* anio)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *anio=this->anio;
                retorno=0;
            }

        return retorno;
    }

 int persona_setTipo(Persona* this, char tipo)
     {
         int retorno=-1;

         if(this!=NULL)
         {
             this->tipo=tipo;
             retorno=0;
         }

        return retorno;
     }

int persona_getTipo(Persona* this, char *tipo)
     {
         int retorno=-1;

         if(this!=NULL)
         {
             *tipo=this->tipo;
             retorno=0;
         }

        return retorno;
     }

int filtrarAutos(void* p)
{

    int ok = 0;
    Persona* ePersona;

    if(p != NULL){

        ePersona = (Persona*) p;

        if(ePersona->tipo == 'A')
		{
            ok = 1;
        }
    }

    return ok;

}

int filtrarMotos(void* p)
{

    int ok = 0;
    Persona* ePersona;

    if(p != NULL){

        ePersona = (Persona*) p;

        if(ePersona->tipo == 'M')
		{
            ok = 1;
        }
    }

    return ok;

}
