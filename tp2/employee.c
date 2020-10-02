#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "utn.h"


//***************************************************************************************************************************************
//***************************************************************************************************************************************
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int emp_initEmployees(eEmployee* employeelist, int len)
{
    if(employeelist!=NULL&&len>0)
    {
        int i;
        for(i=0;i<len;i++)
        {
            employeelist[i].isEmpty=TRUE;
            employeelist[i].id=0;
        }
        return 0;
    }
return -1;
}

//***************************************************************************************************************************************
//***************************************************************************************************************************************

/*2.2 Función addEmployees
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.*/

/*sin el uso de punteros esta funcion es imposible, ya que no puedo usarla solo para asignar los valores
cual creo que seria su funcion ideal. por lo tanto tengo que hacer toda la logica adentro de la misma.
*/
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee[] it's the array of the eEmplyee structure
* \param len int the lenght of the eEmployee Array
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 4
Programación I – Laboratorio I

*/
int emp_addEmployee(eEmployee employeelist[], int len)
{
    int retorno=-1;
    if(employeelist !=NULL && len>0 )//valida los datos ingresados
    {
        float salarioAuxFloat;
        int sectorAuxInt;
        int emptyIndex;
        char nombreAux[51];
        char apellidoAux[51];
        char validacionAux;
        if(getFirstEmptyIndex(employeelist,len,&emptyIndex)==0)//este if verifica si hay espacio
        {
            printf("\n Error! No hay mas lugares libres\n");

        }else//y si hay espacio este else modifica los datos
        {
            //se ingresan los datos;

            do{// aca algo estoy haciendo mal, aveces los datos validan, pero a veces deciden no valida nada .
                    //ahora si, pero hay algo que hace que las funciones no validan si permito que tome el string un " ",solo valida la primera funion getValidAlgo y las uqe siguen se rompen

            if(emp_SetId(employeelist,-1,emptyIndex) == -1)
            {
                break;
            }
            if(getValidNames("ingrese el nombre = ","\nError! intente nuevamente",
                          "\nError! el nombre no debe superar los 51 caracteres. ",nombreAux,51,3) == -1)
            {
                break;
            }
              if(getValidNames("ingrese el apellido = ","\nError!  intente nuevamente",
                         "\nError!el apellido no debe superar los 51 caracteres. ",apellidoAux,51,3) == -1)
            {
                break;
            }
             if(getValidFloat("ingrese el salario","error intente nuevamente",&salarioAuxFloat,3) == -1)
            {
                break;
            }
             if(getValidInt("ingrese el sector = ","\nError! intente nuevamente",&sectorAuxInt,0,10,3) == -1)
            {
                break;
            }
            validacionAux = getChar("confirmar ingreso de datos 'Y', 'N'");
            }while(validacionAux != 'Y' && validacionAux != 'y' && validacionAux != 'n' && validacionAux != 'N');

            if(validacionAux == 'Y' || validacionAux == 'y')
            {
                strcpy(employeelist[emptyIndex].lastName , apellidoAux);
                strcpy(employeelist[emptyIndex].name , nombreAux);
                employeelist[emptyIndex].sector = sectorAuxInt;
                employeelist[emptyIndex].salary = salarioAuxFloat;
                employeelist[emptyIndex].isEmpty = FALSE;
                retorno=0;
            }
         }
    }
return retorno;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

/** \brief searches for a isEmpty with a true value and returns its index number
* \param list employee[] it's the array of the eEmplyee structure
* \param len int the lenght of the eEmployee Array
* \param *emptyIndex its the pointer to where the empty index value will be stored
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int getFirstEmptyIndex(eEmployee* employeelist, int len,int* emptyIndex)
{

    if(employeelist != NULL&&len > 0 &&emptyIndex!=NULL )
    {
        int i;
        for(i=0;i<len;i++)
        {
            if(employeelist[i].isEmpty==TRUE)
            {
               *emptyIndex = i;
               return 1;
            }
        }
        return 0;
    }
    return -1;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

/** \brief genera automaticamente un id nuevo para cada empleado
 *
 * \param empleado eEmployee* es el array de estructura eEmployee
 * \param id int es la id con la que se quiere inciarlizar el conteo. si se pone -1 empieza a contar desde 1 hasta el limite de int
 * \param index int es el indice de el array de empleados donde se va aguardar el id
 * \return int si falla en encontrar un id retorna -1, si sale todo bien retorna 0
 *
 */
int emp_SetId(eEmployee* empleado,int id,int index)
{
    int retorno =-1;
    static unsigned int  maxId=0;
    if(empleado != NULL)
    {
        retorno = 0;
        if(id < 0)
        {
            maxId++;
            empleado[index].id = maxId;
        }
    }else
    {
        if(id>maxId)
        {
          retorno = 0;
          maxId=id;
          empleado[index].id = maxId;
        }
    }

    return retorno;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

//2.3 Función findEmployeeById
//Busca un empleado recibiendo como parámetro de búsqueda su Id.
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee* list, int len,int id)
{
    int i;
    int returnIndex = -1;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(id==list[i].id&&list)
            {
                returnIndex = i;
            }
        }
    }

