#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "unt_ingresoDeDatos.h"


//***************************************************************************************************************************************
//***************************************************************************************************************************************
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
int emp_SetId(eEmployee* empleado,int id,int index)//el primer id va a ser 0 y cada nuevo entry va a tener un id diferente.
//si falla en encontrar un id retorna -1;
{

    int retorno =-1;
    static int maxId=0;
    if(empleado != NULL)
    {
        retorno = 0;
        if(id < 0)
        {
            maxId++;
            empleado[index].id = maxId;
        }
    }

    return retorno;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

int printEmployees(eEmployee* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        system("cls");
        printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
        for(i=0; i<len && list[i].isEmpty==FALSE;i++)
        {
            printf("\n%5d | %20s | %20s | %10.2f | %10d",list[i].id ,list[i].name , list[i].lastName ,list[i].salary,list[i].sector);
        }
        return 1;
    }

return 0;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

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
//***************************************************************************************************************************************
//***************************************************************************************************************************************
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
                                break;

                            case 2://"2- apellido"
                                getValidNames("ingrese el apellido = ","\nError!  intente nuevamente",
                                    "\nError!el apellido no debe superar los 51 caracteres. ",list[index].lastName,51,3);
                                break;

                            case 3://"3- salario"
                                getValidFloat("ingrese el salario","error intente nuevamente",&salarioAuxFloat,3);
                                list[index].salary = salarioAuxFloat;
                                break;

                            case 4://"4- sector"
                                getValidInt("ingrese el sector = ","\nError! intente nuevamente",&sectorAuxInt,0,10,3);
                                list[index].sector = sectorAuxInt;
                                break;
                         }//end swich
                    }//if(getValidInt);
                }while(opcionSeleccionada!=5);
            }//endif(desea modificar el empleado?)
        }else
        {
            printf("No se encontro el empleado \n");
        }
    }//end if de verificacion de parametros de la func
return retorno;
}
//***************************************************************************************************************************************
//***************************************************************************************************************************************

int emp_ordenarPorNombreYApellido(eEmployee lista[],int len)
{
    eEmployee Aux;
    int iEmpleados;
    int jEmpleados;
    int comparacionNombre;
    int comparacionApellido;
    for(iEmpleados = 0 ; iEmpleados<len-1 ; iEmpleados++ )
    {
       for(jEmpleados = iEmpleados+1 ; jEmpleados<len ; jEmpleados++ )
        {
            comparacionNombre=strcmp(lista[iEmpleados].name,lista[jEmpleados].name);
            comparacionApellido=strcmp(lista[iEmpleados].lastName,lista[jEmpleados].lastName);
            if(comparacionNombre == 1 || (comparacionNombre == 1 && comparacionApellido == 1))
            {
                Aux=lista[iEmpleados];
                lista[iEmpleados]=lista[jEmpleados];
                lista[jEmpleados]=Aux;
            }
        }
    }
    return 0;
}

//***************************************************************************************************************************************
//***************************************************************************************************************************************

