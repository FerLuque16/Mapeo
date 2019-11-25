#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Persona.h"
#include "parser.h"

void dominio_mapTipo(void* pDominio);

int main()
{
    int opcion;
    LinkedList* listaVehiculos=NULL;
    LinkedList* filtradoAutos;
    LinkedList* filtradoMotos;

    listaVehiculos=ll_newLinkedList();

    do
    {
        system("cls");
        printf("1. Cargar\n2. Mapeo\n3. Filtrar autos\n4. Filtrar motos\n5. Guardar\n6. Salir");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                parserText(listaVehiculos);
                break;

            case 2:
                ll_map(listaVehiculos,dominio_mapTipo);
                break;

            case 3:


                filtradoAutos=ll_newLinkedList();
                filtradoAutos=ll_filter(listaVehiculos,filtrarAutos);
                saveAsText(filtradoAutos,"autos.csv");
                break;
            case 4:
                filtradoMotos=ll_newLinkedList();
                filtradoMotos=ll_filter(listaVehiculos,filtrarMotos);
                saveAsText(filtradoMotos,"motos.csv");
                break;

            case 5:
                saveAsText(listaVehiculos,"Vehiculos.csv");
                break;




        }
    } while(opcion!=6);




    //saveAsText(listaVehiculos);


    return 0;
}




void dominio_mapTipo(void* pDominio)
{
    char aux[10];

    if (pDominio!= NULL)
	{
        persona_getDominio(pDominio, aux);

        if (aux[0]<'0' || aux [0]>'9')
		{
            persona_setTipo(pDominio, 'A');
        }
        else
		{
            persona_setTipo(pDominio, 'M');
        }
    }
}