return returnIndex;
}

//***************************************************************************************************************************************
//***************************************************************************************************************************************

/**
*2.4 Función removeEmployee
*\brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee* list, int len, int id)
{
int retorno=-1;
    if(list!=NULL && len>0 && id > 0 && id < 1000)
    {

        int index;
        index = findEmployeeById(list,len,id);

        if(index!=-1)
        {
            printf("el empleado a borrar es : \n");
             printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
            printf("\n%5d | %20s | %20s | %10.2f | %10d\n",list[index].id ,list[index].name , list[index].lastName ,list[index].salary,list[index].sector);


            if(getChar("para confirmar el borrado ingrese 'S' ") == 'S' )
            {
                list[index].isEmpty=TRUE;
                retorno=0;
            }
        }else
        {
            printf("este indice ya esta vacio \n");
        }
    }
return retorno;
}

/************************************************************************************************************************
************************************************************************************************************************/

/**
2.5 Función sortEmployees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
\brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *///por alguna razon el indice 0 no lo mueve y queda siempre arriba de todo en la lista


int sortEmployees(eEmployee lista[], int len, int order)
{
    int retorno = -1;
    if(lista != NULL && len > 0 && (order == 0 || order == 1) )
    {
        retorno = 0;
        int iEmpleados;
        int jEmpleados;
        int comparacionSector;
        int comparacionApellido;

        for(iEmpleados = 0 ; iEmpleados < len-1 ; iEmpleados++ )
        {
           for(jEmpleados = iEmpleados+1 ; jEmpleados<len ; jEmpleados++ )
            {
                comparacionApellido = strcmp(lista[iEmpleados].lastName,lista[jEmpleados].lastName);
                comparacionSector = lista[iEmpleados].sector - lista[jEmpleados].sector;
                if(order == 1)
                {
                    if(comparacionSector>0 || (comparacionApellido > 0 && comparacionSector ==0) )
                    {
                        intercambiarLugaesEempleados(lista,iEmpleados,jEmpleados);
                        retorno=1;
                    }
                }else
                {
                    if(order == 0)
                    {
                        if(comparacionSector<0 || (comparacionApellido < 0 && comparacionSector ==0) )
                        {
                            intercambiarLugaesEempleados(lista,jEmpleados,iEmpleados);
                            retorno=1;
                        }
                    }
                }
             }
        }
    }
     return retorno;
}

//***************************************************************************************************************************************
//***************************************************************************************************************************************

//2.6 Función printEmployees
//Imprime el array de empleados de forma encolumnada.
/** \brief print the content of employees array
*
* \param list Employee* the pointer to the eEmployee array that will be printed in console
* \param length int lenght of the array
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(eEmployee* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        clearScreen();
        printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
        for(i=0; i<len;i++)
        {
            if(list[i].isEmpty==FALSE)
           // printf("\n%5d | %20s | %20s | %10.2f | %10d | %d | %d",list[i].id ,list[i].name , list[i].lastName ,list[i].salary,list[i].sector,list[i].isEmpty,i);
            printf("\n%5d | %20s | %20s | %10.2f | %10d ",list[i].id ,list[i].name , list[i].lastName ,list[i].salary,list[i].sector);
        }
        return 1;
    }

return 0;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

/** \brief ingresandole un id de un empleado, busca en que indice se encuetra ese id .
 muestra los datos del empleado y permite modificar los datos uno a uno
 *
 * \param list[] eEmployee es el array de estructura eEmployee a modificar
 * \param len int el largo del array
 * \param id int es el id del empleado a modificar
 * \return int retorna -1 si algun parametro esta incorrecto - 0 si no existe el empleado con el id ingresado y 1 si se entro a alguna modificacion;
 *
 */
