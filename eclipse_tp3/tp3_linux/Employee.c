#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

static int isValidId(int *id);
static int isValidIdString(char *id);
static int isValidNombre(char *nombre);
static int isValidHorasTrabajadas(int *horasTrabajadas);
static int isValidHorasTrabajadasString(char *horasTrabajadas);
static int isValidSueldo(int *sueldo);
static int isValidSueldoString(char *sueldo);



Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

void employee_delete(Employee *this)
{
	free(this);
}

Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
	Employee* retorno = NULL;
	Employee* this;

	this = employee_new();

	if(this != NULL)
	{
		if(		employee_setNombre(this,nombre) == EXIT_SUCCESS &&
				employee_setHorasTrabajadasString(this,horasTrabajadas) == EXIT_SUCCESS &&
				employee_setSueldoString(this,sueldo) == EXIT_SUCCESS &&
				employee_setIdString(this,id) == EXIT_SUCCESS )
		{
				printf("\nOK!\n");
				retorno = this;
		}
		else
		{
			employee_delete(this);
		}
	}

	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidId(&id) == EXIT_SUCCESS)
	{
		this->id=id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidId(int *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		if(id > 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int employee_setIdString(Employee *this,char *id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidIdString(id)==EXIT_SUCCESS)
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidIdString(char *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		//if(esSoloNumerosPositivos(id,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
		//}
	}

	return retorno;
}

int employee_setNombre(Employee *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidNombre(nombre)==EXIT_SUCCESS)
	{
		strcpy(this->nombre,nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getNombre(Employee *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidNombre(char *nombre)
{
	int retorno = EXIT_ERROR;

	if(nombre != NULL)
	{
		//esNombreOApellido(nombre,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidHorasTrabajadas(&horasTrabajadas) == EXIT_SUCCESS)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidHorasTrabajadas(int *horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(horasTrabajadas != NULL)
	{
		if(horasTrabajadas >= 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int employee_setHorasTrabajadasString(Employee *this,char *horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidHorasTrabajadasString(horasTrabajadas)==EXIT_SUCCESS)
	{
		this->horasTrabajadas=atoi(horasTrabajadas);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidHorasTrabajadasString(char *horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(horasTrabajadas != NULL)
	{
		//if(esSoloNumerosPositivos(horasTrabajadas,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
			//}
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidSueldo(&sueldo) == EXIT_SUCCESS)
	{
		this->sueldo=sueldo;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo=this->sueldo;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidSueldo(int *sueldo)
{
	int retorno = EXIT_ERROR;

	if(sueldo != NULL)
	{
		if(sueldo > 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int employee_setSueldoString(Employee *this,char *sueldo)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidSueldoString(sueldo)==EXIT_SUCCESS)
	{
		this->sueldo=atoi(sueldo);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidSueldoString(char *sueldo)
{
	int retorno = EXIT_ERROR;

	if(sueldo != NULL)
	{
		//	if(esSoloNumerosFlotantes(sueldo,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
			//}
	}

	return retorno;
}

Employee* employee_buscaPorId(LinkedList* pArrayListEmployee,int id)
{
	Employee* this = NULL;
	int i;

	if(pArrayListEmployee!=NULL && id>0)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			this = ll_get(pArrayListEmployee,i);
			if(this->id == id)
			{
				return this;
			}
		}
	}
	return this;
}

int employee_ordenoPorId(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(((Employee*)pElementUno)->id > ((Employee*)pElementDos)->id)
	{
		retorno = 1;
	}
	if(((Employee*)pElementUno)->id < ((Employee*)pElementDos)->id)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_ordenoPorSueldo(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(((Employee*)pElementUno)->sueldo > ((Employee*)pElementDos)->sueldo)
	{
		retorno = 1;
	}
	if(((Employee*)pElementUno)->sueldo < ((Employee*)pElementDos)->sueldo)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_ordenoPorHorasTrabajadas(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(((Employee*)pElementUno)->horasTrabajadas > ((Employee*)pElementDos)->horasTrabajadas)
	{
		retorno = 1;
	}
	if(((Employee*)pElementUno)->horasTrabajadas < ((Employee*)pElementDos)->horasTrabajadas)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_ordenoPorNombre(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(strncmp(((Employee *)pElementUno)->nombre,((Employee *)pElementDos)->nombre,CANT_CARACTERES)>0)
	{
		retorno = 1;
	}
	if(strncmp(((Employee *)pElementUno)->nombre,((Employee *)pElementDos)->nombre,CANT_CARACTERES)<0)
	{
		retorno = -1;
	}

	return retorno;
}