char nombres[550][51]={"Liam","Noah","William","James","Oliver","Benjamín","Elijah","Lucas","Masón","Logan","Alejandro","Ethan","Jacob","Miguel","Daniel","Enrique","Jackson","Sebastian","Aiden","Mateo","Samuel","David","José","Carretero","Owen","Wyatt","John","Jack","Luke","Jayden","Dylan","Grayson","Levi","Isaac","Gabriel","Julian","Mateo","Antonio","Jaxon","Lincoln","Joshua","Christopher","Andrés","Theodore","Caleb","Ryan","Asher","Nathan","Thomas","León","Isaias","Charles","Josiah","Hudson","cristiano","Cazador","Connor","Eli","Ezra","Aaron","Aterrizar","Adrian","Jonathan","Nolan","Jeremías","Easton","Elias","Colton","Cameron","Carson","Robert","Ángel","Disidente","Nicholas","Dominic","Jaxson","Greyson","Adán","Ian","Austin","Santiago","Jordán","cobre","Brayden","romano","Evan","Ezequiel","Javier","Jose","Jace","Jameson","Leonardo","Bryson","Axel","Everett","Parker","Kayden","Millas","Aserrador","Jason","Declan","Weston","Micah","Ayden","Wesley","Luca","Vincent","Damian","Zachary","Silas","Gavin","Persecución","Kai","Emmett","Harrison","Nathaniel","Kingston","Col","Tyler","Bennett","Bentley","Ryker","Tristan","Brandon","Kevin","Luis","Jorge","Ashton","Serbal","Braxton","Ryder","gaélico","Ivan","Diego","Maxwell","Max","Carlos","Kaiden","Juan","Maddox","Justin","Waylon","Calvin","Giovanni","Jonás","Abel","Jayce","Jesús","Amir","Rey","Galán","Camden","Alex","Jaspe","Malaquías","Brody","Judas","Blake","Emmanuel","Eric","Brooks","Elliot","Antonio","Abrahán","Timothy","finlandés","Rhett","Elliott","Eduardo","agosto","Xander","Alan","Decano","Lorenzo","Bryce","Karter","Víctor","Milo","Miguel","Hayden","Graham","Conceder","Sión","Fatigar","Jesse","Zayden","Joel","Ricardo","Patricio","Emiliano","Avery","Nicolas","Brantley","Dawson","Myles","Matteo","Río","Steven","Thiago","Zane","Matias","Judá","Mesías","Jeremy","Preston","Oscar","Kaleb","Alejandro","Marcus","marca","Peter","Maximus","Barrett","Jax","Andres","Holden","Leyenda","Charlie","Knox","Kaden","Paxton","Kyrie","Kyle","Grifo","Josue","Kenneth","Beckett","Enzo","Adriel","Arturo","Felix","Bryan","Lukas","Pablo","Brian","Potro","Caden","León","Arquero","Omar","Israel","Aidan","Theo","Javier","Remington","Jaden","Bradley","Emilio","Colin","Riley","Cayden","Fénix","Clayton","Simon","As","Nash","Derek","Rafael","Zander","Brady","Jorge","Jake","Louis","Damien","Karson","Caminante","Maximiliano","Amari","Sean","Oportunidad","Walter","Martín","Finley","Andre","Tobias","Efectivo","Corbin","Arlo","Iker","Erick","Emerson","Artillero","Cody","Stephen","Francisco","Killian","Dallas","Reid","Manuel","carril","Atlas","Rylan","Jensen","Ronan","Beckham","Daxton","Anderson","Kameron","Raymond","Orión","Cristian","Curtidor","Kyler","Jett","Cohen","Ricardo","Spencer","Gedeón","Ali","Fernando","Jaiden","Titus","Travis","Bodhi","Eduardo","Dante","Ellis","Príncipe","Kane","Luka","Kash","Hendrix","Desmond","Donovan","Mario","Atticus","Cruz","Garrett","Héctor","Angelo","Jeffrey","Edwin","Cesar","Zayn","Devin","Conor","Madriguera","Odin","Jayceon","Romeo","Julius","Jaylen","Hayes","Kayson","Mahoma","Jaxton","Joaquin","Caiden","Dakota","Mayor","Keegan","Sergio","Marshall","Johnny","Kade","Edgar","Leonel","Ismael","Marco","Tyson","Vadear","Collin","Troya","Nasir","Conner","Adonis","Jared","Rory","Andy","Jase","Lennox","Shane","Malik","Ari","Caña","Seth","Clark","Erik","Lawson","Trevor","Calibrar","Nico","Malakai","Quinn","Cade","Johnathan","Sullivan","Salomón","Ciro","Fabian","Pedro","Franco","Shawn","Malcolm","Jalil","Nehemías","Dalton","Mathias","Arrendajo","Ibrahim","Peyton","Winston","Kason","Zayne","Navidad","Princeton","Matías","Gregory","Libraesterlina","Dominick","Elian","Grady","Russell","Finnegan","Rubén","Gianni","Portero","Kendrick","Leland","Pablo","Allen","Hugo","Raiden","Kolton","Remy","Ezequiel","Damon","Emanuel","Zaiden","Otón","Bowen","Marcos","Abram","Kasen","Franklin","Royce","Jonas","Sabio","Philip","Esteban","Pato","Kashton","Roberto","Harvey","Alexis","Kian","Jamison","Maximiliano","Adán","Milán","Phillip","Albert","Dax","Mohamed","Ronin","Kamden","Madeja","Memphis","Oakley","Augusto","Dibujó","Moisés","Armani","Rhys","Benson","Jayson","Kyson","Braylen","Corey","Gunnar","Omari","Alonzo","Landen","Armando","Derrick","Diestro","Enrique","Bruce","Nikolai","Francisco","Rocco","Kairo","Real","Zacarías","Arjun","Diácono","Skyler","Edén","Alijah","Rowen","atravesar","Uriel","Ronald","Luciano","Tate","Frederick","Kieran","Lawrence","Moisés","Rodrigo"};
char apellidos[500][51]={"Acosta","Acuña","Aguilar","Aguirre","Agustín","Ahumada","Alanis","Alarcón","Alayón","Alcázar","Alcocer","Alfaro","Almendárez","Altamirano","Álvarez","Alzate","Amador","Anaya","Argüelles","Arjona","Arriaga","Arrollo","Ayala","Baca","Báez","Baños","Barba","Barrera","Barrientos","Barriga","Bastida","Batalla","Bautista","Bazán","Becerra","Becerril","Bello","Beltrán","Benítez","Bernal","Bolaños","Bonilla","Borges","Bustamante","Busto","Caballero","Cabeza","Cabrera","Cadenas","Caldera","Calleja","Calles","Camacho","Camareno","Camarillo","Campos","Cárdenas","Cardoso","Carranza","Carrillo","Carvajal","Carvallo","Casas","CastellanosCastañeda","Cepeda","Cerda","Cervantes","Céspedes","Cevallos","Cevedo","Chávez","Chavira","Cisneros","Collado","Cordero","Cornejo","Correa","Corro","Cuéllar","Cuervo","Cuesta","Cuevas","Daniel","Darío","Dávila","DeAguilar","DeAlba","DelaCruz","DelaCuesta","DelaFuente","DelaRosa","DelCastillo","Doblado","Domínguez","Donato","Dorado","Duarte","Dueñas","Echeverría","Elizondo","Enríquez","Escalante","Escamilla","Escobar","Escobedo","Escoto","Escovar","Espino","Esquivel","Estévez","Estrada","Estrella","Fábregas","Falcón","Farías","Fernández","Ferreira","Ferrer","Fierro","Figueras","Flores","Fonseca","Fraga","Frías","Fuentes","Funez","Gaitán","Galán","Galeano","Galeno","Galindo","Gallegos","Galván","Gamboa","Gámez","García","Garrido","Gavilán","Gayoso","Gaytán","Gillén","Godines","Gómez","Góngora","Granada","Granados","Grijalba","Guardado","Guardiola","Guerrero","Guillén","Gutiérrez","Guzmán","Heredia","Hernández","Herrera","Hidalgo","Hierro","Huerta","Hurtado","Ibáñez","Ibarra","Icaza","Iglesias","Infante","Ivañez","Izquierdo","Jara","Jaramillo","Jerano","Jiménez","Juárez","Junco","Jurado","Lacayo","Lafuente","Lagos","Lagunal","Lamas","Lández","Larios","Lastreto","Lázaro","Leandro","Lemus","Leyva","Linares","Lines","Lira","Lizano","Llano","Lobo","Lombardo","López","Loredo","Lorio","Losada","Lozano","Lucas","Lugo","Luna","Macedo","Machado","Macías","Maduro","Magallón","Maldonado","Maltés","Mantilla","Manuel","Manzanal","Manzano","Marcías","Marrero","Marroquí","Martí","Martínez","Mateo","Matías","Maurer","Medrano","Medina","Mendoza","Mejía","Mena","Meneses","Merazo","Meza","Mijares","Milanés","Minas","Molina","Molleda","Moneda","Monge","Montalbán","Montalvo","Montecinos","Montero","Montes","Montiel","Morillo","Moscoa","Munera","Murillo","Naranjo","Navaro","Navarrete","Navarro","Nieto","Noble","Noguera","Noriega","Novales","Novo","Novoa","Núñez","Obellón","Obregón","Ocampo","Ochoa","Ordóñez","Olguín","Olivar","Olivares","Olivera","Olmeda","Olmedo","Olmo","Ordóñez","Orozco","Ortega","Ortiz","Oseda","Osorio","Ospino","Otero","Oviedo","Ozuno","Pacheco","Padilla","Páez","Palacio","Paladino","Palazuelos","Palomar","PalominoPaniagua","Pantoja","Parado","Páramo","Pardo","Paredes","Parra","Pastor","Pastrana","Patiño","Paz","Pedroza","Pena","Peña","Peralta","Peraza","Perdomo","Pineda","Pino","Plácido","Ponce","Portillo","Prada","Prieto","Puente","Quesada","Quevedo","Quijada","Quijano","Quintana","Quintanilla","Quiroga","Quiroz","Ramírez","Ramón","Ramos","Rangel","Real","Redondo","Restrepo","Reyes","Rivas","Rivera","Roble","Robles","Rojas","Roldán","Román","Romero","Rosales","Rosas","Rovira","Rubín","Rubio","Rueda","Ruiz","Sabín","Sáenz","Sagel","Sala","Salas","Salazar","Salcedo","Saldaña","Saldivar","Salinas","Salmón","Salvado","Samper","Sánchez","Sandino","Sandoval","Santiago","Santos","Sardinas","Sarmiento","Saucedo","Savala","Seballos","Sedano","Segura","Silva","Sol","Solana","Solé","Soler","Solís","Somoza","Sorio","Sotelo","Soto","Sotomayor","Soza","Suárez","Tablada","Talavera","Tames","Taracena","Tedesco","Tejada","Tobar","Torre","Torrente","Tovar","Travieso","Trejos","Treminio","Triguero","Troncoso","Trujillo","Ulloa","Ureña","Uriarte","Uribe","Urieta","Urrutia","Usaga","Uveda","Valdés","Valdiva","Valencia","Valentín","Valenzuela","Vales","Valle","Vallejo","Vanegas","Varela","Varga","Vargas","Vásquez","Vega","Vela","Velarde","Velasco","Velásquez","Venegas","Ventura","Verti","Vidal","Villallovos","Villar","Villareal","Villas","Villaseñor","Villeda","Vivas","Vivero","Vívez","Zabaleta","Zacarías","Zaldívar","Zambrano","Zamora","Zamudio","Zapata","Zarco","Zavala","Zavaleta","Zelaya","Zetina","Zuleta","Zúñiga"};


void hardcodearEmpleados(eEmployee lista[],int len)
{
    int flagSeddRandom = 1;
    int numeroRandomName;
    int numeroRandomLastName;
    int iEmpleados;
    len=len-1;
    for(iEmpleados=0 ; iEmpleados<len ; iEmpleados++)
    {

        emp_SetId(lista,-1,iEmpleados);

        numeroRandomName = getNumeroAleatorio(0,len,flagSeddRandom);
        numeroRandomLastName = getNumeroAleatorio(0,len,flagSeddRandom);

        strcpy(lista[iEmpleados].name , nombres[numeroRandomName]);
        printf("%d  ",numeroRandomName);
         printf("%s\n",nombres[numeroRandomName]);

        strcpy(lista[iEmpleados].lastName , apellidos[numeroRandomLastName]);

        lista[iEmpleados].salary = (float)getNumeroAleatorio(0,14,flagSeddRandom)*1000.0;
        lista[iEmpleados].sector = getNumeroAleatorio(0,10,flagSeddRandom);
        lista[iEmpleados].isEmpty = FALSE;


        if(iEmpleados==0)
        {
             flagSeddRandom = 0 ;
        }

    } pausarYBorrar();

}