int modificarEmployee(eEmployee list[], int len, int id)
{
int retorno=-1;
int sectorAuxInt;
float salarioAuxFloat;
    if(list!=NULL && len>0 && id > 0 && id < 1000)
    {

        char opcionesModificacion[][70]={"1- nombre","2- apellido","3- salario","4- sector","5- salir","N"};
        int index;
        index = findEmployeeById(list,len,id);

        if(index!=-1)
        {
            printf("el empleado a modificar es : \n");
             printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
            printf("\n%5d | %20s | %20s | %10.2f | %10d\n",list[index].id ,list[index].name , list[index].lastName ,list[index].salary,list[index].sector);


            if(getChar("¿Desea modificar este empleado? 'Y', 'N'") == 'Y' )
            {
                int opcionSeleccionada;
                do{
                    clearScreen();
                    menuDisplay(opcionesModificacion);

                    if(getValidInt("\nelija una opcion [_]\b\b","\nerror opcion invalida",&opcionSeleccionada,1,5,3)!=-1)
                    {
                          switch(opcionSeleccionada)
                          {
                            case 1://"1- nombre"
                                 getValidNames("ingrese el nombre = ","\nError! intente nuevamente",
                                    "\nError! el nombre no debe superar los 51 caracteres. ",list[index].name,51,3);
                                retorno=1;
                                break;

                            case 2://"2- apellido"
                                getValidNames("ingrese el apellido = ","\nError!  intente nuevamente",
                                    "\nError!el apellido no debe superar los 51 caracteres. ",list[index].lastName,51,3);
                                retorno=1;
                                break;

                            case 3://"3- salario"
                                getValidFloat("ingrese el salario","error intente nuevamente",&salarioAuxFloat,3);
                                list[index].salary = salarioAuxFloat;
                                retorno=1;
                                break;

                            case 4://"4- sector"
                                getValidInt("ingrese el sector = ","\nError! intente nuevamente",&sectorAuxInt,0,10,3);
                                list[index].sector = sectorAuxInt;
                                retorno=1;
                                break;
                         }//end swich
                    }//if(getValidInt);

                }while(opcionSeleccionada!=5);
            }//endif(desea modificar el empleado?)
        }else
        {
            retorno=0;
            printf("No se encontro el empleado \n");
        }
    }//end if de verificacion de parametros de la func
return retorno;
}

/************************************************************************************************************************
************************************************************************************************************************/
/**
\brief intercambia dos elementos de un array de estructura eEmpleado
 *
 * \param list Employee*
 * \param empleadoA
 * \param empleadoB
 *///por alguna razon el indice 0 no lo mueve y queda siempre arriba de todo en la lista
 void intercambiarLugaesEempleados(eEmployee* lista,int empleadoA,int empleadoB )
 {
     if(empleadoA!= NULL && empleadoB != NULL)
     {
        eEmployee aux;

        aux=lista[empleadoA];
        lista[empleadoA]=lista[empleadoB];
        lista[empleadoB]=aux;

     }
 }


/************************************************************************************************************************
************************************************************************************************************************/

/** \brief carga nombres al array y genera valores automaticos para cada miembro de una estrucutura
 *
 * \param lista[] eEmployee es el array de estructura eEmployee a modificar
 * \param len int el largo del array
 * \return void
 *
 */
