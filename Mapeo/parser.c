#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Persona.h"

int parserText(LinkedList* lista)
{

    int returnAux=-1;

    Persona* persona;

    FILE* pFile;

    char dominio[4096];
    char anio[4096];
    char id[4096];
    int r;
    int i=0;

    pFile=fopen("datos.csv","r");

    if(pFile!=NULL && lista!=NULL)
    {
        do
        {


            r=fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,dominio,anio);

            if(r==3)
            {


                persona=persona_newParametros(id,dominio,anio);

                if(persona!=NULL)
                {
                    ll_add(lista,persona);
                    returnAux=i;
                    i++;
                }
            }
            else
                break;

        }
        while(!feof(pFile));


    }

    pclose(pFile);

    return returnAux;

}

int saveAsText(LinkedList* listaVehiculos,char* fileName)
{
    int returnAux=-1;
    int id;
    char dominio[10];
    int anio;
    char tipo;
    int i;

    Persona* persona=NULL;

    FILE* pFile;

    pFile=fopen(fileName,"w");

    if(pFile!=NULL && listaVehiculos!=NULL)
    {
        fprintf(pFile,"%s,%s,%s,%s\n\n","id","dominio","anio","tipo");

        for(i=1;i<ll_len(listaVehiculos);i++)
        {
            persona=ll_get(listaVehiculos,i);

            if(persona!=NULL)
            {
                persona_getAnio(persona,&anio);
                persona_getDominio(persona,dominio);
                persona_getId(persona,&id);
                persona_getTipo(persona,&tipo);

                fprintf(pFile,"%d,%s,%d,%c\n",id,dominio,anio,tipo);
            }
        }
       returnAux=0;
    }

    fclose(pFile);

    return returnAux;




}