void hardcodearEmpleados(eEmployee lista[],int len)
{

char nombres[550][51]={"Liam","Noah","William","James","Oliver","Benjamin","Elijah","Lucas","Mason","Logan","Alejandro","Ethan","Jacob","Miguel","Daniel","Enrique","Jackson","Sebastian","Aiden","Mateo","Samuel","David","Jose","Carretero","Owen","Wyatt","John","Jack","Luke","Jayden","Dylan","Grayson","Levi","Isaac","Gabriel","Julian","Mateo","Antonio","Jaxon","Lincoln","Joshua","Christopher","Andres","Theodore","Caleb","Ryan","Asher","Nathan","Thomas","Leon","Isaias","Charles","Josiah","Hudson","cristiano","Cazador","Connor","Eli","Ezra","Aaron","Aterrizar","Adrian","Jonathan","Nolan","Jeremias","Easton","Elias","Colton","Cameron","Carson","Robert","angel","Disidente","Nicholas","Dominic","Jaxson","Greyson","Adan","Ian","Austin","Santiago","Jordan","cobre","Brayden","romano","Evan","Ezequiel","Javier","Jose","Jace","Jameson","Leonardo","Bryson","Axel","Everett","Parker","Kayden","Millas","Aserrador","Jason","Declan","Weston","Micah","Ayden","Wesley","Luca","Vincent","Damian","Zachary","Silas","Gavin","Persecucion","Kai","Emmett","Harrison","Nathaniel","Kingston","Col","Tyler","Bennett","Bentley","Ryker","Tristan","Brandon","Kevin","Luis","Jorge","Ashton","Serbal","Braxton","Ryder","gaelico","Ivan","Diego","Maxwell","Max","Carlos","Kaiden","Juan","Maddox","Justin","Waylon","Calvin","Giovanni","Jonas","Abel","Jayce","Jesus","Amir","Rey","Galan","Camden","Alex","Jaspe","Malaquias","Brody","Judas","Blake","Emmanuel","Eric","Brooks","Elliot","Antonio","Abrahan","Timothy","finlandes","Rhett","Elliott","Eduardo","agosto","Xander","Alan","Decano","Lorenzo","Bryce","Karter","Victor","Milo","Miguel","Hayden","Graham","Conceder","Sion","Fatigar","Jesse","Zayden","Joel","Ricardo","Patricio","Emiliano","Avery","Nicolas","Brantley","Dawson","Myles","Matteo","Rio","Steven","Thiago","Zane","Matias","Juda","Mesias","Jeremy","Preston","Oscar","Kaleb","Alejandro","Marcus","marca","Peter","Maximus","Barrett","Jax","Andres","Holden","Leyenda","Charlie","Knox","Kaden","Paxton","Kyrie","Kyle","Grifo","Josue","Kenneth","Beckett","Enzo","Adriel","Arturo","Felix","Bryan","Lukas","Pablo","Brian","Potro","Caden","Leon","Arquero","Omar","Israel","Aidan","Theo","Javier","Remington","Jaden","Bradley","Emilio","Colin","Riley","Cayden","Fenix","Clayton","Simon","As","Nash","Derek","Rafael","Zander","Brady","Jorge","Jake","Louis","Damien","Karson","Caminante","Maximiliano","Amari","Sean","Oportunidad","Walter","Martin","Finley","Andre","Tobias","Efectivo","Corbin","Arlo","Iker","Erick","Emerson","Artillero","Cody","Stephen","Francisco","Killian","Dallas","Reid","Manuel","carril","Atlas","Rylan","Jensen","Ronan","Beckham","Daxton","Anderson","Kameron","Raymond","Orion","Cristian","Curtidor","Kyler","Jett","Cohen","Ricardo","Spencer","Gedeon","Ali","Fernando","Jaiden","Titus","Travis","Bodhi","Eduardo","Dante","Ellis","Principe","Kane","Luka","Kash","Hendrix","Desmond","Donovan","Mario","Atticus","Cruz","Garrett","Hector","Angelo","Jeffrey","Edwin","Cesar","Zayn","Devin","Conor","Madriguera","Odin","Jayceon","Romeo","Julius","Jaylen","Hayes","Kayson","Mahoma","Jaxton","Joaquin","Caiden","Dakota","Mayor","Keegan","Sergio","Marshall","Johnny","Kade","Edgar","Leonel","Ismael","Marco","Tyson","Vadear","Collin","Troya","Nasir","Conner","Adonis","Jared","Rory","Andy","Jase","Lennox","Shane","Malik","Ari","Cania","Seth","Clark","Erik","Lawson","Trevor","Calibrar","Nico","Malakai","Quinn","Cade","Johnathan","Sullivan","Salomon","Ciro","Fabian","Pedro","Franco","Shawn","Malcolm","Jalil","Nehemias","Dalton","Mathias","Arrendajo","Ibrahim","Peyton","Winston","Kason","Zayne","Navidad","Princeton","Matias","Gregory","Libraesterlina","Dominick","Elian","Grady","Russell","Finnegan","Ruben","Gianni","Portero","Kendrick","Leland","Pablo","Allen","Hugo","Raiden","Kolton","Remy","Ezequiel","Damon","Emanuel","Zaiden","Oton","Bowen","Marcos","Abram","Kasen","Franklin","Royce","Jonas","Sabio","Philip","Esteban","Pato","Kashton","Roberto","Harvey","Alexis","Kian","Jamison","Maximiliano","Adan","Milan","Phillip","Albert","Dax","Mohamed","Ronin","Kamden","Madeja","Memphis","Oakley","Augusto","Dibujo","Moises","Armani","Rhys","Benson","Jayson","Kyson","Braylen","Corey","Gunnar","Omari","Alonzo","Landen","Armando","Derrick","Diestro","Enrique","Bruce","Nikolai","Francisco","Rocco","Kairo","Real","Zacarias","Arjun","Diacono","Skyler","Eden","Alijah","Rowen","atravesar","Uriel","Ronald","Luciano","Tate","Frederick","Kieran","Lawrence","Moises","Rodrigo"};
char apellidos[500][51]={"Acosta","Acunia","Aguilar","Aguirre","Agustin","Ahumada","Alanis","Alarcon","Alayon","Alcazar","Alcocer","Alfaro","Almendarez","Altamirano","alvarez","Alzate","Amador","Anaya","Argüelles","Arjona","Arriaga","Arrollo","Ayala","Baca","Baez","Banios","Barba","Barrera","Barrientos","Barriga","Bastida","Batalla","Bautista","Bazan","Becerra","Becerril","Bello","Beltran","Benitez","Bernal","Bolanios","Bonilla","Borges","Bustamante","Busto","Caballero","Cabeza","Cabrera","Cadenas","Caldera","Calleja","Calles","Camacho","Camareno","Camarillo","Campos","Cardenas","Cardoso","Carranza","Carrillo","Carvajal","Carvallo","Casas","CastellanosCastanieda","Cepeda","Cerda","Cervantes","Cespedes","Cevallos","Cevedo","Chavez","Chavira","Cisneros","Collado","Cordero","Cornejo","Correa","Corro","Cuellar","Cuervo","Cuesta","Cuevas","Daniel","Dario","Davila","DeAguilar","DeAlba","DelaCruz","DelaCuesta","DelaFuente","DelaRosa","DelCastillo","Doblado","Dominguez","Donato","Dorado","Duarte","Duenias","Echeverria","Elizondo","Enriquez","Escalante","Escamilla","Escobar","Escobedo","Escoto","Escovar","Espino","Esquivel","Estevez","Estrada","Estrella","Fabregas","Falcon","Farias","Fernandez","Ferreira","Ferrer","Fierro","Figueras","Flores","Fonseca","Fraga","Frias","Fuentes","Funez","Gaitan","Galan","Galeano","Galeno","Galindo","Gallegos","Galvan","Gamboa","Gamez","Garcia","Garrido","Gavilan","Gayoso","Gaytan","Gillen","Godines","Gomez","Gongora","Granada","Granados","Grijalba","Guardado","Guardiola","Guerrero","Guillen","Gutierrez","Guzman","Heredia","Hernandez","Herrera","Hidalgo","Hierro","Huerta","Hurtado","Ibaniez","Ibarra","Icaza","Iglesias","Infante","Ivaniez","Izquierdo","Jara","Jaramillo","Jerano","Jimenez","Juarez","Junco","Jurado","Lacayo","Lafuente","Lagos","Lagunal","Lamas","Landez","Larios","Lastreto","Lazaro","Leandro","Lemus","Leyva","Linares","Lines","Lira","Lizano","Llano","Lobo","Lombardo","Lopez","Loredo","Lorio","Losada","Lozano","Lucas","Lugo","Luna","Macedo","Machado","Macias","Maduro","Magallon","Maldonado","Maltes","Mantilla","Manuel","Manzanal","Manzano","Marcias","Marrero","Marroqui","Marti","Martinez","Mateo","Matias","Maurer","Medrano","Medina","Mendoza","Mejia","Mena","Meneses","Merazo","Meza","Mijares","Milanes","Minas","Molina","Molleda","Moneda","Monge","Montalban","Montalvo","Montecinos","Montero","Montes","Montiel","Morillo","Moscoa","Munera","Murillo","Naranjo","Navaro","Navarrete","Navarro","Nieto","Noble","Noguera","Noriega","Novales","Novo","Novoa","Nuniez","Obellon","Obregon","Ocampo","Ochoa","Ordoniez","Olguin","Olivar","Olivares","Olivera","Olmeda","Olmedo","Olmo","Ordoniez","Orozco","Ortega","Ortiz","Oseda","Osorio","Ospino","Otero","Oviedo","Ozuno","Pacheco","Padilla","Paez","Palacio","Paladino","Palazuelos","Palomar","PalominoPaniagua","Pantoja","Parado","Paramo","Pardo","Paredes","Parra","Pastor","Pastrana","Patinio","Paz","Pedroza","Pena","Penia","Peralta","Peraza","Perdomo","Pineda","Pino","Placido","Ponce","Portillo","Prada","Prieto","Puente","Quesada","Quevedo","Quijada","Quijano","Quintana","Quintanilla","Quiroga","Quiroz","Ramirez","Ramon","Ramos","Rangel","Real","Redondo","Restrepo","Reyes","Rivas","Rivera","Roble","Robles","Rojas","Roldan","Roman","Romero","Rosales","Rosas","Rovira","Rubin","Rubio","Rueda","Ruiz","Sabin","Saenz","Sagel","Sala","Salas","Salazar","Salcedo","Saldania","Saldivar","Salinas","Salmon","Salvado","Samper","Sanchez","Sandino","Sandoval","Santiago","Santos","Sardinas","Sarmiento","Saucedo","Savala","Seballos","Sedano","Segura","Silva","Sol","Solana","Sole","Soler","Solis","Somoza","Sorio","Sotelo","Soto","Sotomayor","Soza","Suarez","Tablada","Talavera","Tames","Taracena","Tedesco","Tejada","Tobar","Torre","Torrente","Tovar","Travieso","Trejos","Treminio","Triguero","Troncoso","Trujillo","Ulloa","Urenia","Uriarte","Uribe","Urieta","Urrutia","Usaga","Uveda","Valdes","Valdiva","Valencia","Valentin","Valenzuela","Vales","Valle","Vallejo","Vanegas","Varela","Varga","Vargas","Vasquez","Vega","Vela","Velarde","Velasco","Velasquez","Venegas","Ventura","Verti","Vidal","Villallovos","Villar","Villareal","Villas","Villasenior","Villeda","Vivas","Vivero","Vivez","Zabaleta","Zacarias","Zaldivar","Zambrano","Zamora","Zamudio","Zapata","Zarco","Zavala","Zavaleta","Zelaya","Zetina","Zuleta","Zuniiga"};

    int flagSeddRandom = 1;
    int numeroRandomName;
    int numeroRandomLastName;
    int iEmpleados;
    for(iEmpleados=0 ; iEmpleados<len ; iEmpleados++)
    {

        emp_SetId(lista,-1,iEmpleados);

        numeroRandomName = getNumeroAleatorio(0,400,flagSeddRandom);
        numeroRandomLastName = getNumeroAleatorio(0,400,flagSeddRandom);

        strcpy(lista[iEmpleados].name , nombres[numeroRandomName]);

        strcpy(lista[iEmpleados].lastName , apellidos[numeroRandomLastName]);

        lista[iEmpleados].salary = (float)getNumeroAleatorio(18000,100000,flagSeddRandom);
        lista[iEmpleados].sector = getNumeroAleatorio(1,10,flagSeddRandom);
        lista[iEmpleados].isEmpty = FALSE;

        if(iEmpleados==0)
        {
             flagSeddRandom = 0 ;
        }
    }
}

/************************************************************************************************************************
************************************************************************************************************************/

/** \brief calcula y muestra la suma del total de los sueldos, el promedio de los sueldos y la cantidad de empleados por sobre el promedio
 *
 * \param lista[] eEmployee es el array de estructura eEmployee a modificar
 * \param len int el largo del array
 * \return int retorna -1 si los parametros de la funcion estan incorrectos - 0 esta todo bien
 *
 */
int promedioSueldos(eEmployee lista[],int len)
{
    int retorno = -1;

    if(lista != NULL && len>0)
    {
        retorno = 0;
        float acumuladorSueldos=0,contadorEmpleados=0;
        float promedio;
        int CantidadSobreElPromedio=0;
        int iEmpleados;
        for(iEmpleados=0;iEmpleados<len;iEmpleados++)
        {
            if(lista[iEmpleados].isEmpty==FALSE)
            {
                acumuladorSueldos += lista[iEmpleados].salary;
                contadorEmpleados++;
            }
        }//endfor
        promedio=acumuladorSueldos/contadorEmpleados;

        for(iEmpleados=0;iEmpleados<len;iEmpleados++)
        {
            if(lista[iEmpleados].salary>promedio)
            {
                CantidadSobreElPromedio++;
            }
        }
        printf("\nEl total de los sueldos es = %-10.2f\nEl promedio de los sueldos es = %-10.2f"
               "\nLa cantidad de empleados por sobre el promedio es = %-5d",
               acumuladorSueldos,promedio,CantidadSobreElPromedio);
        return retorno;
    }
}
