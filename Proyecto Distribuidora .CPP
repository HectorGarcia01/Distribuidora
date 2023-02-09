//******************LIBERIRIAS PARA DEV****************************************
//*******NOTA: SI LO EJECUTA EN DEV QUITAR EL (/*) Y EL (*/) DE LO SIGUIENTE...
//*******NOTA 2: A LA HORA DE EJECUTARLO EN DEV VAYA HASTA EL CUERPO Y LEA LA INDICACION

/*#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
}*/
//*************************************************************************

//*******************LIBRERIAS PARA BORLAND******************************
//*******NOTA: SI LO EJECUTA EN BORLAND NO HACER NADA, PERO SI LO EJECUTA EN DEV COLOCAR ESTAS LIBRERIAS EN COMENTARIO

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
//************************************************************************

FILE *acliente;      //apuntador cliente para llamar los modulos al cuerpo
FILE *aempleado;     //apuntador empleado para llamar los modulos al cuerpo
FILE *aventa;        //apuntador venta para llamar los modulos al cuerpo
FILE *aplanilla;     //apuntador venta para llamar los modulos al cuerpo

int long dir_fisica;  //Declaracion global de la variables para calcular la direccion fisica
char repet,repet1,repet2,repet3,repeE, repeC,repeP;       //Declaracion global de la Variables para repetir ciclo

int ConAdmon=12345;     //Variable global y Codigo que le permite al administrador agregar/ingresar datos

//**************PANTALLA INICIAL DE CARGA********************************
void PantallaDeCarga(){
   system("COLOR F1");
	system("mode con: cols=140 lines=38");
   gotoxy(10,3);	printf("                      `.-://+++++++++//:-.`                      ");
   gotoxy(10,4);	printf("                  .:++o++//ohood+/+h//+so++++:-`                 ");
   gotoxy(10,5);	printf("              `:+o++ [D]  /// [M] yms [A] /oy++o+:.              ");
   gotoxy(10,6);	printf("           `-+o+/yy+/yh/N+/+ys+yos+sy+m+m++m+/oh/+++:`           ");
   gotoxy(10,7);	printf("         `:o+o [A] hhoho+/++++++++++++++o+yss [R] ho+o/`         ");
   gotoxy(10,8);	printf("       `:o++yhosd/y++++o+++	          ++++++++hsoodss++o:`       ");
   gotoxy(10,9);	printf("      -o++  [D] s/+o++     ::----::   :    ++o++o [I] so+o-      ");
   gotoxy(10,10);	printf("     /o+osssyh+++o+        ::1966::  syyho+   +oo+++do+ho/o/`    ");
   gotoxy(10,11);	printf("   `+o/  [I] ++o+                    shymmdh:    oo+ [A]  /++`   ");
   gotoxy(10,12);	printf("   +ooyhssy++o+               oyhhhsshhh0hhh+     +o+//+yyso++`  ");
   gotoxy(10,13);	printf("  /o+ [S] ++o               omMMMMMMhdmNYo          o+/ [N] +o/  ");
   gotoxy(10,14);	printf(" -o+so+oy++o              +dMMMNNMMMN                o++ys++//o- ");
   gotoxy(10,15);	printf(" o+ [R] s+o              sNMMMMMhMMMmo                o+o [O] +o ");
   gotoxy(10,16);	printf("-o/sooos/o+             hddmNNdssNMMNmd               +o/yyo++/o-");
   gotoxy(10,17);	printf("/o [E] ++s             sMNmhhdNMMdMMNmM+               o++ [G] ++");
   gotoxy(10,18);	printf("++osooo++o             +MNNmmdMMMmdMMmd                o++y+/+++o");
   gotoxy(10,19);	printf("++ [V] ++o             :ymNMMNhs++smMMmh               +o/ [A] +o");
   gotoxy(10,20);	printf("++oooyy++o               +NMMMh:  hMmmMmy+  +          o+++++oo+o");
	gotoxy(10,21);	printf("/o [I] o/s               :oNMMM  :dMd yNmh++           o+s [L]  ++");
   gotoxy(10,22);	printf("-o/so+oo/o+             +ymmMMMo :NM+  +mmdh+         +o/yossy/o-");
   gotoxy(10,23);	printf(" o+ [N] y+o          +ymMMNmdhs :hMMh+   mhs::        o+s [V] +o`");
   gotoxy(10,24);	printf(" -o/oyyyo/+o     odddNNddyso+syhymmmdmmhyhhdhhyysosyso+/yohyy/o:");
   gotoxy(10,25);	printf("  /o [U] //+oshdmhNmmddddddmNNNNNNNmMMMNNNNNNNmmNNNNy+// [E] ++ ");
   gotoxy(10,26);	printf("  `++////++/+smNmdhd [CONOCEREIS LA VERDAD] NMMMMNms+/++////++`");
   gotoxy(10,27);	printf("   `+o//+mNs//oy  [Y LA VERDAD OS HARA LIBRES]   ho/// [Z] /+` ");
   gotoxy(10,28);	printf("     /o+ [G] ///+oyhNysNNNNNmNmNNNNMNNMmNhsoyhho+////oo//o/` ");
   gotoxy(10,29);	printf("      -o+////+ysoo+syhNsoshhdmNNmmMdddhsmyyyhs++yo [A]  /+o-   ");
   gotoxy(10,30);	printf("       `/o+ [U] oo+soyosyyhhshhhysNshhyhyyoos///shhh+/+o/`       ");
   gotoxy(10,31);	printf("         `/o+ooho+mo+y++o+++oosssssoo+o+/y++hy [L] ++o/.         ");
   gotoxy(10,32);	printf("           `:++ [A] yoosm/shssyyosodoyN//hms/hyo++++:`           ");
   gotoxy(10,33);	printf("              .:+o++ [T]  ////yhy+/ydymo+ [A] +++:.              ");
   gotoxy(10,34);	printf("                 `-:+*//+++ [E] */*  [M] ++o+:-`                 ");
   gotoxy(10,35);	printf("                      `--://++++o++++//::-`    ");


int i,d;

//*********Para las columnas de la barra*********************************

   for(i=80;i<120;i++){
   	gotoxy(i,15);
   	printf("%c",205);

   	gotoxy(i,19);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=15;d<19;d++){
   	gotoxy(80,d);
   	printf("%c",186);

   	gotoxy(120,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(80,15);
   printf("%c",201);

   gotoxy(80,19);
   printf("%c",200);

   gotoxy(120,15);
   printf("%c",187);

   gotoxy(120,19);
   printf("%c",188);

//****************Barra de carga interior*************************

	gotoxy(82,13);	printf("Cargando....");
   gotoxy(82,14);	printf("Proyecto Final-Distribuidora");
   gotoxy(81,5);	printf("Universidad Mariano Galvez de Guatemala");
   gotoxy(81,6);	printf("Facultad de Ingenieria en Sistemas");
   gotoxy(81,7);	printf("Programacion I");

for(int carga=81;carga<=119;carga++){



	if(carga==81){
		for(carga=81;carga<=93;carga++){
			gotoxy(carga,16);printf("%c",178);
			gotoxy(carga,17);printf("%c",178);
			gotoxy(carga,18);printf("%c",178);
			Sleep(125);
			}
		}
   if(carga==94){
		for(carga=94;carga<=107;carga++){
			gotoxy(carga,16);printf("%c",177);
			gotoxy(carga,17);printf("%c",177);
			gotoxy(carga,18);printf("%c",177);
			Sleep(120);
			}
		}
	if(carga==108){
		for(carga=108;carga<=119;carga++){
			gotoxy(carga,16);printf("%c",176);
			gotoxy(carga,17);printf("%c",176);
			gotoxy(carga,18);printf("%c",176);
			Sleep(100);
			}
	Sleep(120);
	}
}




gotoxy(83,27);	printf("Listo.. Presione cualquier tecla para continuar..");
 getch();
}



//Diseño de marcos para cada menu

void marcoGrande(){
  int i,d;

//*********Para las columnas*********************************

   for(i=5;i<107;i++){
   	gotoxy(i,1);
   	printf("%c",219);

   	gotoxy(i,33);
   	printf("%c",219);
   }
//*********Para las filas************************************

   for(d=1;d<33;d++){
   	gotoxy(5,d);
   	printf("%c",219);

   	gotoxy(107,d);
   	printf("%c",219);
   }

//***********Las esquinas*************************************
   gotoxy(5,1);
   printf("%c",219);

   gotoxy(107,1);
   printf("%c",219);

   gotoxy(5,33);
   printf("%c",219);

   gotoxy(107,33);
   printf("%c",219);
}

void marcoadGrande(){
  int i,d;

//*********Para las columnas*********************************

   for(i=6;i<106;i++){
   	gotoxy(i,2);
   	printf("%c",177);

   	gotoxy(i,32);
   	printf("%c",177);
   }
//*********Para las filas************************************

   for(d=2;d<32;d++){
   	gotoxy(6,d);
   	printf("%c",177);

   	gotoxy(106,d);
   	printf("%c",177);
   }

//***********Las esquinas*************************************
   gotoxy(6,2);
   printf("%c",177);

   gotoxy(106,2);
   printf("%c",177);

   gotoxy(6,32);
   printf("%c",177);

   gotoxy(106,32);
   printf("%c",177);
}

void marco(){
  int i,d;

//*********Para las columnas*********************************

   for(i=10;i<100;i++){
   	gotoxy(i,1);
   	printf("%c",219);

   	gotoxy(i,33);
   	printf("%c",219);
   }
//*********Para las filas************************************

   for(d=1;d<33;d++){
   	gotoxy(10,d);
   	printf("%c",219);

   	gotoxy(100,d);
   	printf("%c",219);
   }

//***********Las esquinas*************************************
   gotoxy(10,1);
   printf("%c",219);

   gotoxy(100,1);
   printf("%c",219);

   gotoxy(10,33);
   printf("%c",219);

   gotoxy(100,33);
   printf("%c",219);
}

void marcoad(){
  int i,d;

//*********Para las columnas*********************************

   for(i=11;i<99;i++){
   	gotoxy(i,2);
   	printf("%c",177);

   	gotoxy(i,32);
   	printf("%c",177);
   }
//*********Para las filas************************************

   for(d=2;d<32;d++){
   	gotoxy(11,d);
   	printf("%c",177);

   	gotoxy(99,d);
   	printf("%c",177);
   }

//***********Las esquinas*************************************
   gotoxy(11,2);
   printf("%c",177);

   gotoxy(99,2);
   printf("%c",177);

   gotoxy(11,32);
   printf("%c",177);

   gotoxy(99,32);
   printf("%c",177);
}

void marcoad2(){
  int i,d;

//*********Para las columnas*********************************

   for(i=12;i<98;i++){
   	gotoxy(i,3);
   	printf("%c",179);

   	gotoxy(i,31);
   	printf("%c",179);
   }
//*********Para las filas************************************

   for(d=3;d<31;d++){
   	gotoxy(12,d);
   	printf("%c",179);

   	gotoxy(98,d);
   	printf("%c",179);
   }

//***********Las esquinas*************************************
   gotoxy(12,3);
   printf("%c",179);

   gotoxy(98,3);
   printf("%c",179);

   gotoxy(12,31);
   printf("%c",179);

   gotoxy(98,31);
   printf("%c",179);
}

//Pantalla caratula
void caratula(){
   marco();
	system("color FC");

   gotoxy(76,21);	printf("                      ()");
   gotoxy(76,22);	printf("                    ()()");
   gotoxy(76,23);	printf("                  ()()()");
   gotoxy(76,24);	printf("                ()()()()");
   gotoxy(76,25);	printf("              ()()()()()");
   gotoxy(76,26);	printf("            ()()()()()()");
   gotoxy(76,27);	printf("          ()()()()()()()");
   gotoxy(76,28);	printf("        ()()()()()()()()");
   gotoxy(76,29);	printf("      ()()()()()()()()()");
   gotoxy(76,30);	printf("    ()()()()()()()()()()");
   gotoxy(76,31);	printf("  ()()()()()()()()()()()");
   gotoxy(76,32);	printf("()()()()()()()()()()()()");

   gotoxy(76,2);	printf("()()()()()()()()()()()()");
   gotoxy(76,3);	printf("  ()()()()()()()()()()()");
   gotoxy(76,4);	printf("    ()()()()()()()()()()");
   gotoxy(76,5);	printf("      ()()()()()()()()()");
   gotoxy(76,6);	printf("        ()()()()()()()()");
   gotoxy(76,7);	printf("          ()()()()()()()");
   gotoxy(76,8);	printf("            ()()()()()()");
   gotoxy(76,9);	printf("              ()()()()()");
   gotoxy(76,10);	printf("                ()()()()");
   gotoxy(76,11);	printf("                  ()()()");
   gotoxy(76,12);	printf("                    ()()");
   gotoxy(76,13);	printf("                      ()");

	gotoxy(13,3);	printf("Universidad Mariano Galvez de Guatemala");
   gotoxy(13,4);	printf("Facultad de Ingenieria en Sistemas");
   gotoxy(13,5);	printf("Programacion I");
   gotoxy(13,6);	printf("Ingeniero Jose Manuel Gonzalez Chua");
   gotoxy(40,14);	printf("Proyecto Final-Distribuidora:");
   gotoxy(40,15);	printf("Plasticos el Triunfador");
	gotoxy(13,20);	printf("Integrantes del grupo: ");
   gotoxy(35,22);	printf("Astrid Guisel Avila Mangandid");
	gotoxy(35,23);	printf("Carlos Daniel Vela Luna");
	gotoxy(35,24);	printf("Hector Armando Garcia Gonzalez");
	gotoxy(35,25);	printf("Jorge Leonel de Paz Martinez");
	gotoxy(35,26);	printf("Jose Damian Veliz Hernandez");
	gotoxy(35,27);	printf("Jose Isai Ixcoy Morales");
	gotoxy(35,28);	printf("Kimberly Stephanie Moreno Lopez");
   gotoxy(13,31);	printf("Preciona cualquier tecla para iniciar.");
}

//Pantalla Bienvenida
void bienvenida(){
   getch();
   system("cls");
   marco();
	system("color 0D");
	gotoxy(15,5);	printf("Bienvenido al Programa Administrativo para Distribuidora Plasticos El Triunfador");
   gotoxy(13,6);	printf("                                 (PADPET Project)                               ");
   gotoxy(22,12);	printf("PADNET version 1.0  2020-pc-windows-c++prog");
   gotoxy(22,13);	printf("of 2020.05.26 on Guatemala, modified by University Programmers");
   gotoxy(22,14);	printf("Copyright (C) 2020 Tools and Software Solutions, Inc");
   gotoxy(22,15);	printf("PADPET Project comes with ABSOLUTELY NO WARRANTY");
   gotoxy(22,17);	printf("PADNET es un Software privado... ");
   gotoxy(22,18);	printf("No esta permitida la copia de este software ni su distribucion");
   gotoxy(22,19);	printf("Consulte el manual de usuario para mas detalles");
   gotoxy(22,27);	printf("Para mas informacion acerca de PADPET Project y sus objetivos,");
   gotoxy(22,28);	printf("                   Consultar instructivo.                      ");
   gotoxy(22,30); printf("Presiona cualquier tecla para iniciar.");
}

void MenuPrincipal(){     //MENU PRINCIPAL
	getch();
   system("cls");
   marco();
	int i,d;

//*********Para las columnas*********************************

   for(i=40;i<68;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",205);

   	gotoxy(i,18);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<18;d++){
   	gotoxy(40,d);
   	printf("%c",186);

   	gotoxy(68,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(40,9);
   printf("%c",201);

   gotoxy(40,18);
   printf("%c",200);

   gotoxy(68,9);
   printf("%c",187);

   gotoxy(68,18);
   printf("%c",188);

   gotoxy(12,25);	printf("***");
   gotoxy(12,26);	printf("******");
   gotoxy(12,27);	printf("*********");
   gotoxy(12,28);	printf("************");
   gotoxy(12,29);	printf("***************");
   gotoxy(12,30);	printf("******************");
   gotoxy(12,31);	printf("*********************");
   gotoxy(12,32);	printf("************************");
   gotoxy(37,25);	printf("                     ***");
   gotoxy(37,26);	printf("                  ******");
   gotoxy(37,27);	printf("               *********");
   gotoxy(37,28);	printf("            ************");
   gotoxy(37,29);	printf("         ***************");
   gotoxy(37,30);	printf("      ******************");
   gotoxy(37,31);	printf("   *********************");
   gotoxy(37,32);	printf("************************");
   gotoxy(62,25);	printf("***");
   gotoxy(62,26);	printf("******");
   gotoxy(62,27);	printf("*********");
   gotoxy(62,28);	printf("************");
   gotoxy(62,29);	printf("***************");
   gotoxy(62,30);	printf("******************");
   gotoxy(62,31);	printf("*********************");
   gotoxy(62,32);	printf("************************");
   gotoxy(88,29);	printf("         **");
   gotoxy(88,30);	printf("      *****");
   gotoxy(88,31);	printf("   ********");
   gotoxy(88,32);	printf("***********");

   system("color 0B");
   gotoxy(48,10);	printf("MENU PRINCIPAL");
   gotoxy(46,12);	printf("1. Menu Cliente");
   gotoxy(46,13);	printf("2. Menu Empleado");
   gotoxy(46,14);	printf("3. Menu Venta");
   gotoxy(46,15);	printf("4. Menu Planilla");
   gotoxy(46,16);	printf("5. Busqueda Rapida");
   gotoxy(46,17);	printf("6. Salir");
}

//CODIGO COMPLETO DEL MODULO CLIENTE
FILE *ACliente;     		// apuntador cliente
struct sRegistro{   		//estructura del registro cliente
	char Nom_Client[30],Ape_Client[30],Correo[40];
   int NIT;
   int Tel;
    char repe;				//Variable para repetir el ciclo de modificar
}registro;

void MenuCliente(){  //MENU CLIENTE
	getch();
   system("cls");
   system("mode con: cols=110 lines=38");
   marco();
   marcoad();
   marcoad2();
   int i,d;

//*********Para las columnas*********************************

   for(i=38;i<75;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",207);

   	gotoxy(i,18);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<18;d++){
   	gotoxy(38,d);
   	printf("%c",186);

   	gotoxy(75,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(38,9);
   printf("%c",201);

   gotoxy(38,18);
   printf("%c",200);

   gotoxy(75,9);
   printf("%c",187);

   gotoxy(75,18);
   printf("%c",188);

   system("color FD");
   gotoxy(52,10);	printf("MENU CLIENTE");
   gotoxy(42,12);	printf("1. Crear Fichero");
   gotoxy(42,13);	printf("2. Agregar Cliente");
   gotoxy(42,14);	printf("3. Ver Datos");
   gotoxy(42,15);	printf("4. Modificar");
   gotoxy(42,16);	printf("5. Borrar Logicamente");
   gotoxy(42,17);	printf("6. Volver al Menu Principal");
}

void MenuModCliente(){
   system("color FA");
   marco();
   marcoad();
   marcoad2();
   int i,d;
   //*********Para las columnas*********************************

   for(i=41;i<70;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",207);

   	gotoxy(i,17);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<17;d++){
   	gotoxy(41,d);
   	printf("%c",186);

   	gotoxy(70,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(41,9);
   printf("%c",201);

   gotoxy(41,17);
   printf("%c",200);

   gotoxy(70,9);
   printf("%c",187);

   gotoxy(70,17);
   printf("%c",188);

   gotoxy(48,10);	printf("Modificar cliente");
   gotoxy(50,12);	printf("1. Nombre");
   gotoxy(50,13);	printf("2. Apellido");
   gotoxy(50,14);	printf("3. Telefono");
   gotoxy(50,15);	printf("4. Correo");

}

void CrearFichero(FILE *ACliente){ 	  //Creacion del fichero cliente
	ACliente=fopen("Cliente.dat", "r");   //Nombre del fichero, modo lectura
   system("color F5");
   if(!ACliente){
   	ACliente=fopen("Cliente.dat", "w"); //Nombre del fichero, modo escritura
      gotoxy(26,22);	printf("El fichero ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   else{
   system("color F4");
   	gotoxy(26,22);	printf("El fichero ya existe!"); printf("%c",7);
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   fclose(ACliente);
}

void AgregarCliente(FILE *ACliente){    //Modulo para agregar datos del cliente
	ACliente=fopen("Cliente.dat", "a+");		//Nombre del fichero, modo agregar
   if(ACliente==NULL){
   	system("color F4");
   	gotoxy(26,22);	printf("El fichero no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   system("cls");
   int contraAUX;      //Variable para verificar si tiene derecho a agregar datos como administrador
   marco();
   gotoxy(42,6);	printf("Ingrese el PIN del administrador: ");
   scanf("%d",&contraAUX);
   fread(&registro, sizeof(struct sRegistro), 1, ACliente);
   while(!feof(ACliente)){
      if(ConAdmon != contraAUX){
   		gotoxy(42,10);	printf("Usted no es el administrador!");
      	gotoxy(42,12);	printf("Por lo tanto no puede ingresar datos...");
      	gotoxy(17,15);	printf("Preciona cualquier tecla para continuar...");
   		fclose(ACliente);
   	}
   	fread(&registro, sizeof(struct sRegistro), 1, ACliente);
   }
   if(ConAdmon == contraAUX){
   		do{
   			system("cls");
      		marco();
   			marcoad();
   			system("color F5");
      		gotoxy(72,3);	printf("*******    _   ********");
   			gotoxy(72,4);	printf("********  / \  ********");
   			gotoxy(72,5);	printf("******** ( C ) ********");
   			gotoxy(72,6);	printf("********   \_/  ********");
   			gotoxy(72,7);	printf("********   _  ********");
   			gotoxy(72,8);	printf("********  / \  ********");
   			gotoxy(72,9);	printf("******** ( L ) ********");
   			gotoxy(72,10);	printf("********   \_/  ********");
   			gotoxy(72,11);	printf("********   _  ********");
   			gotoxy(72,12);	printf("********  / \  ********");
   			gotoxy(72,13);	printf("******** ( I ) ********");
   			gotoxy(72,14);	printf("********   \_/  ********");
   			gotoxy(72,15);	printf("********   _   ********");
   			gotoxy(72,16);	printf("********  / \  ********");
   			gotoxy(72,17);	printf("******** ( E ) ********");
   			gotoxy(72,18);	printf("********   \_/  ********");
   			gotoxy(72,19);	printf("********   _   ********");
   			gotoxy(72,20);	printf("********  / \  ********");
   			gotoxy(72,21);	printf("******** ( N ) ********");
   			gotoxy(72,22);	printf("********   \_/  ********");
   			gotoxy(72,23);	printf("********   _  ********");
   			gotoxy(72,24);	printf("********  / \  ********");
   			gotoxy(72,25);	printf("******** ( T ) ********");
   			gotoxy(72,26);	printf("********   \_/  ********");
   			gotoxy(72,27);	printf("********   _   ********");
   			gotoxy(72,28);	printf("********  / \  ********");
   			gotoxy(72,29);	printf("******** ( E ) ********");
   			gotoxy(72,30);	printf("********   \_/  ********");

            gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
   			gotoxy(36,4);	printf("PIN: \%d",ConAdmon);

   			gotoxy(17,6);	printf("Datos del cliente.");
      		for(int i=16;i<37;i++){
   				gotoxy(i,7);
   				printf("%c",177);
      		}
				gotoxy(17,8);	printf("Nombre: ");
   			fflush(stdin);
				gets(registro.Nom_Client);
				gotoxy(17,10);	printf("Apellido: ");
   			fflush(stdin);
				gets(registro.Ape_Client);
				gotoxy(17,12);	printf("Correo: ");
   			fflush(stdin);
				gets(registro.Correo);
      		fflush(stdin);
				gotoxy(17,14);	printf("NIT: ");
   			fflush(stdin);
				scanf("%d",&registro.NIT);
				gotoxy(17,16);	printf("Telefono: ");
   			fflush(stdin);
				scanf("%d",&registro.Tel);

   			fwrite(&registro, sizeof(struct sRegistro), 1, ACliente);
      		do{
      			gotoxy(17,18); printf("Desea seguir registrando clientes? SI[S] o NO[N]: ");  repeC=toupper(getche()); getch;
      		}while(repeC!='S' && repeC!='N');
   		}while(repeC=='S');
   		gotoxy(17,20);	printf("Preciona cualquier tecla para continuar...");
   		fclose(ACliente);
   	}
}

void encaC() {      //Encabezado para los datos del cliente
    system("color F5");
	 gotoxy(51,3);	printf("DATOS CLIENTE.");
    gotoxy(12,6);	printf("NO.");
    gotoxy(19,6);	printf("NOMBRE");
    gotoxy(38,6);	printf("APELLIDO");
    gotoxy(56,6);	printf("NIT");
    gotoxy(72,6);	printf("TELEFONO");
    gotoxy(84,6);	printf("CORREO");
}

void VerDatosCliente(FILE *ACliente) {  	//Modulo para ver datos del cliente
	  system("cls");
     system("mode con: cols=120 lines=38");
     int i,d;
//****************Linea superior de datos
     for(i=6;i<115;i++){
     gotoxy(i,5);
     printf("%c",177);
     }
//*********Para las columnas*********************************

   for(i=5;i<115;i++){
   	gotoxy(i,1);
   	printf("%c",219);

   	gotoxy(i,33);
   	printf("%c",219);
   }
//*********Para las filas************************************

   for(d=1;d<33;d++){
   	gotoxy(5,d);
   	printf("%c",219);

   	gotoxy(115,d);
   	printf("%c",219);
   }

//***********Las esquinas*************************************
   gotoxy(5,1);
   printf("%c",219);

   gotoxy(115,1);
   printf("%c",219);

   gotoxy(5,33);
   printf("%c",219);

   gotoxy(115,33);
   printf("%c",219);
     system("color F5");
     encaC();
     int numero1=1;
     ACliente = fopen ("Cliente.dat", "r");
     if(ACliente==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }

     fread(&registro, sizeof(struct sRegistro), 1, ACliente);

     while(!feof(ACliente)){
     		gotoxy(12,numero1+6);	printf("\%d",numero1);
     		gotoxy(19,numero1+6);	printf("\%s",registro.Nom_Client);
     		gotoxy(38,numero1+6);	printf("\%s",registro.Ape_Client);
     		gotoxy(56,numero1+6);	printf("\%d",registro.NIT);
     		gotoxy(72,numero1+6);	printf("\%d",registro.Tel);
     		gotoxy(84,numero1+6);	printf("\%s",registro.Correo);

     		fread(&registro, sizeof(struct sRegistro), 1, ACliente);
     		numero1++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(ACliente);
}

void ModCliente(FILE *ACliente){     //Modificar cliente
	 system("cls");
    system("color FA");
  	 marco();
    marcoad();
    marcoad2();
    int op;
    int NITaux;                            //Variable para realizar la busqueda
    char seguir2;                            //Variable para repetir el ciclo
	 ACliente=fopen("Cliente.dat","r+b");
    if(ACliente==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
    }
    int contraMOAUX;      //Variable para verificar si tiene derecho a agregar datos como administrador
    gotoxy(42,6);	printf("Ingrese el PIN del administrador: ");
    scanf("%d",&contraMOAUX);
    if(ConAdmon != contraMOAUX){
   	gotoxy(42,10);	printf("Usted no es el administrador!");
     	gotoxy(42,12);	printf("Por lo tanto no puede borrar registros...");
     	gotoxy(17,15);	printf("Preciona cualquier tecla para continuar...");
   	fclose(ACliente);
   }
   else{
   	system("cls");
   	system("color FA");
		marcoGrande();
   	marcoadGrande();
      gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
      gotoxy(36,4);	printf("CONTRASEÑA: \%d",ConAdmon);
    	gotoxy(14,6); printf("Ingrese el NIT del cliente a modificar: ");
    	scanf("%i", &NITaux);
    	sRegistro registro;
    	fread(&registro, sizeof(sRegistro), 1, ACliente);
    	while(!feof(ACliente)){
        if (NITaux==registro.NIT){
        	do{
         	system("cls");
        		MenuModCliente();
      		gotoxy(27,19); printf("Escoja el dato que desea modificar: ");
      		scanf("%d",&op);

	        if (op==1){
	           gotoxy(14,21); printf("Informacion actual: %s ",registro.Nom_Client);
	           gotoxy(14,22);printf("Ingrese nuevo nombre: ");
              fflush(stdin);
	           gets(registro.Nom_Client);
              fflush(stdin);
	           int pos=ftell(ACliente)-sizeof(sRegistro);
	           fseek(ACliente,pos,SEEK_SET);
	           fwrite(&registro, sizeof(sRegistro), 1, ACliente);
	           gotoxy(14,24); printf("Se modifico el nombre del cliente.");
           }
	      	else
	       	if (op==2){
	           gotoxy(14,21); printf("Informacion actual: %s ", registro.Ape_Client);
	           gotoxy(14,22);printf("Ingrese nuevo apellido: ");
              fflush(stdin);
	           gets(registro.Ape_Client);
              fflush(stdin);
	           int pos=ftell(ACliente)-sizeof(sRegistro);
	           fseek(ACliente,pos,SEEK_SET);
	           fwrite(&registro, sizeof(sRegistro), 1, ACliente);
	           gotoxy(14,24); printf("Se modifico el apellido del cliente.");
	        }
           else
	       	if (op==3){
	           gotoxy(14,21);printf("Informacion actual: %d ", registro.Tel);
	           gotoxy(14,22);printf("Ingrese nuevo telefono: ");
              fflush(stdin);
	           scanf("%d",&registro.Tel);
              fflush(stdin);
	           int pos=ftell(ACliente)-sizeof(sRegistro);
	           fseek(ACliente,pos,SEEK_SET);
	           fwrite(&registro, sizeof(sRegistro), 1, ACliente);
	           gotoxy(14,24); printf("Se modifico el telefono del cliente.");
	        }
         	else
	       	if (op==4){
	           gotoxy(14,21);printf("Informacion actual: %s ", registro.Correo);
	           gotoxy(14,22);printf("Ingrese nuevo correo: ");
              fflush(stdin);
	           gets(registro.Correo);
              fflush(stdin);
	           int pos=ftell(ACliente)-sizeof(sRegistro);
	           fseek(ACliente,pos,SEEK_SET);
	           fwrite(&registro, sizeof(sRegistro), 1, ACliente);
	           gotoxy(14,24);printf("Se modifico el correo del cliente.");
	        }
         else
	       if (op==5){
          	return;
	        }
           do{
            	gotoxy(14,25); printf("Desea seguir modificando? SI[S] o NO[N]: "); seguir2=toupper(getche());
            }while(seguir2!='S' && seguir2!='N');
          }while(seguir2=='S');
          return;
        }
        fread(&registro, sizeof(sRegistro), 1, ACliente);
    	}
    	if(NITaux!=registro.NIT){
        	gotoxy(20,14); printf("No existe un cliente con dicho NIT!");
    	}
    	fclose(ACliente);
    	gotoxy(14,27); printf("Presione una tecla para continuar");
    	getch();
   }
}

void BoClienteLogica(FILE *ACliente){
	system("cls");
   int op11;
   int NITaux1;                            //Variable para realizar la busqueda
	ACliente=fopen("Cliente.dat","r+b");
   if(ACliente==NULL) {
   	gotoxy(26,22);	printf("Fichero no existe!");
      gotoxy(26,23);	printf("Por favor creelo!");
   	gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     	return;
   }
   int contraBAUX;      //Variable para verificar si tiene derecho a agregar datos como administrador
   gotoxy(42,6);	printf("Ingrese el PIN del administrador: ");
   scanf("%d",&contraBAUX);
   if(ConAdmon != contraBAUX){
   	gotoxy(42,10);	printf("Usted no es el administrador!");
     	gotoxy(42,12);	printf("Por lo tanto no puede borrar registros...");
     	gotoxy(17,15);	printf("Preciona cualquier tecla para continuar...");
   	fclose(ACliente);
   }
   else{
   	system("cls");
   	system("color FA");
		marcoGrande();
   	marcoadGrande();
      gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
      gotoxy(36,4);	printf("CONTRASEÑA: \%d",ConAdmon);
   	gotoxy(14,8); printf("Ingrese el NIT del cliente a Borrar: ");
   	scanf("%i", &NITaux1);
   	sRegistro registro;
   	fread(&registro, sizeof(sRegistro), 1, ACliente);
   	while(!feof(ACliente)){
      	if (NITaux1==registro.NIT){
         	system("cls");
            marcoGrande();
   			marcoadGrande();
            gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
   			gotoxy(36,4);	printf("CONTRASEÑA: \%d",ConAdmon);
         	gotoxy(45,7);	printf("DATOS CLIENTE A BORRAR");
   			gotoxy(10,10);	printf("NOMBRE");
   			gotoxy(29,10);	printf("APELLIDO");
   			gotoxy(50,10);	printf("NIT");
   			gotoxy(62,10);	printf("TELEFONO");
   			gotoxy(74,10);	printf("CORREO");
   			gotoxy(10,12);	printf("\%s",registro.Nom_Client);
   			gotoxy(29,12);	printf("\%s",registro.Ape_Client);
   			gotoxy(50,12);	printf("\%d",registro.NIT);
   			gotoxy(62,12);	printf("\%d",registro.Tel);
   			gotoxy(74,12);	printf("\%s",registro.Correo);

         	strcpy(registro.Nom_Client,"BORRADO");
         	strcpy(registro.Ape_Client,"BORRADO");
         	registro.NIT=NULL;
         	registro.Tel=NULL;
         	strcpy(registro.Correo,"BORRADO");
         	do {
         		gotoxy(10,15);printf ("Esta seguro que desea borrarlo? SI[S] o NO[N]: "); op11=toupper(getche()); getch();
				}while(op11!='S' && op11!='N');
				if(op11=='S'){
            	int pos1=ftell(ACliente)-sizeof(sRegistro);
	           	fseek(ACliente,pos1,SEEK_SET);
	           	fwrite(&registro, sizeof(sRegistro), 1, ACliente);
              	gotoxy(10,18); printf ("Registro eliminado con exito!!!");
            }
             fclose(ACliente);
             gotoxy(10,24);	printf("Preciona cualquier tecla para continuar...");
             return;
        	}
      	fread(&registro, sizeof(struct sRegistro), 1, ACliente);
    	}
   	gotoxy(10,15);printf("No se encuentra ese registro en el archivo!!");
   	fclose(ACliente);
   	gotoxy(10,24);	printf("Preciona cualquier tecla para continuar...");
   	return;
   }
}


//CODIGO COMPLETO DEL MENU EMPLEADO
FILE *AEmpleado;					//apuntador empleado
struct sRegistroE{            //estructura del registro empleado
	char Nom_emp[30], Ape_emp[30], correo1[40];
   char client_emp[30],cargo_emp[30], t_equipo[40], mobi[40];
   int NIT1,Tel1,cod_emp,contra;

}registroE;

void MenuEmpleado(){    //MENU EMPLEADO
	getch();
   system("cls");
   marco();
    int i,d;

//*********Para las columnas*********************************

   for(i=38;i<75;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",167);

   	gotoxy(i,18);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<18;d++){
   	gotoxy(38,d);
   	printf("%c",186);

   	gotoxy(75,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(38,9);
   printf("%c",201);

   gotoxy(38,18);
   printf("%c",200);

   gotoxy(75,9);
   printf("%c",187);

   gotoxy(75,18);
   printf("%c",188);
   system("color 17");
   gotoxy(52,10);	printf("MENU EMPLEADO");
   gotoxy(42,12);	printf("1. Crear Fichero");
   gotoxy(42,13);	printf("2. Agregar Empleado");
   gotoxy(42,14);	printf("3. Ver Datos");
   gotoxy(42,15);	printf("4. Modificar");
   gotoxy(42,16);	printf("5. Borrar");
   gotoxy(42,17);	printf("6. Volver al Menu Principal");


   gotoxy(76,2);	printf("()()()()()()()()()()()()");
   gotoxy(76,3);	printf("  ()()()()()()()()()()()");
   gotoxy(76,4);	printf("    ()()()()()()()()()()");
   gotoxy(76,5);	printf("      ()()()()()()()()()");
   gotoxy(76,6);	printf("        ()()()()()()()()");
   gotoxy(76,7);	printf("          ()()()()()()()");
   gotoxy(76,8);	printf("            ()()()()()()");
   gotoxy(76,9);	printf("              ()()()()()");
   gotoxy(76,10);	printf("                ()()()()");
   gotoxy(76,11);	printf("                  ()()()");
   gotoxy(76,12);	printf("                    ()()");
   gotoxy(76,13);	printf("                      ()");

   gotoxy(12,23);	printf("*");
   gotoxy(12,24);	printf("**");
   gotoxy(12,25);	printf("***");
   gotoxy(12,26);	printf("******");
   gotoxy(12,27);	printf("*********");
   gotoxy(12,28);	printf("************");
   gotoxy(12,29);	printf("***************");
   gotoxy(12,30);	printf("******************");
   gotoxy(12,31);	printf("*********************");
   gotoxy(12,32);	printf("************************");
}

void MenuDatosE(){      //MENU PARA DATOS DEL EMPLEADO
	getch();
   system("mode con: cols=110 lines=38");     //tamaño de la ventana
   system("cls");
   marco();
	int i,d;

//*********Para las columnas*********************************

   for(i=38;i<77;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",167);

   	gotoxy(i,19);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<19;d++){
   	gotoxy(38,d);
   	printf("%c",186);

   	gotoxy(77,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(38,9);
   printf("%c",201);

   gotoxy(38,19);
   printf("%c",200);

   gotoxy(77,9);
   printf("%c",187);

   gotoxy(77,19);
   printf("%c",188);

   gotoxy(12,25);	printf("***");
   gotoxy(12,26);	printf("******");
   gotoxy(12,27);	printf("*********");
   gotoxy(12,28);	printf("************");
   gotoxy(12,29);	printf("***************");
   gotoxy(12,30);	printf("******************");
   gotoxy(12,31);	printf("*********************");
   gotoxy(12,32);	printf("************************");
   gotoxy(37,25);	printf("                     ***");
   gotoxy(37,26);	printf("                  ******");
   gotoxy(37,27);	printf("               *********");
   gotoxy(37,28);	printf("            ************");
   gotoxy(37,29);	printf("         ***************");
   gotoxy(37,30);	printf("      ******************");
   gotoxy(37,31);	printf("   *********************");
   gotoxy(37,32);	printf("************************");
   gotoxy(62,25);	printf("***");
   gotoxy(62,26);	printf("******");
   gotoxy(62,27);	printf("*********");
   gotoxy(62,28);	printf("************");
   gotoxy(62,29);	printf("***************");
   gotoxy(62,30);	printf("******************");
   gotoxy(62,31);	printf("*********************");
   gotoxy(62,32);	printf("************************");
   gotoxy(88,29);	printf("         **");
   gotoxy(88,30);	printf("      *****");
   gotoxy(88,31);	printf("   ********");
   gotoxy(88,32);	printf("***********");


   system("color 1F");
   gotoxy(52,10);	printf("VER DATOS");
   gotoxy(42,12);	printf("1. Datos Personales del Empleado");
   gotoxy(42,13);	printf("2. Cargo del Empleado");
   gotoxy(42,14);	printf("3. Cliente Empleado");    //El cliente empleado lo tomamos como el/los clientes que posee el empleado
   gotoxy(42,15);	printf("4. Tipo de Equipo");
   gotoxy(42,16);	printf("5. Mobiliario");
   gotoxy(42,17);	printf("6. Contraseña");
   gotoxy(42,18);	printf("7. Volver al Menu Empleado");
}

void MenuModEmpleado(){
      marco();
  	   marcoad();
   int i,d;
   //*********Para las columnas*********************************

   for(i=41;i<75;i++){
   	gotoxy(i,7);
   	printf("%c",205);

      gotoxy(i,9);
   	printf("%c",177);

   	gotoxy(i,21);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=7;d<21;d++){
   	gotoxy(41,d);
   	printf("%c",186);

   	gotoxy(75,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(41,7);
   printf("%c",201);

   gotoxy(41,21);
   printf("%c",200);

   gotoxy(75,7);
   printf("%c",187);

   gotoxy(75,21);
   printf("%c",188);


   system("color 5F");
   gotoxy(50,8);	printf("Modificar empleado");
   gotoxy(46,10);	printf("1. Nombre");
   gotoxy(46,11);	printf("2. Apellido");
   gotoxy(46,12);	printf("3. Telefono");
   gotoxy(46,13);	printf("4. Correo");
   gotoxy(46,14);	printf("5. Pin");
   gotoxy(46,15);	printf("6. Cargo");
   gotoxy(46,16);	printf("7. Tipo de Equipo");
   gotoxy(46,17);	printf("8. Mobiliario");
   gotoxy(46,18);	printf("9. Volver al Menu Empleado");
}

void CrearFicheroE(FILE *AEmpleado){     //Creacion del fichero empleado
	AEmpleado=fopen("Empleado.dat", "r");   //Nombre del fichero, modo lectura
   if(!AEmpleado){
   	AEmpleado=fopen("Empleado.dat", "w"); //Nombre del fichero, modo escritura
      gotoxy(26,22);	printf("El fichero ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   else{
   	system("color 9F");
   	gotoxy(26,22);	printf("El fichero ya existe!"); printf("%c",7);
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   fclose(AEmpleado);
}

void AgregarEmpleado(FILE *AEmpleado){    //Modulo para agregar datos del empleado
	AEmpleado=fopen("Empleado.dat", "a+");		//Nombre del fichero, modo agregar
   if(AEmpleado==NULL){
   	gotoxy(26,22);	printf("El fichero no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   system("cls");
   int conAUX;
   marco();										//Variable para verificar si tiene derecho a agregar datos como administrador
   gotoxy(42,6);	printf("Ingrese el PIN del administrador: ");
   scanf("%d",&conAUX);
   fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   while(!feof(AEmpleado)){
      if(ConAdmon != conAUX){
   		gotoxy(42,10);	printf("Usted no es el administrador!");
      	gotoxy(42,12);	printf("Por lo tanto no puede ingresar datos...");
      	gotoxy(17,15);	printf("Preciona cualquier tecla para continuar...");
   	}
   	fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   }
   if(ConAdmon == conAUX){
   		do{
   			system("cls");
      		marcoGrande();
   			gotoxy(72,6);	printf("*******    _   ********");
   			gotoxy(72,7);	printf("********  / \   ********");
   			gotoxy(72,8);	printf("******** ( E ) ********");
   			gotoxy(72,9);	printf("********   \_/  ********");
   			gotoxy(72,10);	printf("******** ( M ) ********");
   			gotoxy(72,11);	printf("********   \_/  ********");
   			gotoxy(72,12);	printf("******** ( P ) ********");
   			gotoxy(72,13);	printf("********   \_/  ********");
   			gotoxy(72,14);	printf("******** ( L ) ********");
   			gotoxy(72,15);	printf("********   \_/  ********");
   			gotoxy(72,16);	printf("******** ( E ) ********");
   			gotoxy(72,17);	printf("********   \_/  ********");
   			gotoxy(72,18);	printf("******** ( A ) ********");
   			gotoxy(72,19);	printf("********   \_/  ********");
   			gotoxy(72,20);	printf("******** ( D ) ********");
   	      gotoxy(72,21);	printf("********   \_/  ********");
		   	gotoxy(72,22);	printf("******** ( O ) ********");
		   	gotoxy(72,23);	printf("********   \_/  ********");

            gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
   			gotoxy(36,4);	printf("PIN: \%d",ConAdmon);

		   	gotoxy(15,6);	printf("Datos del empleado.");
		      gotoxy(11,8);	printf("ID: ");      //Codigo que les imparte la empresa
		   	fflush(stdin);
		   	scanf("%d",&registroE.cod_emp);
				gotoxy(11,10);	printf("Nombre: ");
		   	fflush(stdin);
				gets(registroE.Nom_emp);
				gotoxy(11,12);	printf("Apellido: ");
		   	fflush(stdin);
		   	gets(registroE.Ape_emp);
		   	gotoxy(11,14);	printf("NIT: ");
		   	fflush(stdin);
		   	scanf("%d",&registroE.NIT1);
		   	gotoxy(11,16);	printf("Telefono: ");
		   	fflush(stdin);
		   	scanf("%d",&registroE.Tel1);
		   	gotoxy(11,18);	printf("Correo: ");
		   	fflush(stdin);
		   	gets(registroE.correo1);
		   	fflush(stdin);
		   	gotoxy(11,20);	printf("Pin: ");            //pin para acceder a informacion
		   	scanf("%d",&registroE.contra);
		   	gotoxy(11,22);	printf("Cargo de trabajo: ");
		   	fflush(stdin);
		   	gets(registroE.cargo_emp);
		   	fflush(stdin);
		   	gotoxy(11,24);	printf("Cliente: ");               //El cliente que posee el empleado
		   	fflush(stdin);
		   	gets(registroE.client_emp);
		   	fflush(stdin);
		   	gotoxy(11,26);	printf("Tipo de equipo: ");
		   	fflush(stdin);
		   	gets(registroE.t_equipo);
		   	gotoxy(11,28);	printf("Mobiliario: ");
		   	fflush(stdin);
		   	gets(registroE.mobi);
		   	fwrite(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
		      do{
		      	gotoxy(11,30);printf("Desea seguir registrando Empleados? SI[S] o NO[N]: ");  repeE=toupper(getche()); getch;
		      }while(repeE!='S' && repeE!='N');
		   }while(repeE=='S');
		   gotoxy(11,32);	printf("Presione cualquier tecla para continuar...");
		   fclose(AEmpleado);
      }
}

void EncaPersoEmp(){           //Encabezado de datos personales del empleado
	 system("color 3F");
	 gotoxy(50,3);	printf("DATOS PERSONALES.");
    gotoxy(7,6);	printf("NO.");
    gotoxy(12,6);	printf("ID");
    gotoxy(22,6);	printf("NOMBRE");
    gotoxy(40,6);	printf("APELLIDO");
    gotoxy(58,6);	printf("NIT");
    gotoxy(74,6);	printf("TELEFONO");
    gotoxy(84,6);	printf("CORREO");
}


void marcoDatos(){
	int i,d;

//*********Para las columnas*********************************

   for(i=5;i<113;i++){
   	gotoxy(i,1);
   	printf("%c",219);

      gotoxy(i,5);
      printf("%c",177);

   	gotoxy(i,33);
   	printf("%c",219);
   }
//*********Para las filas************************************

   for(d=1;d<33;d++){
   	gotoxy(5,d);
   	printf("%c",219);

   	gotoxy(113,d);
   	printf("%c",219);
   }

//***********Las esquinas*************************************
   gotoxy(5,1);
   printf("%c",219);

   gotoxy(113,1);
   printf("%c",219);

   gotoxy(5,33);
   printf("%c",219);

   gotoxy(113,33);
   printf("%c",219);

}

void DatosPersoEmp(FILE *AEmpleado){           //Ver los Datos personales del empleado
   system("cls");
   system("color 9F");
   int numero2=1;
     AEmpleado = fopen ("Empleado.dat", "r");
     if(AEmpleado==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");printf("%c",7);
         gotoxy(26,23);	printf("Por favor creelo!");
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }

     system("mode con: cols=115 lines=38");
     marcoDatos();
     EncaPersoEmp();
     fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);

     while(!feof(AEmpleado)){
     		gotoxy(7,numero2+6);	printf("\%d",numero2);
         gotoxy(12,numero2+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(22,numero2+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(40,numero2+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(58,numero2+6);	printf("\%d",registroE.NIT1);
     		gotoxy(74,numero2+6);	printf("\%d",registroE.Tel1);
         gotoxy(84,numero2+6);	printf("\%s",registroE.correo1);

     		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
     		numero2++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(AEmpleado);
}

void EncaCargoEmp(){           //Encabezado de Cargo empleado
	 system("color 3F");
	 gotoxy(50,3);	printf("CARGO DEL EMPLEADO.");
    gotoxy(8,6);	printf("NO.");
    gotoxy(15,6);	printf("ID");
    gotoxy(27,6);	printf("NOMBRE");
    gotoxy(48,6);	printf("APELLIDO");
    gotoxy(70,6);	printf("CARGO");
}

void VerCargoEmpleado(FILE *AEmpleado){       // Ver el cargo del empleado
	system("cls");
   system("color 9F");
	EncaCargoEmp();
//****************Linea superior de datos
   for(int i=6;i<107;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
   int numero3=1;
     AEmpleado = fopen ("Empleado.dat", "r");
     if(AEmpleado==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!"); printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }
     marcoGrande();
     fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);

     while(!feof(AEmpleado)){
     		gotoxy(8,numero3+6);	printf("\%d",numero3);
         gotoxy(15,numero3+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(27,numero3+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(48,numero3+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(70,numero3+6);	printf("\%s",registroE.cargo_emp);

     		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
     		numero3++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(AEmpleado);
}

void EncaClientEmp(){           //Encabezado de Cliente del empleado
	 system("color 3F ");
	 gotoxy(50,3);	printf("CLIENTE DEL EMPLEADO.");
    gotoxy(40,4);	printf("EMPLEADO.");
    gotoxy(80,4);	printf("CLIENTE.");
    gotoxy(8,6);	printf("NO.");
    gotoxy(12,6);	printf("ID");
    gotoxy(22,6);	printf("NOMBRE");
    gotoxy(43,6);	printf("APELLIDO");
    gotoxy(60,6);	printf("CARGO");
    gotoxy(78,6);	printf("NOMBRE");
}

void VerClientEmpleado(FILE *AEmpleado){       //  Ver Cliente del empleado
	system("cls");
   marcoGrande();
//****************Linea superior de datos
   for(int i=6;i<107;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
   system("color 3F");
	EncaClientEmp();
   int numero4=1;
     AEmpleado = fopen ("Empleado.dat", "r");
     if(AEmpleado==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }

     fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);

     while(!feof(AEmpleado)){
     		gotoxy(8,numero4+6);	printf("\%d",numero4);
         gotoxy(12,numero4+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(22,numero4+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(43,numero4+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(60,numero4+6);	printf("\%s",registroE.cargo_emp);
         gotoxy(78,numero4+6);	printf("\%s",registroE.client_emp);

     		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
     		numero4++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(AEmpleado);
}

void EncaTipoEqui(){           //Encabezado de Tipo de Equipo
	 system("color 3F");
	 gotoxy(50,3);	printf("TIPO DE EQUIPO.");
    gotoxy(8,6);	printf("NO.");
    gotoxy(12,6);	printf("ID");
    gotoxy(22,6);	printf("NOMBRE");
    gotoxy(44,6);	printf("APELLIDO");
    gotoxy(61,6);	printf("CARGO");
    gotoxy(79,6);	printf("EQUIPO");
}

void VerTipoEquipo(FILE *AEmpleado){       //  Ver Tipo de Equipo
	system("cls");
   system("color 3F");
   marcoGrande();
//****************Linea superior de datos
   for(int i=6;i<107;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
	EncaTipoEqui();
   int numero5=1;
     AEmpleado = fopen ("Empleado.dat", "r");
     if(AEmpleado==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }

     fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);

     while(!feof(AEmpleado)){
     		gotoxy(8,numero5+6);	printf("\%d",numero5);
         gotoxy(12,numero5+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(22,numero5+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(44,numero5+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(61,numero5+6);	printf("\%s",registroE.cargo_emp);
         gotoxy(79,numero5+6);	printf("\%s",registroE.t_equipo);

     		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
     		numero5++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(AEmpleado);
}

void EncaMobi(){           //Encabezado de Mobiliario
	 system("color 3F");
	 gotoxy(50,3);	printf("MOBILIARIO.");
    gotoxy(8,6);	printf("NO.");
    gotoxy(12,6);	printf("ID");
    gotoxy(22,6);	printf("NOMBRE");
    gotoxy(44,6);	printf("APELLIDO");
    gotoxy(62,6);	printf("CARGO");
    gotoxy(79,6);	printf("MOBILIARIO");
}

void VerMobiliario(FILE *AEmpleado){       //  Ver Mobiliario
	system("cls");
   system("color 3F");
   marcoGrande();
	EncaMobi();
//****************Linea superior de datos
   for(int i=6;i<107;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
   int numero6=1;
     AEmpleado = fopen ("Empleado.dat", "r");
     if(AEmpleado==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }

     fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);

     while(!feof(AEmpleado)){
     		gotoxy(8,numero6+6);	printf("\%d",numero6);
         gotoxy(12,numero6+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(22,numero6+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(44,numero6+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(62,numero6+6);	printf("\%s",registroE.cargo_emp);
         gotoxy(79,numero6+6);	printf("\%s",registroE.mobi);

     		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
     		numero6++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(AEmpleado);
}


void EncaContraEmp(){           //Encabezado de datos personales del empleado
	 system("color 3F");
    marcoGrande();
	 gotoxy(50,3);	printf("DATOS PERSONALES.");
    gotoxy(7,6);	printf("NO.");
    gotoxy(12,6);	printf("ID");
    gotoxy(22,6);	printf("NOMBRE");
    gotoxy(40,6);	printf("APELLIDO");
    gotoxy(58,6);	printf("NIT");
    gotoxy(74,6);	printf("PIN");
}

void 	VerContraEm(FILE *AEmpleado){           //Ver contraseña/pin del empleado
   system("cls");
   system("color 9F");
	EncaContraEmp();
//****************Linea superior de datos
   for(int i=6;i<107;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
   int numero7=1;
     AEmpleado = fopen ("Empleado.dat", "r");
     if(AEmpleado==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");printf("%c",7);
         gotoxy(26,23);	printf("Por favor creelo!");
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }
     marcoGrande();
     fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);

     while(!feof(AEmpleado)){
     		gotoxy(7,numero7+6);	printf("\%d",numero7);
         gotoxy(12,numero7+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(22,numero7+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(40,numero7+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(58,numero7+6);	printf("\%d",registroE.NIT1);
     		gotoxy(74,numero7+6);	printf("\%d",registroE.contra);

     		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
     		numero7++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(AEmpleado);
}


void ModEmpleado(FILE *AEmpleado){     //Modificar empleado
	system("cls");
   marco();
   marcoad();
   int op1;
   int Daux;                            //Variable para realizar la busqueda
   char seguir;                          //Variable para repetir el ciclo
	AEmpleado=fopen("Empleado.dat","r+b");
    if (AEmpleado==NULL){
    		system("color 5C");
    		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
    }
    int contraMBAUX;      //Variable para verificar si tiene derecho a agregar datos como administrador
   gotoxy(42,6);	printf("Ingrese el PIN del administrador: ");
   scanf("%d",&contraMBAUX);
   if(ConAdmon != contraMBAUX){
   	gotoxy(42,10);	printf("Usted no es el administrador!");
     	gotoxy(42,12);	printf("Por lo tanto no puede modificar registros...");
     	gotoxy(17,15);	printf("Preciona cualquier tecla para continuar...");
   	fclose(AEmpleado);
   }
   else{
   	system("cls");
   	system("color FA");
		marcoGrande();
   	marcoadGrande();
      gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
      gotoxy(36,4);	printf("PIN: \%d",ConAdmon);
    	gotoxy(15,6);printf("Ingrese el NIT del empleado a modificar: ");
    	scanf("%i", &Daux);
    	sRegistroE registroE;
    	fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
    	while(!feof(AEmpleado)){
      	if (Daux == registroE.NIT1){
         	do{
         		system("cls");
      			MenuModEmpleado();
      			gotoxy(26,23); printf(" Escoja el dato que desea modificar: ");
      			scanf("%d",&op1);
	        		if (op1==1){
            		gotoxy(15,25);printf("La informacion actual: %s ", registroE.Nom_emp);
            		gotoxy(15,26);printf("Ingrese nuevo nombre: ");
            		fflush(stdin);
            		gets(registroE.Nom_emp);
              		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el nombre del empleado.");
	        		}
	        		else
	        		if (op1==2){
            		gotoxy(15,25);printf("Informacion actual: %s ", registroE.Ape_emp);
	           		gotoxy(15,26);printf("Ingrese nuevo apellido: ");
	           		fflush(stdin);
	           		gets(registroE.Ape_emp);
	           		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el apellido del empleado.");
	        		}
	    			else
	       		if (op1==3){
	           		gotoxy(15,25);printf("Informacion actual: %d ", registroE.Tel1);
	           		gotoxy(15,26);printf("Ingrese nuevo telefono: ");
	           		fflush(stdin);
	           		scanf("%d",&registroE.Tel1);
	           		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el telefono del empleado.");
	        		}
	        		else
	       		if (op1==4){
	           		gotoxy(15,25);printf("Informacion actual: %s ", registroE.correo1);
	           		gotoxy(15,26);printf("Ingrese nuevo correo: ");
	           		fflush(stdin);
	           		gets(registroE.correo1);
	           		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el correo del empleado.");
	        		}
	        		else
           		if (op1==5){
	           		gotoxy(15,25);printf("Informacion actual: %d ", registroE.contra);
	           		gotoxy(15,26);printf("Ingrese nuevo pin: ");
	           		scanf("%d",&registroE.contra);
               	int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el pin del empleado.\n");
	        		}
	        		else
           		if (op1==6){
	           		gotoxy(15,25);printf("Informacion actual: %s ", registroE.cargo_emp);
	           		gotoxy(15,26);printf("Ingrese nuevo cargo: ");
	           		fflush(stdin);
	           		gets(registroE.cargo_emp);
	           		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el cargo del empleado.");
	        		}
           		else
           		if (op1==7){
	           		gotoxy(15,25);printf("Informacion actual: %s ", registroE.t_equipo);
	           		gotoxy(15,26);printf("Ingrese nuevo equipo: ");
	           		fflush(stdin);
	           		gets(registroE.t_equipo);
	           		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el equipo del empleado.");
	        		}
           		else
               if (op1==8){
	           		gotoxy(15,25);printf("Informacion actual: %s ", registroE.mobi);
	           		gotoxy(15,26);printf("Ingrese nuevo mobiliario: ");
	           		fflush(stdin);
	           		gets(registroE.mobi);
	           		fflush(stdin);
	           		int pos=ftell(AEmpleado)-sizeof(sRegistroE);
	           		fseek(AEmpleado,pos,SEEK_SET);
	           		fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
	           		gotoxy(15,28);printf("Se modifico el mobiliario del empleado.");
	        		}
	        		else
	        		if (op1==9){
	        			return;
	        		}
            	do{
            		gotoxy(14,30); printf("Desea seguir modificando? SI[S] o NO[N]: "); seguir=toupper(getche());
            	}while(seguir!='S' && seguir!='N');
          	}while(seguir=='S');
          	return;
        	}
        	fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
    	}
    	if (Daux != registroE.NIT1){
      	gotoxy(14,14); printf("No existe un Empleado con dicho NIT!");
    	}
    	fclose(AEmpleado);
    	gotoxy(14,26); printf("Presione una tecla para continuar");
    	getch();
   }
}

//************Modulo de borrar empleado******************

void BoEmpleado(FILE *AEmpleado){
	system("cls");
   system("color FA");
  	marcoGrande();
   marcoadGrande();
   int op12;
   int IDaux1;                            //Variable para realizar la busqueda
	AEmpleado=fopen("Empleado.dat", "r+b");
  	if(AEmpleado==NULL){
   	system("color AF");
   	gotoxy(26,22);	printf("El fichero no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");  printf("%c",7);
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      getch();
      return;
   }
   int CONAUX;      //Variable para verificar si tiene derecho a agregar datos como administrador
   gotoxy(42,6);	printf("Ingrese el PIN del administrador: ");
   scanf("%d",&CONAUX);
   if(ConAdmon != CONAUX){
   	gotoxy(42,10);	printf("Usted no es el administrador!");
     	gotoxy(42,12);	printf("Por lo tanto no puede borrar registros...");
     	gotoxy(17,15);	printf("Preciona cualquier tecla para continuar...");
   	fclose(AEmpleado);
   }
   else{
   	system("cls");
   	system("color FA");
		marcoGrande();
   	marcoadGrande();
      gotoxy(36,3);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
      gotoxy(36,4);	printf("PIN: \%d",ConAdmon);
   	gotoxy(14,6); printf("Ingrese el ID del Empleado a Borrar:");
   	scanf("%i", &IDaux1);
   	fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   	while(!feof(AEmpleado)){
   		if(registroE.cod_emp == IDaux1){
      		system("cls");
         	system("color FA");
  	 			marcoGrande();
    			marcoadGrande();
     			gotoxy(50,3);	printf("DATOS EMPLEADO.");
   			gotoxy(10,6);	printf("ID");
   			gotoxy(22,6);	printf("NOMBRE");
   			gotoxy(40,6);	printf("APELLIDO");
   			gotoxy(58,6);	printf("NIT");
   			gotoxy(68,6);	printf("TELEFONO");
   			gotoxy(78,6);	printf("CORREO");
      		gotoxy(10,8);	printf("\%d",registroE.cod_emp);
   			gotoxy(22,8);	printf("\%s",registroE.Nom_emp);
   			gotoxy(40,8);	printf("\%s",registroE.Ape_emp);
   			gotoxy(58,8);	printf("\%d",registroE.NIT1);
   			gotoxy(68,8);	printf("\%d",registroE.Tel1);
      		gotoxy(78,8);	printf("\%s",registroE.correo1);
      		gotoxy(10,13);	printf("CARGO DEL EMPLEADO.");
      		gotoxy(40,13);	printf("CLIENTE DEL EMPLEADO.");
      		gotoxy(10,15);	printf("\%s",registroE.cargo_emp);
      		gotoxy(40,15);	printf("\%s",registroE.client_emp);
      		gotoxy(10,21);	printf("TIPO DE EQUIPO.");
      		gotoxy(40,21);	printf("MOBILIARIO.");
      		gotoxy(10,23);	printf("\%s",registroE.t_equipo);
      		gotoxy(40,23);	printf("\%s",registroE.mobi);
         	gotoxy(65,21);	printf("PIN ");
      		gotoxy(65,23);	printf("\%d",registroE.contra);

         	strcpy(registroE.Nom_emp,"BORRADO");
         	strcpy(registroE.Ape_emp,"BORRADO");
         	registroE.NIT1=0;
         	registroE.Tel1=0;
         	registroE.cod_emp=0;
         	strcpy(registroE.correo1,"BORRADO");
         	strcpy(registroE.cargo_emp,"BORRADO");
         	strcpy(registroE.client_emp,"BORRADO");
         	strcpy(registroE.t_equipo,"BORRADO");
         	strcpy(registroE.mobi,"BORRADO");
         	registroE.contra=0;

         	do{
         		gotoxy(10,26);printf ("Esta seguro que desea borrarlo? SI[S] o NO[N]: "); op12=toupper(getche()); getch();
				}while(op12!='S' && op12!='N');
				if(op12=='S'){
            	int pos11=ftell(AEmpleado)-sizeof(sRegistroE);
	           	fseek(AEmpleado,pos11,SEEK_SET);
	           	fwrite(&registroE, sizeof(sRegistroE), 1, AEmpleado);
              	gotoxy(10,28); printf ("Registro eliminado con exito!!!");
            }
            fclose(AEmpleado);
             gotoxy(10,30);printf("Presione cualquier tecla para continuar...");
             getch();
             return;
      	}
      	fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   	}
		gotoxy(10,15);printf("No se encuentra ese registro en el archivo!!");
   	fclose(AEmpleado);
   	gotoxy(10,20);printf("Presione cualquier tecla para continuar...");
   	getch();
   	return;
   }
}



//CODIGO COMPLETO DEL MODULO VENTA
FILE *AVenta;																	//apuntador venta
struct sRegistroV{            											//estructura del registro venta
   char nom_prod[30];  														//variables para el producto ingresado
   int cod_prod;                       								//variable para el producto ingresado
   float precio;                       								//Varibale para el precio del producto
   float total1,total2,total3,total4,total5;  						//Variables para las compras
   float total6,total7,total8,total9;            					//Variables para las compras
   float TotalC;     													 //Variable del total
   int cant;                                                   //Variable para la cantidad de producto
   char nomArchivo[20];             									//variable para el nombre del archivo/fichero
   int intentar;    															//variable fuera de la estructura para volver a repetir el ciclo de ingresar producto nuevo
   char repe1,repe2;															//Variables para repetir el ciclo
   int num_fact;																//Varibale para el codigo/numero de factura
   char fecha[20];															 //Variabe para la fecha de la factura
   }registroV;

void MenuVenta(){    //MENU VENTA
	getch();
   system("cls");
   system("mode con: cols=110 lines=38");     //tamaño de la ventana
   marco();
   int i,d;
   //*********Para las columnas*********************************

   for(i=35;i<72;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",176);

   	gotoxy(i,18);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<18;d++){
   	gotoxy(35,d);
   	printf("%c",186);

   	gotoxy(72,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(35,9);
   printf("%c",201);

   gotoxy(35,18);
   printf("%c",200);

   gotoxy(72,9);
   printf("%c",187);

   gotoxy(72,18);
   printf("%c",188);

   system("color 1F");
   marco();
   gotoxy(50,10);	printf("MENU VENTA");
   gotoxy(42,12);	printf("1. Crear Fichero Venta");    //creara el fichero para la venta y para los productos
   gotoxy(42,13);	printf("2. Agregar Productos");  //El producto agregado sera visualizado en tipo de producto
   gotoxy(42,14);	printf("3. Tipo de Producto");
   gotoxy(42,15);	printf("4. Nueva Venta");
   gotoxy(42,16);	printf("5. Ver Ventas");
   gotoxy(42,17);	printf("6. Volver al Menu Principal");
}

void MenuAP(){    //MENU AGREGAR PRODUCTO
	getch();
   system("cls");
   int i,d;

//*********Para las columnas*********************************

   for(i=37;i<70;i++){
   	gotoxy(i,11);
   	printf("%c",205);

      gotoxy(i,13);
   	printf("%c",167);

   	gotoxy(i,16);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=11;d<16;d++){
   	gotoxy(37,d);
   	printf("%c",186);

   	gotoxy(70,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(37,11);
   printf("%c",201);

   gotoxy(37,16);
   printf("%c",200);

   gotoxy(70,11);
   printf("%c",187);

   gotoxy(70,16);
   printf("%c",188);

   marco();
   system("color A1");
   gotoxy(45,12);	printf("MENU AGREGAR PRODUCTO  ");
   gotoxy(39,14);	printf("1. Ingresar Productos ");
   gotoxy(39,15);	printf("2. Volver al Menu Venta ");
}

void MenuIP(){    //MENU INGRESAR PRODUCTO
	getch();
   system("cls");
   int i,d;

//*********Para las columnas*********************************

   for(i=37;i<78;i++){
   	gotoxy(i,7);
   	printf("%c",205);

      gotoxy(i,9);
   	printf("%c",167);

   	gotoxy(i,20);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=7;d<20;d++){
   	gotoxy(37,d);
   	printf("%c",186);

   	gotoxy(78,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(37,7);
   printf("%c",201);

   gotoxy(37,20);
   printf("%c",200);

   gotoxy(78,7);
   printf("%c",187);

   gotoxy(78,20);
   printf("%c",188);
   marco();
   system("color C1");
   gotoxy(48,8);	printf("MENU INGRESAR PRODUCTO");
   gotoxy(39,10);	printf("1. Baño ");
   gotoxy(39,11);	printf("2. Huacal ");
   gotoxy(39,12);	printf("3. Colador ");
   gotoxy(39,13);	printf("4. Canasta ");
   gotoxy(39,14);	printf("5. Vaso Plastico ");
   gotoxy(39,15);	printf("6. Plato plastico	");
   gotoxy(39,16);	printf("7. Mesa ");
   gotoxy(39,17);	printf("8. Silla ");
   gotoxy(39,18);	printf("9. Bolsa Plastica ");
   gotoxy(39,19);	printf("10. Volver al Menu Agregar Producto ");
}

void MenuTP(){    //MENU TIPO DE PRODUCTO
	getch();
   system("cls");
   int i,d;

//*********Para las columnas*********************************

   for(i=37;i<78;i++){
   	gotoxy(i,7);
   	printf("%c",205);

      gotoxy(i,9);
   	printf("%c",167);

   	gotoxy(i,20);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=7;d<20;d++){
   	gotoxy(37,d);
   	printf("%c",186);

   	gotoxy(78,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(37,7);
   printf("%c",201);

   gotoxy(37,20);
   printf("%c",200);

   gotoxy(78,7);
   printf("%c",187);

   gotoxy(78,20);
   printf("%c",188);

   marco();
   system("color 8E");
   gotoxy(48,8);	printf("MENU TIPO DE PRODUCTO");
   gotoxy(39,10);	printf("1. Baños ");
   gotoxy(39,11);	printf("2. Huacales ");
   gotoxy(39,12);	printf("3. Coladores ");
   gotoxy(39,13);	printf("4. Canastas ");
   gotoxy(39,14);	printf("5. Vasos Plasticos ");
   gotoxy(39,15);	printf("6. Platos plasticos	");
   gotoxy(39,16);	printf("7. Mesas ");
   gotoxy(39,17);	printf("8. Sillas ");
   gotoxy(39,18);	printf("9. Bolsa Plastica(por ciento)");
   gotoxy(39,19);	printf("10. Volver al Menu Venta ");
}

//Creacion del ficheros venta
void CrearFicheroVP(FILE *AVenta){
   system("color BF");
	AVenta=fopen("Venta.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
   	AVenta=fopen("Venta.dat", "w"); //Nombre del fichero, modo escritura
      gotoxy(26,22);	printf("El fichero Venta.dat ha sido creado!!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   else{
   	gotoxy(26,25);	printf("El fichero Venta.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
   }
   fclose(AVenta);
}

void CrearFicheroPB(FILE *AVenta){   //Se crea el fichero tipo producto-baño
   system("color F5");
   AVenta=fopen("Baños.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
   	AVenta=fopen("Baños.dat", "w");   //Nombre del fichero, modo escritura
      gotoxy(26,22);	printf("El fichero Baños.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Baños.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPH(FILE *AVenta){   //Se crea el fichero tipo producto-huacal
   system("color F5");
   AVenta=fopen("Huacales.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Huacales.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Huacales.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Huacales.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPCo(FILE *AVenta){   //Se crea el fichero tipo producto-colador
   system("color F5");
   AVenta=fopen("Coladores.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Coladores.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Coladores.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Coladores.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPCa(FILE *AVenta){   //Se crea el fichero tipo producto-canasta
   system("color F5");
   AVenta=fopen("Canastas.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Canastas.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Canastas.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Canastas.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPVP(FILE *AVenta){   //Se crea el fichero tipo producto-vasos plasticos
   system("color F5");
   AVenta=fopen("Vasos Plasticos.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Vasos Plasticos.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Vasos Plasticos.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Vasos Plasticos.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPPP(FILE *AVenta){   //Se crea el fichero tipo producto-platos plasticos
   system("color F5");
   AVenta=fopen("Platos Plasticos.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Platos Plasticos.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Platos Plasticos.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Platos Plasticos.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPM(FILE *AVenta){   //Se crea el fichero tipo producto-mesa
   system("color F5");
   AVenta=fopen("Mesas.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Mesas.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Mesas.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Mesas.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPS(FILE *AVenta){   //Se crea el fichero tipo producto-silla
   system("color F5");
   AVenta=fopen("Sillas.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Sillas.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Sillas.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Sillas.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

void CrearFicheroPBP(FILE *AVenta){   //Se crea el fichero tipo producto-bolsas plasticas
   system("color F5");
   AVenta=fopen("Bolsa Plastica.dat", "r");   //Nombre del fichero, modo lectura
   if(!AVenta){
      AVenta=fopen("Bolsa Plastica.dat", "w");   //Nombre del fichero, modo escritura
   	gotoxy(26,22);	printf("El fichero Bolsa Plastica.dat ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   else{
   	gotoxy(26,25);	printf("El fichero Bolsa Plastica.dat ya existe!!");
      gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      getch();
   }
   fclose(AVenta);
}

//Modulos para Ingresar y Ver Datos de Productos
//Donde en cada modulo de ingresar producto lleva el modulo de crear fichero
//***********NOTA EL PRODUCTO QUE SE VENDE EN LA DISTRIBUIDORA YA HA SIDO AGREGADO*********
//**********NOTA 2 SI QUIERE PUEDE SEGUIR AGREGANDO PRODUCTOS NUEVOS************

//**************CODIGO PARA PRODUCTO-BAÑOS**********************************
void IngresarProductosB(FILE *AVenta){   //Ingresar Productos-Baños
   CrearFicheroPB(aventa);
   system("cls");
   AVenta=fopen("Baños.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep1;     //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
   	marco();
   	marcoad();
      system("color C1");
   	gotoxy(25,10);	printf("Tipo de producto: Baño ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
   	fflush(stdin);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
      do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep1=toupper(getche()); getch;
      }while(rep1!='S' && rep1!='N');
   }while(rep1=='S');
	fclose(AVenta);
}

void encaPB(){          //Encabezado de productos baños
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("BAÑO.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoB(FILE *AVenta){          //Ver productos Baños
	system("cls");
   system("color C0");
	encaPB();
   marco();
   marcoad();
   int numero7=1;
     AVenta = fopen ("Baños.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero7+6);	printf("\%d",numero7);
         gotoxy(29,numero7+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero7+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero7+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero7++;
     }
       fclose(AVenta);
}

//Para el Archivo general de productos
void encaPB1(){          //Encabezado de productos baños
    gotoxy(15,4);	printf("BAÑOS.");
    gotoxy(5,6);	printf("NO.");
    gotoxy(9,6);	printf("CODIGO");
    gotoxy(17,6);	printf("NOMBRE");
    gotoxy(37,6);	printf("PRECIO");
}

void VerProductoB1(FILE *AVenta){          //Ver productos Baños
	encaPB1();
   int numero17=1;
     AVenta = fopen ("Baños.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(5,numero17+6);	printf("\%d",numero17);
         gotoxy(9,numero17+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(17,numero17+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(37,numero17+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero17++;
     }
       fclose(AVenta);
}

//**************CODIGO PARA PRODUCTO-HUACALES**********************************
void IngresarProductosH(FILE *AVenta){   //Ingresar Productos-Huacales
   CrearFicheroPH(aventa);
   system("cls");
   AVenta=fopen("Huacales.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep2;             //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
      system("color 4A");
      marco();
   	marcoad();
   	gotoxy(25,10);	printf("Tipo de producto: Huacal ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
   	fflush(stdin);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
   	do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep2=toupper(getche()); getch;
      }while(rep2!='S' && rep2!='N');
   }while(rep2=='S');
	fclose(AVenta);
}

void encaPH(){          //Encabezado de productos Huacales
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("HUACAL.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoH(FILE *AVenta){          //Ver productos Huacales
	system("cls");
   system("color C7");
	encaPH();
   marco();
   marcoad();
   int numero8=1;
     AVenta = fopen ("Huacales.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero8+6);	printf("\%d",numero8);
         gotoxy(29,numero8+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero8+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero8+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero8++;
     }
       fclose(AVenta);
}

//Para el archivo general de productos
void encaPH1(){          //Encabezado de productos Huacales
    gotoxy(50,4);	printf("HUACAL.");
    gotoxy(46,6);	printf("NO.");
    gotoxy(50,6);	printf("CODIGO");
    gotoxy(59,6);	printf("NOMBRE");
    gotoxy(80,6);	printf("PRECIO");
}

void VerProductoH1(FILE *AVenta){          //Ver productos Huacales
	encaPH1();
   int numero18=8;
   int numero118=1;
     AVenta = fopen ("Huacales.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(46,numero118+6);	printf("\%d",numero18);
         gotoxy(50,numero118+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(59,numero118+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(80,numero118+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero118++;
         numero18++;
     }
       fclose(AVenta);
}

//**************CODIGO PARA PRODUCTO-COLADORES**********************************
void IngresarProductosC(FILE *AVenta){   //Ingresar Productos-Coladores
   CrearFicheroPCo(aventa);
   AVenta=fopen("Coladores.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep3;                  //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
   	system("color 1E");
   	marco();
   	marcoad();
   	gotoxy(25,10);	printf("Tipo de producto: Colador ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
   	do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep3=toupper(getche()); getch;
      }while(rep3!='S' && rep3!='N');
   }while(rep3=='S');
	fclose(AVenta);
}

void encaPC(){          //Encabezado de productos Coladores
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("COLADOR.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductosC(FILE *AVenta){          //Ver productos Coladores
	system("cls");
   system("color 68");
   marco();
   marcoad();
	encaPC();
   int numero9=1;
     AVenta = fopen ("Coladores.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero9+6);	printf("\%d",numero9);
         gotoxy(29,numero9+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero9+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero9+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero9++;
     }
       fclose(AVenta);
}


//Para el archivo genereral de productos
void encaPC1(){          //Encabezado de productos Coladores
    gotoxy(100,4);	printf("COLADOR.");
    gotoxy(90,6);	printf("NO.");
    gotoxy(95,6);	printf("CODIGO");
    gotoxy(103,6);	printf("NOMBRE");
    gotoxy(133,6);	printf("PRECIO");
}

void VerProductosC1(FILE *AVenta){          //Ver productos Coladores
	encaPC1();
   int numero119=1, numero109=14;
     AVenta = fopen ("Coladores.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(90,numero119+6);	printf("\%d",numero109);
         gotoxy(95,numero119+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(103,numero119+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(133,numero119+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero119++;
         numero109++;
     }
       fclose(AVenta);

}

//**************CODIGO PARA PRODUCTO-VASOS PLASTICOS**********************************
void IngresarProductosVP(FILE *AVenta){   //Ingresar Productos-Vasos Plasticos
   CrearFicheroPVP(aventa);
   system("cls");
   AVenta=fopen("Vasos Plasticos.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep4;       //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
   	system("color F8");
   	marco();
   	marcoad();
   	gotoxy(25,10);	printf("Tipo de producto: Vaso Plastico ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
      do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep4=toupper(getche()); getch;
      }while(rep4!='S' && rep4!='N');
   }while(rep4=='S');
	fclose(AVenta);
}

void encaPV(){          //Encabezado de productos Vasos Plasticos
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("VASO PLASTICO.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductosVP(FILE *AVenta){          //Ver productos vasos plasticos
	system("cls");
   system("color 1E");
   marco();
   marcoad();
	encaPV();
   int numero10=1;
     AVenta = fopen ("Vasos Plasticos.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero10+6);	printf("\%d",numero10);
         gotoxy(29,numero10+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero10+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero10+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero10++;
     }
       fclose(AVenta);
}

//Para el archivo general de productos
void encaPV1(){          //Encabezado de productos Vasos Plasticos
    gotoxy(15,15);	printf("VASO PLASTICO.");
    gotoxy(5,17);	printf("NO.");
    gotoxy(9,17);	printf("CODIGO");
    gotoxy(17,17);	printf("NOMBRE");
    gotoxy(37,17);	printf("PRECIO");
}

void VerProductosVP1(FILE *AVenta){          //Ver productos vasos plasticos
	encaPV1();
   int numero100=1,numero101=19;
     AVenta = fopen ("Vasos Plasticos.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(5,numero100+17);	printf("\%d",numero101);
         gotoxy(9,numero100+17);	printf("\%d",registroV.cod_prod);
     		gotoxy(17,numero100+17);	printf("\%s",registroV.nom_prod);
     		gotoxy(37,numero100+17);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero100++;
         numero101++;
     }
       fclose(AVenta);
}



//**************CODIGO PARA PRODUCTO-Platos Plasticos**********************************
void IngresarProductosPP(FILE *AVenta){   //Ingresar Productos-Platos Plasticos
   CrearFicheroPPP(aventa);
   system("cls");
   AVenta=fopen("Platos Plasticos.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep5;           //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
      marco();
   	marcoad();
      system("color D1");
   	gotoxy(25,10);	printf("Tipo de producto: Plato Plastico ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
		do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep5=toupper(getche()); getch;
      }while(rep5!='S' && rep5!='N');
   }while(rep5=='S');
	fclose(AVenta);
}


void encaPP(){          //Encabezado de productos platos plasticos
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("PLATO PLASTICO.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoPP(FILE *AVenta){          //Ver productos platos plasticos
	system("cls");
   marco();
   marcoad();
   system("color B2");
	encaPP();
   int numero11=1;
     AVenta = fopen ("Platos Plasticos.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero11+6);	printf("\%d",numero11);
         gotoxy(29,numero11+6);  printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero11+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero11+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero11++;
     }
       fclose(AVenta);
}


//Para el archivo general de productos

void encaPP1(){          //Encabezado de productos platos plasticos
    gotoxy(50,15);	printf("PLATO PLASTICO.");
    gotoxy(46,17);	printf("NO.");
    gotoxy(50,17);	printf("CODIGO");
    gotoxy(59,17);	printf("NOMBRE");
    gotoxy(80,17);	printf("PRECIO");
}

void VerProductoPP1(FILE *AVenta){          //Ver productos platos plasticos
	encaPP1();
   int numero113=1,numero114=23;
     AVenta = fopen ("Platos Plasticos.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(46,numero113+17);	printf("\%d",numero114);
         gotoxy(50,numero113+17);  printf("\%d",registroV.cod_prod);
     		gotoxy(59,numero113+17);	printf("\%s",registroV.nom_prod);
     		gotoxy(81,numero113+17);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
         numero114++;
     		numero113++;
     }
       fclose(AVenta);
}




//**************CODIGO PARA PRODUCTO-MESAS**********************************
void IngresarProductosM(FILE *AVenta){   //Ingresar Productos-Mesas
   CrearFicheroPM(aventa);
   system("cls");
   AVenta=fopen("Mesas.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep6;      //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
      marco();
   	marcoad();
      system("color C7");
   	gotoxy(25,10);	printf("Tipo de producto: Mesa ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
      do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep6=toupper(getche()); getch;
      }while(rep6!='S' && rep6!='N');
   }while(rep6=='S');
	fclose(AVenta);
}

void encaPM(){          //Encabezado de productos mesas
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("MESA.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoM(FILE *AVenta){          //Ver productos mesas
	system("cls");
   marco();
   marcoad();
	system("color E2");
	encaPM();
   int numero12=1;
     AVenta = fopen ("Mesas.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero12+6);	printf("\%d",numero12);
         gotoxy(29,numero12+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero12+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero12+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero12++;
     }
       fclose(AVenta);
}
//Para el archivo general de productos

void encaPM1(){          //Encabezado de productos mesas
    gotoxy(100,15);	printf("MESA.");
    gotoxy(90,17);	printf("NO.");
    gotoxy(95,17);	printf("CODIGO");
    gotoxy(103,17);	printf("NOMBRE");
    gotoxy(133,17);	printf("PRECIO");
}

void VerProductoM1(FILE *AVenta){          //Ver productos mesas
	encaPM1();
   int numero122=1,numero123=28;
     AVenta = fopen ("Mesas.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(90,numero122+17);	printf("\%d",numero123);
         gotoxy(95,numero122+17);	printf("\%d",registroV.cod_prod);
     		gotoxy(103,numero122+17);	printf("\%s",registroV.nom_prod);
     		gotoxy(133,numero122+17);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
         numero123++;
     		numero122++;
     }
       fclose(AVenta);
}



//**************CODIGO PARA PRODUCTO-SILLAS**********************************
void IngresarProductosS(FILE *AVenta){   //Ingresar Productos-Sillas
   CrearFicheroPS(aventa);
   system("cls");
   AVenta=fopen("Sillas.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep7;         //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
      marco();
   	marcoad();
      system("color A4");
   	gotoxy(25,10);	printf("Tipo de producto: Silla ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
   	do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep7=toupper(getche()); getch;
      }while(rep7!='S' && rep7!='N');
   }while(rep7=='S');
	fclose(AVenta);
}

void encaPS(){          //Encabezado de productos sillas
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("SILLA.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoS(FILE *AVenta){          //Ver productos sillas
	system("cls");
   marco();
   marcoad();
   system("color A0");
	encaPS();
   int numero13=1;
     AVenta = fopen ("Sillas.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero13+6);	printf("\%d",numero13);
         gotoxy(29,numero13+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero13+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero13+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero13++;
     }
       fclose(AVenta);
}

//Para el archivo general de productos

void encaPS1(){          //Encabezado de productos sillas
    gotoxy(15,23);	printf("SILLA.");
    gotoxy(5,25);	   printf("NO.");
    gotoxy(9,25);	   printf("CODIGO");
    gotoxy(17,25);	printf("NOMBRE");
    gotoxy(40,25);	printf("PRECIO");
}

void VerProductoS1(FILE *AVenta){          //Ver productos sillas
	encaPS1();
   int numero133=1,numero134=35;
     AVenta = fopen ("Sillas.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(5,numero133+25);	printf("\%d",numero134);
         gotoxy(9,numero133+25);	printf("\%d",registroV.cod_prod);
     		gotoxy(17,numero133+25);	printf("\%s",registroV.nom_prod);
     		gotoxy(40,numero133+25);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
         numero134++;
     		numero133++;
     }
       fclose(AVenta);
}



//**************CODIGO PARA PRODUCTO-CANASTAS**********************************
void IngresarProductosC1(FILE *AVenta){   //Ingresar Productos-Canastas
   CrearFicheroPCa(aventa);
   system("cls");
   AVenta=fopen("Canastas.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep8;     //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
   	marco();
   	marcoad();
      system("color C1");
   	gotoxy(25,10);	printf("Tipo de producto: Canasta ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
   	do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep8=toupper(getche()); getch;
      }while(rep8!='S' && rep8!='N');
   }while(rep8=='S');
	fclose(AVenta);
}

void encaPC11(){          //Encabezado de productos canastas
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("CANASTA.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoC1(FILE *AVenta){          //Ver productos Canastas
	system("cls");
   marco();
   marcoad();
   system("color A1");
	encaPC11();
   int numero14=1;
     AVenta = fopen ("Canastas.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero14+6);	printf("\%d",numero14);
         gotoxy(29,numero14+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero14+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero14+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero14++;
     }
       fclose(AVenta);
}

//Para el archivo general de productos
void encaPC111(){          //Encabezado de productos canastas
    gotoxy(55,23);	printf("CANASTA.");
    gotoxy(49,25);	printf("NO.");
    gotoxy(53,25);	printf("CODIGO");
    gotoxy(61,25);	printf("NOMBRE");
    gotoxy(83,25);	printf("PRECIO");
}

void VerProductoC111(FILE *AVenta){          //Ver productos Canastas
	encaPC111();
   int numero144=1,numero145=35;
     AVenta = fopen ("Canastas.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(49,numero144+25);	printf("\%d",numero145);
         gotoxy(53,numero144+25);	printf("\%d",registroV.cod_prod);
     		gotoxy(61,numero144+25);	printf("\%s",registroV.nom_prod);
     		gotoxy(83,numero144+25);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
         numero145++;
     		numero144++;
     }
       fclose(AVenta);
}



//**************CODIGO PARA PRODUCTO-BOLSAS PLASTICAS**********************************
void IngresarProductosBP(FILE *AVenta){   //Ingresar Productos-Bolsas plasticas
   CrearFicheroPBP(aventa);
   system("cls");
   AVenta=fopen("Bolsa Plastica.dat","a+");
   if(AVenta==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char rep9;     //Variable para repetir el ciclo de ingresar productos
   do{
   	system("cls");
      marco();
   	marcoad();
      system("color A0");
   	gotoxy(25,10);	printf("Tipo de producto: Bolsa Plastica ");
		gotoxy(15,12);	printf("Codigo: ");
  		scanf("%d",&registroV.cod_prod);
		gotoxy(15,14);	printf("Nombre: ");
   	fflush(stdin);
   	gets(registroV.nom_prod);
		gotoxy(15,16);	printf("Precio: Q");
  		fflush(stdin);
  		scanf("%f",&registroV.precio);
  		fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
		do{
      	gotoxy(15,18); printf("Desea seguir registrando productos? SI[S] o NO[N]: ");  rep9=toupper(getche()); getch;
      }while(rep9!='S' && rep9!='N');
   }while(rep9=='S');
	fclose(AVenta);
}

void encaPBP(){          //Encabezado de productos bolsas plasticas
	 gotoxy(50,3);	printf("TIPO DE PRODUCTO.");
    gotoxy(55,4);	printf("BOLSA PLASTICA.");
    gotoxy(20,6);	printf("NO.");
    gotoxy(28,6);	printf("CODIGO");
    gotoxy(45,6);	printf("NOMBRE");
    gotoxy(79,6);	printf("PRECIO");
}

void VerProductoBP(FILE *AVenta){          //Ver productos Bolsas plasticas
	system("cls");
   marco();
   marcoad();
   system("color F6");
	encaPBP();
   int numero15=1;
     AVenta = fopen ("Bolsa Plastica.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(20,numero15+6);	printf("\%d",numero15);
         gotoxy(29,numero15+6);	printf("\%d",registroV.cod_prod);
     		gotoxy(45,numero15+6);	printf("\%s",registroV.nom_prod);
     		gotoxy(79,numero15+6);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero15++;
     }
       fclose(AVenta);
}

//Para el archivo general de productos
void encaPBP1(){          //Encabezado de productos bolsas plasticas;
    gotoxy(100,23);	printf("BOLSA PLASTICA.");
    gotoxy(90,25);	printf("NO.");
    gotoxy(95,25);	printf("CODIGO");
    gotoxy(103,25);	printf("NOMBRE");
    gotoxy(133,25);	printf("PRECIO");
}

void VerProductoBP1(FILE *AVenta){          //Ver productos Bolsas plasticas
	encaPBP1();
   int numero115=1;
   int numero1115=40;
     AVenta = fopen ("Bolsa Plastica.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(90,numero115+25);	printf("\%d",numero1115);
         gotoxy(95,numero115+25);	printf("\%d",registroV.cod_prod);
     		gotoxy(103,numero115+25);	printf("\%s",registroV.nom_prod);
     		gotoxy(133,numero115+25);	printf("Q \%2.f",registroV.precio);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numero115++;
         numero1115++;
     }
       fclose(AVenta);
}

//Modulo para realizar Nueva Venta
void NuevaVenta(FILE *AVenta){
	system("cls");
   system("color F5");
   marco();
   marcoad();
   int cod_empaux;    												//Variable utilizada para realizar la busqueda del empleado
   int cod_prodaux;
   AEmpleado=fopen("Empleado.dat","r");
   if(AEmpleado==NULL){
   	system("color F4");
   	gotoxy(26,25);	printf("El fichero Empleado.dat no existe!");
      gotoxy(26,26);	printf("Por favor creelo.");
      gotoxy(26,28);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   gotoxy(26,12); printf("Ingrese el ID del Empleado que realizara la venta: ");
   scanf("%d",&cod_empaux);
   fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   while(!feof(AEmpleado)){
	   if(registroE.cod_emp == cod_empaux){
      	AVenta=fopen("Venta.dat", "a+");                //Nombre del fichero, modo agregar
   		if(AVenta==NULL){
   			system("color F4");
   			gotoxy(26,22);	printf("El fichero Venta.dat no existe!");
      		gotoxy(26,23);	printf("Por favor creelo.");
      		gotoxy(26,28);	printf("Presione cualquier tecla para continuar...");
      		return;
   		}
	   	gotoxy(26,15); printf("Escriba el numero de factura: ");
	      scanf("%d",&registroV.num_fact);
	   	gotoxy(26,17); printf("Escriba la fecha: ");
	   	fflush(stdin);
	   	gets(registroV.fecha);
	  		fflush(stdin);
         fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
	      system("cls");
         system("mode con: cols=155 lines=45");     //tamaño de la ventana
         gotoxy(26,1); printf("Vendedor: \%s",registroE.Nom_emp);
		   gotoxy(26,2); printf("Cliente: \%s",registroE.client_emp);
         AVenta=fopen("Baños.dat","r+b");
         VerProductoB1(AVenta);
         AVenta=fopen("Huacales.dat","r+b");
   		VerProductoH1(AVenta);
        	AVenta=fopen("Coladores.dat","r+b");
         VerProductosC1(AVenta);
         AVenta=fopen("Vasos Plasticos.dat","r+b");
         VerProductosVP1(AVenta);
         AVenta=fopen("Platos Plasticos.dat","r+b");
         VerProductoPP1(AVenta);
         AVenta=fopen("Mesas.dat","r+b");
         VerProductoM1(AVenta);
         AVenta=fopen("Sillas.dat","r+b");
         VerProductoS1(AVenta);
         AVenta=fopen("Canastas.dat","r+b");
         VerProductoC111(AVenta);
         AVenta=fopen("Bolsa Plastica.dat","r+b");
         VerProductoBP1(AVenta);
			gotoxy(37,33);	printf("Ingrese el codigo del producto que desea comprar: ");
			scanf("%d",&cod_prodaux);
         fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
         if(registroV.cod_prod == cod_prodaux){
         	gotoxy(37,34);	printf("Cantidad a comprar: ");
         	scanf("%d",&registroV.cant);
           	registroV.TotalC=registroV.cant * registroV.precio;
            fwrite(&registroV, sizeof(struct sRegistroV), 1, AVenta);
           	gotoxy(25,35); printf("Su total a pagar es: \%2.f", registroV.TotalC);
           	fclose(AVenta);
         }
         if(registroV.cod_prod != cod_prodaux){
                gotoxy(26,33); printf("El producto no esta registrado!!");
                gotoxy(26,34);	printf("Preciona cualquier tecla para continuar...");
                return;
         }
			fclose(AEmpleado);
		}
		fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
	}
   if(registroE.cod_emp != cod_empaux){
   	gotoxy(26,14); printf("El empleado no esta registrado!!");
      do{
      	gotoxy(26,16); printf("Desea intentarlo de nuevo? SI[S] o NO[N]: "); repet=toupper(getche()); getch;
      }while(repet!='S' && repet!='N');
      if(repet=='S'){
      	gotoxy(26,20);	printf("Preciona cualquier tecla para continuar...");
      	getch();
      	NuevaVenta(aventa);
      }
      else{
      	gotoxy(26,20);	printf("Preciona cualquier tecla para continuar...");
      	return;
      }
   }
}

void NumFacturas(FILE *AVenta){   //Modulo que enumera el codigo de las facturas
	system("cls");
   system("color ");     //pendiente
   int numeroF=1;
     AVenta = fopen ("Venta.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
     fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     while(!feof(AVenta)){
     		gotoxy(40,4); printf("FACTURAS");
     		gotoxy(20,numeroF+6);	printf("\%d",numeroF);
         gotoxy(23,numeroF+6);	printf("\%d",registroV.num_fact);
     		fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
     		numeroF++;
     }
       fclose(AVenta);
}

void VerVenta(FILE *AVenta){
	system("cls");
   system("color ");     //pendiente
     AVenta = fopen ("Venta.dat", "r");
     if(AVenta==NULL) {
     		gotoxy(26,22);	printf("Fichero no existe!");
         gotoxy(26,25);	printf("Por favor creelo!");
     		return;
     }
   int CodFacturas;
   int repetir;    //Varibale para repetir el ciclo de busqueda de factura
   NumFacturas(aventa);
   gotoxy(20,20); printf("Ingrese el codigo de factura que desea ver: ");
   scanf("%d",&CodFacturas);
   fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
	while(!feof(AVenta)){
   	if(registroV.num_fact == CodFacturas){
      	system("cls");
         gotoxy(45,6);	printf("DISTRIBUIDORA:");
         gotoxy(41,8);	printf("PLASTICOS EL TRIUNFADOR.");
         gotoxy(41,10);	printf("CHIQUIMULILLA, SANTA ROSA");
         gotoxy(12,14);	printf("FACTURA NO. \%d",registroV.num_fact);
         gotoxy(33,14);	printf("FECHA: \%s",registroV.fecha);
         gotoxy(12,16);	printf("Cliente: \%s",registroE.client_emp);
         gotoxy(12,20);	printf("VENDEDOR: \%s",registroE.Nom_emp);
         gotoxy(12,22);	printf("CANT.");
         gotoxy(28,22);	printf("DESCRIPCION.");
         gotoxy(69,22);	printf("TOTAL.");
         gotoxy(12,24);	printf("\%d",registroV.cant);
         gotoxy(28,24);	printf("\%d",registroV.cod_prod);
         gotoxy(32,24);	printf("-- \%s",registroV.nom_prod);
         gotoxy(69,24);	printf("\%d",registroV.TotalC);
         gotoxy(26,29);	printf("Presione cualquier tecla para continuar...");
      	getch();
         fclose(AVenta);
		}
     	fread(&registroV, sizeof(struct sRegistroV), 1, AVenta);
	}
   if(registroV.num_fact != CodFacturas){
   	gotoxy(26,23); printf("No se encontro ningun registro con el codigo ingresado!");
   	do{
      	gotoxy(26,25); printf("Desea intentarlo de nuevo? SI[S] o NO[N]: "); repetir=toupper(getche()); getch;
      }while(repetir!='S' && repetir!='N');
      if(repetir=='S'){
      	gotoxy(26,27);	printf("Preciona cualquier tecla para continuar...");
      	getch();
         VerVenta(AVenta);
      }
      else{
      	gotoxy(26,29);	printf("Preciona cualquier tecla para continuar...");
      	return;
      }
   }
}


//*****************CODIGO COMPLETO DEL MODULO PLANILLA*******************
FILE *APlanilla;           // apuntador planilla
struct sRegistroP{        //estructura del registro planilla
	int salario;
   int IDAUX;             //Variable para realizar la busqueda del empleado en planilla
   char a[20],b[20],c[20],d[20],e[20],f[20],g[20],h[20],i[20],j[20];     //Variables para agregar mas informacion a las prestaciones por ley
   char AsistenciaSo[5],Bono[5],SegVid[5],Aguinaldo[5],IGSS[5];    //Variables para las prestaciones
   int Hin,Hout,Hinf,Houtf;      //Varibles para la jordana
}registroP;

void MenuPlanillaA(){       //Menu planilla para el administrador
	int i,d;
   //*********Para las columnas*********************************

   for(i=40;i<78;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",177);

   	gotoxy(i,19);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<19;d++){
   	gotoxy(40,d);
   	printf("%c",186);

   	gotoxy(78,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(40,9);
   printf("%c",201);

   gotoxy(40,19);
   printf("%c",200);

   gotoxy(78,9);
   printf("%c",187);

   gotoxy(78,19);
   printf("%c",188);

   gotoxy(52,10);	printf("MENU PLANILLA");
   gotoxy(42,12);	printf("1. Crear Fichero");
   gotoxy(42,13);	printf("2. Jornada de Trabajo");
   gotoxy(42,14);	printf("3. Salario Empleado");
   gotoxy(42,15);	printf("4. Tipo de Prestacion");
   gotoxy(42,16);	printf("5. Prestacion por Ley");
   gotoxy(42,17);	printf("6. Volver al Menu Principal");
}

void MenuPlanillaT(){       //Menu planilla para ver datos
	int i,d;
   //*********Para las columnas*********************************

   for(i=40;i<78;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",177);

   	gotoxy(i,19);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<19;d++){
   	gotoxy(40,d);
   	printf("%c",186);

   	gotoxy(78,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(40,9);
   printf("%c",201);

   gotoxy(40,19);
   printf("%c",200);

   gotoxy(78,9);
   printf("%c",187);

   gotoxy(78,19);
   printf("%c",188);
   gotoxy(52,10);	printf("MENU PLANILLA");
   gotoxy(42,12);	printf("1. Jornada de Trabajo");
   gotoxy(42,13);	printf("2. Salario Empleado");
   gotoxy(42,14);	printf("3. Tipo de Prestacion");
   gotoxy(42,15);	printf("4. Prestacion por Ley");
   gotoxy(42,16);	printf("5. Volver al Menu Principal");
}

void CrearFicheroPla(FILE *APlanilla){     //Creacion del fichero planilla
   system("color 9F");
	APlanilla=fopen("Planilla.dat", "r");   //Nombre del fichero, modo lectura
   if(!APlanilla){
   	APlanilla=fopen("Planilla.dat", "w"); //Nombre del fichero, modo escritura
      gotoxy(26,22);	printf("El fichero ha sido creado!");
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   else{
   	gotoxy(26,22);	printf("El fichero ya existe!"); printf("%c",7);
      gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
   }
   fclose(APlanilla);
}

void JornadaTrabajo(FILE *APlanilla){   //Ingresar Datos Planilla-jornada de trabajo
   system("cls");
   int opcJ;
   int existeP=0, existeP1=0, posH, posHf;
   int Nitef, Nite;           //Variable que servira para comparar el nit del empleado con el nit del empleado que se desea dar horario
   AEmpleado=fopen("Empleado.dat","r+b");
   if(AEmpleado==NULL){
   	gotoxy(26,22);	printf("El archivo Empleado.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   APlanilla=fopen("Planilla.dat","a+");
   if(APlanilla==NULL){
   	gotoxy(26,22);	printf("El archivo Planilla.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   gotoxy(22,6);	printf("JORNADA DE TRABAJO.");
   gotoxy(13,8);  printf("1. Jornada de trabajo dias comerciales");
   gotoxy(13,9);  printf("2. Jornada de trabajo dias festivos");
   gotoxy(13,10); printf("3. Regresar al menu Plantilla");
   scanf ("%d", &opcJ);
	switch (opcJ){
   	case 1:
      	system("cls");
		  	gotoxy(11,6); printf("Jornada dias comerciales");
         gotoxy(11,8); printf("Ingrese el NIT del empleado: ");
         scanf("%s", &Nite);
         fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
         while(!feof(AEmpleado)){
         	if (registroE.NIT1 == Nite){
         		gotoxy(11,10);	printf("Horario de entrada: ");
					scanf("%d",&registroP.Hin);
					gotoxy(11,12);	printf("Horario de salida: ");
		  			scanf("%d",&registroP.Hout);
         		posH=ftell(APlanilla)-sizeof(sRegistroP);
            	fseek(APlanilla,posH,SEEK_SET);
		  			fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         		existeP=1;
         	}

         	if (existeP==0){
        			gotoxy(14,14); printf("No existe un Empleado con dicho NIT");
        			fclose(APlanilla);
         	}
         	fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
         }
         break;
		case 2:
      	system("cls");
			gotoxy(11,6); printf("Jornada dias festivos");
         gotoxy(11,8); printf("Ingrese el NIT del empleado: ");
         scanf("%s", &Nitef);
         fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
         while(!feof(AEmpleado)){
         	if (registroE.NIT1 == Nitef){
         		gotoxy(11,10);	printf("Horario de entrada: ");
					scanf("%d",&registroP.Hinf);
					gotoxy(11,12);	printf("Horario de salida: ");
		  			scanf("%d",&registroP.Houtf);
         		posHf=ftell(APlanilla)-sizeof(sRegistroP);
            	fseek(APlanilla,posHf,SEEK_SET);
		  			fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         		existeP1=1;
         	}
         	if (existeP1==0){
        			gotoxy(14,14); printf("No existe un Empleado con dicho NIT");
               fclose(AEmpleado);
        			fclose(APlanilla);
         	}
            fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
         }
         break;
		case 3:
		  	gotoxy(11,12);	printf("Regresara al menu de Plantilla");
			getch;
			break;
		default:
			gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
	}
}

void Prestaciones(FILE *APlanilla){           //Modulo para agregar prestacioens
	system("cls");
   marco();
   marcoad();
   int IDaux110;                             //Variable para realizar la busqueda
   char seguir;                             //Variable para repetir el ciclo
	AEmpleado=fopen("Empleado.dat","r+b");
    if (AEmpleado==NULL){
    		system("color 5C");
    		gotoxy(26,22);	printf("Fichero empleado.dat no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
    }
    APlanilla=fopen("Planilla.dat","a+");
    if (APlanilla==NULL){
    		system("color 5C");
    		gotoxy(26,22);	printf("Fichero Planilla.dat no existe!");
         gotoxy(26,23);	printf("Por favor creelo!");printf("%c",7);
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
    }
    gotoxy(15,4);printf("Ingrese el ID del empleado a registrar prestacion: ");
    scanf("%i", &IDaux110);
    sRegistroE registroE;
    fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
    while(!feof(AEmpleado)){
    	if (IDaux110 == registroE.cod_emp){
         do{
         	system("cls");
            	gotoxy(40,8);printf("PRESTACIONES");
            	gotoxy(15,11);printf("El empleado es: %s ", registroE.Nom_emp);
               gotoxy(15,13);printf("Asistencia social, Si o No: ");
               fflush(stdin);
               gets(registroP.AsistenciaSo);
               fflush(stdin);
      			gotoxy(15,15);printf("Seguro de vida, Si o No: ");
               fflush(stdin);
               gets(registroP.SegVid);
               fflush(stdin);
      			gotoxy(15,17);printf("IGGS, Si o No: ");
               fflush(stdin);
               gets(registroP.IGSS);
               fflush(stdin);
      			gotoxy(15,19);printf("Bono 14, Si o No: ");
               fflush(stdin);
               gets(registroP.Bono);
               fflush(stdin);
      			gotoxy(15,21);printf("Aguinaldo, Si o No: ");
               fflush(stdin);
            	gets(registroP.Aguinaldo);
               fflush(stdin);
               fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
	           	gotoxy(15,25);printf("Se agregaron las prestaciones al empleado");
               getch();
            fclose(APlanilla);
            do{
            	gotoxy(15,29); printf("Desea seguir agregando? SI[S] o NO[N]: "); seguir=toupper(getche());
            }while(seguir!='S' && seguir!='N');
           if(seguir=='S'){
             Prestaciones(aplanilla);
           }
          }while(seguir=='S');
          return;
        }
        fclose(AEmpleado);
        fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
    }
    if (IDaux110 != registroE.cod_emp){
        gotoxy(15,14); printf("No existe un Empleado con dicho ID!");
    }
    gotoxy(15,31); printf("Presione una tecla para continuar");
    getch();
}



void EncaPrestaciones(){           //Encabezado de datos de prestacopmes
	 system("color 5C");
    marcoGrande();
	 gotoxy(50,3);	printf("DATOS PRESTACIONES");
    gotoxy(7,6);	printf("NO.");
    gotoxy(12,6);	printf("ID");
    gotoxy(22,6);	printf("NOMBRE");
    gotoxy(35,6);	printf("ASISTENCIA SO");
    gotoxy(51,6);	printf("SEGURO DE VI");
    gotoxy(65,6);	printf("IGGS");
    gotoxy(75,6);	printf("BONO 14");
    gotoxy(86,6);	printf("AGUINALDO");
 }

void VerPrestaciones(FILE *APlanilla){           //Ver los Datos en planilla de las prestaciones
   system("cls");
   system("color 5C");
	EncaPrestaciones();
//****************Linea superior de datos
   for(int i=6;i<107;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
   int numero111=1;
     APlanilla = fopen ("Planilla.dat", "r");
     if(APlanilla==NULL) {
     		gotoxy(26,22);	printf("Fichero Planilla.dat no existe!");printf("%c",7);
         gotoxy(26,23);	printf("Por favor creelo!");
     		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
     		return;
     }
     marcoGrande();
     fread(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
     while(!feof(APlanilla)){
     		gotoxy(7,numero111+6);	printf("\%d",numero111);
         gotoxy(12,numero111+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(22,numero111+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(35,numero111+6);	printf("\%s",registroP.AsistenciaSo);
     		gotoxy(51,numero111+6);	printf("\%s",registroP.SegVid);
     		gotoxy(65,numero111+6);	printf("\%s",registroP.IGSS);
         gotoxy(75,numero111+6);	printf("\%s",registroP.Bono);
         gotoxy(86,numero111+6);	printf("\%s",registroP.Aguinaldo);

     		fread(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
     		numero111++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(APlanilla);
}


void MenuPrestacionesLey(){     //Menu prestaciones de ley
    system("cls");
	 marco();
    marcoad();
    gotoxy(15,3);    printf("Segun el articulo 109 de la Constitucion Politica de Guatemala, los trabajadores");
    gotoxy(15,4);    printf("que laboren por planilla seran equiparados en salarios, prestaciones y");
    gotoxy(15,5);    printf("derechos a los otros trabajadores del Estado. Asi que estos son algunos de los");
    gotoxy(15,6);    printf("beneficios que disfruta un trabajador por planilla en Guatemala.");
    int i,d;
   //*********Para las columnas*********************************

   for(i=38;i<78;i++){
   	gotoxy(i,10);
   	printf("%c",205);

      gotoxy(i,12);
   	printf("%c",177);

   	gotoxy(i,24);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=10;d<24;d++){
   	gotoxy(38,d);
   	printf("%c",186);

   	gotoxy(78,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(38,10);
   printf("%c",201);

   gotoxy(38,24);
   printf("%c",200);

   gotoxy(78,10);
   printf("%c",187);

   gotoxy(78,24);
   printf("%c",188);

    gotoxy(48,11);	printf("Menu Prestaciones de Ley");
    gotoxy(40,13);	printf("1.Indemnizacion");
    gotoxy(40,14);	printf("2.Vacaciones");
    gotoxy(40,15);	printf("3.Aguinaldo");
    gotoxy(40,16);	printf("4.Bono 14");
    gotoxy(40,17);	printf("5.Bonificacion incentivo");
    gotoxy(40,18);	printf("6.IGSS");
    gotoxy(40,19);	printf("7.IRTRA");
    gotoxy(40,20);	printf("8.Jubilacion");
    gotoxy(40,21);	printf("9.Días feriados");
    gotoxy(40,22);	printf("10.Septimo día");
    gotoxy(40,23);	printf("11.Regresar al menu planilla");
}

void PrestacionesLey(FILE *APlanilla){        //modulo para agregar prestaciones por ley
   system("cls");
   APlanilla=fopen("Planilla.dat","a+");
   if(APlanilla==NULL){
   	gotoxy(26,22);	printf("El archivo Planilla.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char sigue,sigue2;
   int opcion78;
   do{
 	 MenuPrestacionesLey();
    gotoxy(40,25); printf("Elija la opcion: ");
    scanf("%d", &opcion78);

    if(opcion78==1){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("INDEMNIZACION");
    		gotoxy(15,13);	printf("Se entrega al trabajador que haya sido despedido sin causa justificada. El");
    		gotoxy(15,14);	printf("calculo de dicho pago es equivalente a un mes de salario por cada año de");
    		gotoxy(15,15);	printf("servicios continuos prestados. Ademas, este no excedera de diez meses.");
         do{
         	gotoxy(15,17); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,19); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.a);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,23); printf("Presione una tecla para continuar");
    		getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==2){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("VACACIONES");
    		gotoxy(15,13);	printf("Según el articulo 130 del Codigo de Trabajo, todo trabajador tiene derecho");
    		gotoxy(15,14);	printf("a un período de vacaciones remuneradas después de cada año de");
    		gotoxy(15,15);	printf("trabajo continuo. La duracion mínima del descanso es de 15 días habiles.");
    		gotoxy(15,16);	printf("salario, segun la constitucion.");
         do{
         	gotoxy(15,18); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,20); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.b);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,23); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==3){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("AGUINALDO");
    		gotoxy(15,13);	printf("Este es un pago anual que tiene todo trabajador desde el primer día de su");
    		gotoxy(15,14);	printf("labor. De hecho, está establecido en el decreto 76-78 del Congreso de la");
    		gotoxy(15,15);	printf("Republica de Guatemala —la ley Reguladora del Aguinaldo— que todo");
    		gotoxy(15,16);	printf("equivale al 100% del salario ordinario mensual por un año de servicios");
    		gotoxy(15,17);	printf("continuos o parte del correspondiente si no se ha cumplido el año");
    		gotoxy(15,19);	printf("Ademas, este se paga en un 50% en la primera quincena de diciembre y el");
    		gotoxy(15,20);	printf("resto en la segunda quincena de enero.");
         do{
         	gotoxy(15,22); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,24); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.c);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,26); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==4){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("BONO 14");
    		gotoxy(15,13);	printf("La Bonificacion Anual para Trabajadores del sector Privado y Publico");
    		gotoxy(15,14);	printf("posee su base legal en el Decreto 42-92. Esta también equivale a un 100%");
    		gotoxy(15,15);	printf("del salario ordinario al mes. Al igual que el aguinaldo, se paga completo si");
    		gotoxy(15,16);	printf("el trabajador ha laborado por un año ininterrumpido. Si la relación laboral");
    		gotoxy(15,17);	printf("ha sido menor a un año, la prestación es proporcional al tiempo laborado.");
    		gotoxy(15,19);	printf("Esta se paga durante la primera quincena del mes de julio de cada año.");
         do{
         	gotoxy(15,21); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,23); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.d);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==5){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("BONIFICACION INCENTIVO");
    		gotoxy(15,13);	printf("Esta bonificacion es medida en cada empresa privada por productividad y");
    		gotoxy(15,14);	printf("eficiencia en mutuo acuerdo con los trabajadores y la empresa. Tiene sus");
    		gotoxy(15,15);	printf("bases legales en el decreto 78-89, Ley de Bonificación Incentivo para los");
    		gotoxy(15,16);	printf("Trabajadores del Sector Privado.");
         do{
         	gotoxy(15,18); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,20); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.e);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,22); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==6){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("IGSS");
    		gotoxy(15,13);	printf("Segun el acuerdo 1123 del Instituto Guatemalteco de Seguridad Social —");
    		gotoxy(15,14);	printf("IGSS—, todo patrono que tenga 3 o mas trabajadores está obligado a");
    		gotoxy(15,15);	printf("inscribirse en el Regimen de Seguridad Social. De esta forma, los");
    		gotoxy(15,16);	printf("trabajadores estarán cubiertos por el seguro social que el estado brinda a");
    		gotoxy(15,17);	printf("la poblacion.");
         do{
         	gotoxy(15,19); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,21); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.f);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==7){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("IRTRA");
    		gotoxy(15,13);	printf("El Instituto de Recreación de los Trabajadores de la Empresa Privada");
    		gotoxy(15,14);	printf("de Guatemala —IRTRA— se dedica a brindar el derecho a recreación que");
    		gotoxy(15,15);	printf("un empleado debe gozar. Además, el carné para entrar a las instalaciones");
    		gotoxy(15,16);	printf("de dicho instituto es brindado a trabajadores del sector privado. ");
         do{
         	gotoxy(15,18); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,21); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.g);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==8){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("JUBILACION");
    		gotoxy(15,13);	printf("En este caso, el trabajador activo pasa a una situacion pasiva o de");
    		gotoxy(15,14);	printf("inactividad laboral, luego de alcanzar una determinada edad maxima");
    		gotoxy(15,15);	printf("legal para trabajar. La prestación suele consistir en una renta mensual");
    		gotoxy(15,16);	printf("para compensar la pérdida de ingresos.");
         do{
         	gotoxy(15,18); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,21); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.h);
            fflush(stdin);
            fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==9){
    		system("cls");
         marco();
    		marcoad();
    		gotoxy(15,10);	printf("DIAS FERIADOS");
    		gotoxy(15,13);	printf("Los días festivos señalados por la legislación guatemalteca serán días no");
    		gotoxy(15,14);	printf("laborables que gozan todos los trabajadores.");
         do{
         	gotoxy(15,16); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
         }while(sigue2!='S' && sigue2!='N');
         if(sigue2=='S'){
         	gotoxy(15,18); printf("Continue: ");
            fflush(stdin);
         	gets(registroP.i);
            fflush(stdin);
         	fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         }
         gotoxy(15,22); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==10){
    		 system("cls");
          marco();
    		 marcoad();
          gotoxy(15,10);	printf("SEPTIMO DIA");
    		 gotoxy(15,13);	printf("Este día es uno de descanso remunerado por cada seis días de trabajo.");
          do{
         	gotoxy(15,15); printf("Desea agregar algo mas? SI[S] o NO[N]: ");  sigue2=toupper(getche()); getch;
          }while(sigue2!='S' && sigue2!='N');
          if(sigue2=='S'){
          	gotoxy(15,18); printf("Continue: ");
          	gets(registroP.j);
            fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
          }
          gotoxy(15,22); printf("Presione una tecla para continuar");
          getch();
          fclose(APlanilla);
    }
    else
    if(opcion78==11){
    		 return;
    }
    do{
 		gotoxy(14,28); printf("Desea seguir viendo las prestaciones? SI[S] o NO[N]: "); sigue=toupper(getche()); getch();
    }while(sigue!='S' && sigue!='N');
 }while(sigue=='S');
  return;
}

void VerPrestacionesLey(FILE *APlanilla){
   system("cls");
   APlanilla=fopen("Planilla.dat","r");
   if(APlanilla==NULL){
   	gotoxy(26,22);	printf("El archivo Planilla.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   char sigue;
   int opcion78;

 do{
 	 MenuPrestacionesLey();
    gotoxy(40,25); printf("Elija la opcion: ");
    scanf("%d", &opcion78);

    if(opcion78==1){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("INDEMNIZACION");
    		gotoxy(15,13);	printf("Se entrega al trabajador que haya sido despedido sin causa justificada. El");
    		gotoxy(15,14);	printf("calculo de dicho pago es equivalente a un mes de salario por cada año de");
    		gotoxy(15,15);	printf("servicios continuos prestados. Ademas, este no excedera de diez meses.");
         gotoxy(15,16); printf("%s",&registroP.a);
         gotoxy(15,20); printf("Presione una tecla para continuar");
    		getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==2){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("VACACIONES");
    		gotoxy(15,13);	printf("Según el articulo 130 del Codigo de Trabajo, todo trabajador tiene derecho");
    		gotoxy(15,14);	printf("a un período de vacaciones remuneradas después de cada año de");
    		gotoxy(15,15);	printf("trabajo continuo. La duracion mínima del descanso es de 15 días habiles.");
    		gotoxy(15,16);	printf("salario, segun la constitucion.");
         gotoxy(15,17); printf("%s",&registroP.b);
         gotoxy(15,20); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==3){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("AGUINALDO");
    		gotoxy(15,13);	printf("Este es un pago anual que tiene todo trabajador desde el primer día de su");
    		gotoxy(15,14);	printf("labor. De hecho, está establecido en el decreto 76-78 del Congreso de la");
    		gotoxy(15,15);	printf("Republica de Guatemala —la ley Reguladora del Aguinaldo— que todo");
    		gotoxy(15,16);	printf("equivale al 100% del salario ordinario mensual por un año de servicios");
    		gotoxy(15,17);	printf("continuos o parte del correspondiente si no se ha cumplido el año");
    		gotoxy(15,19);	printf("Ademas, este se paga en un 50% en la primera quincena de diciembre y el");
    		gotoxy(15,20);	printf("resto en la segunda quincena de enero.");
         gotoxy(15,21); printf("%s",&registroP.c);
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==4){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("BONO 14");
    		gotoxy(15,13);	printf("La Bonificacion Anual para Trabajadores del sector Privado y Publico");
    		gotoxy(15,14);	printf("posee su base legal en el Decreto 42-92. Esta también equivale a un 100%");
    		gotoxy(15,15);	printf("del salario ordinario al mes. Al igual que el aguinaldo, se paga completo si");
    		gotoxy(15,16);	printf("el trabajador ha laborado por un año ininterrumpido. Si la relación laboral");
    		gotoxy(15,17);	printf("ha sido menor a un año, la prestación es proporcional al tiempo laborado.");
    		gotoxy(15,19);	printf("Esta se paga durante la primera quincena del mes de julio de cada año.");
         gotoxy(15,20); printf("%s",&registroP.d);
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==5){
    		system("cls");
         marco();
    		marcoad();
         gotoxy(15,10);	printf("BONIFICACION INCENTIVO");
    		gotoxy(15,13);	printf("Esta bonificacion es medida en cada empresa privada por productividad y");
    		gotoxy(15,14);	printf("eficiencia en mutuo acuerdo con los trabajadores y la empresa. Tiene sus");
    		gotoxy(15,15);	printf("bases legales en el decreto 78-89, Ley de Bonificación Incentivo para los");
    		gotoxy(15,16);	printf("Trabajadores del Sector Privado.");
         gotoxy(15,17); printf("%s",&registroP.e);
         gotoxy(15,22); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==6){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("IGSS");
    		gotoxy(15,13);	printf("Segun el acuerdo 1123 del Instituto Guatemalteco de Seguridad Social —");
    		gotoxy(15,14);	printf("IGSS—, todo patrono que tenga 3 o mas trabajadores está obligado a");
    		gotoxy(15,15);	printf("inscribirse en el Regimen de Seguridad Social. De esta forma, los");
    		gotoxy(15,16);	printf("trabajadores estarán cubiertos por el seguro social que el estado brinda a");
    		gotoxy(15,17);	printf("la poblacion.");
         gotoxy(15,18); printf("%s",&registroP.f);
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==7){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("IRTRA");
    		gotoxy(15,13);	printf("El Instituto de Recreación de los Trabajadores de la Empresa Privada");
    		gotoxy(15,14);	printf("de Guatemala —IRTRA— se dedica a brindar el derecho a recreación que");
    		gotoxy(15,15);	printf("un empleado debe gozar. Además, el carné para entrar a las instalaciones");
    		gotoxy(15,16);	printf("de dicho instituto es brindado a trabajadores del sector privado. ");
         gotoxy(15,17); printf("%s",&registroP.g);
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==8){
    		system("cls");
         marco();
    		marcoad();
      	gotoxy(15,10);	printf("JUBILACION");
    		gotoxy(15,13);	printf("En este caso, el trabajador activo pasa a una situacion pasiva o de");
    		gotoxy(15,14);	printf("inactividad laboral, luego de alcanzar una determinada edad maxima");
    		gotoxy(15,15);	printf("legal para trabajar. La prestación suele consistir en una renta mensual");
    		gotoxy(15,16);	printf("para compensar la pérdida de ingresos.");
         gotoxy(15,17); printf("%s",&registroP.h);
         gotoxy(15,25); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==9){
    		system("cls");
         marco();
    		marcoad();
    		gotoxy(15,10);	printf("DIAS FERIADOS");
    		gotoxy(15,13);	printf("Los días festivos señalados por la legislación guatemalteca serán días no");
    		gotoxy(15,14);	printf("laborables que gozan todos los trabajadores.");
         gotoxy(15,20); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==10){
    		 system("cls");
          marco();
    		 marcoad();
          gotoxy(15,10);	printf("SEPTIMO DIA");
    		 gotoxy(15,13);	printf("Este día es uno de descanso remunerado por cada seis días de trabajo.");
          gotoxy(15,20); printf("Presione una tecla para continuar");
         getch();
         fclose(APlanilla);
    }
    else
    if(opcion78==11){
    		 return;
    }
    do{
 		gotoxy(14,28); printf("Desea seguir viendo las prestaciones? SI[S] o NO[N]: "); sigue=toupper(getche()); getch();
    }while(sigue!='S' && sigue!='N');
 }while(sigue=='S');
  return;
}

void VerJornadaTrabajo(FILE *APlanilla){   //Ver Datos Planilla-jornada de trabajo
   system("cls");
   int existePv;
   int Nitev;           //Variable que servira para comparar el nit del empleado con el nit del empleado que se desea dar horario
   APlanilla=fopen("Planilla.dat","r");
   AEmpleado=fopen("Empleado.dat","r+b");
   if(AEmpleado==NULL){
   	gotoxy(26,22);	printf("El archivo no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   gotoxy(22,6);	printf("JORNADA DE TRABAJO.");
   gotoxy(11,8); printf("Ingrese el NIT del empleado que desea saber su horario de trabajo: ");
   scanf("%s", &Nitev);
   fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
   while(!feof(AEmpleado)){
   	if(Nitev == registroE.NIT1){
   		gotoxy(13,8);  printf(" Jornada de trabajo dias comerciales      Jornada de trabajo dias festivos ");
         gotoxy(13,9);  printf("           %d" ,&registroP.Hin                        , registroP.Hinf);
         gotoxy(13,10); printf("           %d" ,&registroP.Hout                        , registroP.Houtf);
    		fwrite(&registroP, sizeof(sRegistroP), 1, APlanilla);
         existePv=1;
         fclose(AEmpleado);
      }
      if (existePv==0){
      	gotoxy(14,14); printf("No existe un empleado con dicho NIT");
         fclose(APlanilla);
      }
    	fread(&registroE, sizeof(sRegistroE), 1, AEmpleado);
   }
}

void SalarioEmpleado(FILE *APlanilla){   //Ingresar Datos Planilla-salario del empleado
	system("cls");
   int IDAUX;             //Variable para realizar la busqueda del empleado en planilla
   char repet52;          //Variable para repetir el ciclo
   AEmpleado=fopen("Empleado.dat", "r+b");
   if(AEmpleado==NULL){
   	gotoxy(26,22);	printf("El archivo Empleado.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   gotoxy(15,6);	printf("SALARIO EMPLEADO.");
   gotoxy(11,8);	printf("Ingrese el ID del empleado: ");
   scanf("%d",&IDAUX);
   fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   while(!feof(AEmpleado)){
      if(registroE.cod_emp == IDAUX){
      	APlanilla=fopen("Planilla.dat", "a+");          //Nombre del fichero, modo agregar
   		if(APlanilla==NULL){
   			gotoxy(26,22);	printf("El archivo Planilla.dat no existe!");
      		gotoxy(26,23);	printf("Por favor creelo.");
      		gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      		return;
   		}
      	gotoxy(11,15);	printf("El Empleado es: %s",registroE.Nom_emp);
			gotoxy(11,17);	printf("Ingrese el salario del empleado: Q");
  			scanf("%d",&registroP.salario);
  			fwrite(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
         fclose(APlanilla);
         gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
      	getch();
         fclose(AEmpleado);
      }
   	fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   }
   if(registroE.cod_emp != IDAUX){
   	gotoxy(11,18); printf("No se encontro ningun registro con el ID!");
   	do{
      	gotoxy(26,22); printf("Desea intentarlo de nuevo? SI[S] o NO[N]: "); repet52=toupper(getche()); getch;
      }while(repet52!='S' && repet52!='N');
      if(repet52=='S'){
      	gotoxy(26,24);	printf("Presiona cualquier tecla para continuar...");
      	getch();
         SalarioEmpleado(APlanilla);
      }
      else{
      	gotoxy(26,20);	printf("Presiona cualquier tecla para continuar...");
      	return;
      }
   }
}

void encasala(){
	system("cls");
   gotoxy(47,3);	printf("DATOS SALARIO EMPLEADO");
   gotoxy(15,6);	printf("NO.");
   gotoxy(20,6);	printf("ID");
   gotoxy(32,6);	printf("NOMBRE");
   gotoxy(55,6);	printf("APELLIDO");
   gotoxy(72,6);	printf("NIT");
   gotoxy(85,6);	printf("SALARIO");
}

void VerSalario(FILE *APlanilla){        //Modulo para ver el salario del empleado
   APlanilla = fopen ("Planilla.dat", "r");
   if(APlanilla==NULL) {
  		gotoxy(26,22);	printf("Fichero no existe!");printf("%c",7);
      gotoxy(26,23);	printf("Por favor creelo!");
  		gotoxy(26,24);	printf("Preciona cualquier tecla para continuar...");
  		return;
   }
	for(int i=6;i<97;i++){
     gotoxy(i,5);
     printf("%c",177);
   }
   encasala();
   int numero08=1;
   marco();
   fread(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
     while(!feof(APlanilla)){
     		gotoxy(15,numero08+6);	printf("\%d",numero08);
         gotoxy(20,numero08+6);	printf("\%d",registroE.cod_emp);
     		gotoxy(32,numero08+6);	printf("\%s",registroE.Nom_emp);
     		gotoxy(55,numero08+6);	printf("\%s",registroE.Ape_emp);
     		gotoxy(72,numero08+6);	printf("\%d",registroE.NIT1);
     		gotoxy(85,numero08+6);	printf("\%d",registroP.salario);

     		fread(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
     		numero08++;
     }
       gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
       getch();
       fclose(APlanilla);
}

void Planilla(FILE *APlanilla){
	system("cls");
   marco();
   marcoad();
   AEmpleado=fopen("Empleado.dat","r");
   if(AEmpleado==NULL){
   system("color F4");
   	gotoxy(26,22);	printf("El fichero Empleado.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      return;
   }
   int opcPLA,opcPLA1,conti,ConAdmonaux;     			//Variable para los switch de plantilla
   gotoxy(38,8);	printf("Ingrese el PIN del Administrador: ");
   scanf("%d",&ConAdmonaux);
   fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   while(!feof(AEmpleado)){
   	if(ConAdmon == ConAdmonaux){
      	do{
      		system("cls");
            marco();
            marcoad();
            system("color E6");
   			gotoxy(42,6);	printf("USUARIO: ADMINISTRADOR-GRUPO #1");
   			gotoxy(42,7);	printf("PIN: \%d",ConAdmon);
      		MenuPlanillaA();
      		gotoxy(26,20);	printf("Elija una opcion:  ");
      		scanf("%d",&opcPLA);
				switch(opcPLA){
         		case 1:
            		CrearFicheroPla(aplanilla);
               	getch();
            		break;
            	case 2:
               	JornadaTrabajo(aplanilla);
            		break;
            	case 3:
               	SalarioEmpleado(aplanilla);
            		break;
            	case 4:
               	Prestaciones(aplanilla);
            		break;
            	case 5:
               	PrestacionesLey(aplanilla);
            		break;
            	case 6:        //Rompe el ciclo y regresa al menu principal
               	gotoxy(26,22); printf("Presione cualquier tecla para regresar...");
            		break;
            	default:
            		gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
               	gotoxy(26,25); printf("Presione cualquier tecla para regresar...");
               	getch();
      		}
      	}while(opcPLA!=6);
      fclose(AEmpleado);
   	}
   	if(registroE.contra == ConAdmonaux){
   		gotoxy(36,16); printf("Usted no es el administrador!");
      	gotoxy(36,18); printf("Por lo tanto solo puede ver los datos...");
      	gotoxy(36,22); printf("Presione cualquier tecla para continuar....");
      	getch();
      	do{
      		system("cls");
             marco();
            marcoad();
            system("color E6");
      		gotoxy(42,6);	printf("USUARIO: \%s", registroE.Nom_emp);
   			gotoxy(42,7);	printf("PIN: \%d",ConAdmonaux);
      		MenuPlanillaT();
         	gotoxy(26,22);	printf("Elija una opcion:  ");
      		scanf("%d",&opcPLA1);
				switch(opcPLA1){
            	case 1:
                  VerJornadaTrabajo(aplanilla);
            		break;
            	case 2:
               	VerSalario(aplanilla);
            		break;
            	case 3:
               	VerPrestaciones(aplanilla);
            		break;
            	case 4:
               	VerPrestacionesLey(aplanilla);
            		break;
            	case 5:        //Rompe el ciclo y regresa al menu principal
               	gotoxy(26,24); printf("Presione cualquier tecla para regresar...");
            		break;
            	default:
            		gotoxy(26,24);	printf("La opcion que ingreso no es valida.");
               	gotoxy(26,26); printf("Presione cualquier tecla para regresar...");
               	getch();
      		}
      	}while(opcPLA1!=5);
      fclose(AEmpleado);
      fclose(APlanilla);
   	}
      fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   }
   if(ConAdmon != ConAdmonaux  && registroE.contra != ConAdmonaux){
   	gotoxy(26,16); printf("El PIN ingresado es incorrecto!");
      do{
      	gotoxy(26,18); printf("Desea intentarlo de nuevo? SI[S] o NO[N]: "); conti=toupper(getche()); getch;
      }while(conti!='S' && conti!='N');
      if(conti=='S'){
      	gotoxy(26,20);	printf("Preciona cualquier tecla para continuar...");
      	getch();
      	Planilla(AEmpleado);
      }
      else{
      	gotoxy(26,20);	printf("Preciona cualquier tecla para continuar...");
      	return;
      }
   }
}

//****************CODIGO COMPLETO PARA LA BUSQUEDA RAPIDA****************************
void MenuBusqueda(){
	system("cls");
	system("color A1");
   marco();
   marcoad();
   marcoad2();
   int i,d;
   //*********Para las columnas*********************************

   for(i=41;i<70;i++){
   	gotoxy(i,9);
   	printf("%c",205);

      gotoxy(i,11);
   	printf("%c",158);

   	gotoxy(i,15);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=9;d<15;d++){
   	gotoxy(41,d);
   	printf("%c",186);

   	gotoxy(70,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(41,9);
   printf("%c",201);

   gotoxy(41,15);
   printf("%c",200);

   gotoxy(70,9);
   printf("%c",187);

   gotoxy(70,15);
   printf("%c",188);
   gotoxy(50,10);	printf("MENU BUSQUEDA");
   gotoxy(42,12);	printf("1. Buscar Cliente");
   gotoxy(42,13);	printf("2. Buscar Empleado");
   gotoxy(42,14);	printf("3. Volver al Menu Principal");
}

//Modulo para la busqueda de clientes
void BusquedaCliente(FILE *ACliente){
   int BusCliente;
	ACliente=fopen("Cliente.dat", "r+b");		//Nombre del fichero, modo agregar
   if(ACliente==NULL){
   system("color AF");
   	gotoxy(26,22);	printf("El fichero Cliente.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo."); printf("%c",7);
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      getch();
      return;
   }
   system("cls");
   marcoGrande();
   marcoadGrande();

   gotoxy(19,3);printf("Ingrese el NIT del Cliente a buscar: ");
   scanf("%d",&BusCliente);
   fread(&registro, sizeof(struct sRegistro), 1, ACliente);
   while(!feof(ACliente)){
   	if(registro.NIT == BusCliente){
      	system("cls");
         marcoGrande();
   		marcoadGrande();
     		gotoxy(50,5);	printf("DATOS CLIENTE.");
   		gotoxy(10,8);	printf("NOMBRE");
   		gotoxy(29,8);	printf("APELLIDO");
   		gotoxy(50,8);	printf("NIT");
   		gotoxy(62,8);	printf("TELEFONO");
   		gotoxy(74,8);	printf("CORREO");
   		gotoxy(10,10);	printf("\%s",registro.Nom_Client);
   		gotoxy(29,10);	printf("\%s",registro.Ape_Client);
   		gotoxy(50,10);	printf("\%d",registro.NIT);
   		gotoxy(62,10);	printf("\%d",registro.Tel);
   		gotoxy(74,10);	printf("\%s",registro.Correo);
      	gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      	getch();
         fclose(ACliente);
  		}
      fread(&registro, sizeof(struct sRegistro), 1, ACliente);
   }
   if(registro.NIT != BusCliente){
   	gotoxy(26,16); printf("No se encontro ningun registro con el NIT!");
   	do{
      	gotoxy(26,18); printf("Desea intentarlo de nuevo? SI[S] o NO[N]: "); repet1=toupper(getche()); getch;
      }while(repet1!='S' && repet1!='N');
      if(repet1=='S'){
      	gotoxy(26,20);	printf("Preciona cualquier tecla para continuar...");
      	getch();
         BusquedaCliente(ACliente);
      }
      else{
      	gotoxy(26,20);	printf("Preciona cualquier tecla para continuar...");
      	return;
      }
   }
}

//Modulo para la busqueda de empleados
void BusquedaEmpleado(FILE *AEmpleado){
   int BusEmpleado;
	AEmpleado=fopen("Empleado.dat", "r+b");
   if(AEmpleado==NULL){
   system("color AF");
   	gotoxy(26,22);	printf("El fichero Empleado.dat no existe!");
      gotoxy(26,23);	printf("Por favor creelo.");  printf("%c",7);
      gotoxy(26,24);	printf("Presione cualquier tecla para continuar...");
      getch();
      return;
   }
   system("cls");
   marcoGrande();
   marcoadGrande();
   gotoxy(19,3);printf("Ingrese el ID del Empleado a buscar: ");
   scanf("%d",&BusEmpleado);
   fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   while(!feof(AEmpleado)){
   	if(registroE.cod_emp == BusEmpleado){
      	system("cls");
         marcoGrande();
  		   marcoadGrande();
         APlanilla=fopen("Planilla.dat", "r+b");
   	   if(APlanilla==NULL){
   			system("color AF");
   			gotoxy(26,22);	printf("El fichero Planilla.dat no existe!");
      		gotoxy(26,23);	printf("Por favor creelo.");  printf("%c",7);
            gotoxy(26,24);	printf("Ya que si no lo hace no podra ver el salario de dicho empleado");
      		gotoxy(26,25);	printf("Presione cualquier tecla para continuar...");
      		getch();
      		return;
         }
     		gotoxy(50,3);	printf("DATOS EMPLEADO.");
   		gotoxy(10,6);	printf("ID");
   		gotoxy(22,6);	printf("NOMBRE");
   		gotoxy(40,6);	printf("APELLIDO");
   		gotoxy(58,6);	printf("NIT");
   		gotoxy(68,6);	printf("TELEFONO");
   		gotoxy(78,6);	printf("CORREO");
      	gotoxy(10,8);	printf("\%d",registroE.cod_emp);
   		gotoxy(22,8);	printf("\%s",registroE.Nom_emp);
   		gotoxy(40,8);	printf("\%s",registroE.Ape_emp);
   		gotoxy(58,8);	printf("\%d",registroE.NIT1);
   		gotoxy(68,8);	printf("\%d",registroE.Tel1);
      	gotoxy(78,8);	printf("\%s",registroE.correo1);
      	gotoxy(10,14);	printf("CARGO DEL EMPLEADO.");
      	gotoxy(40,14);	printf("CLIENTE DEL EMPLEADO.");
      	gotoxy(10,16);	printf("\%s",registroE.cargo_emp);
      	gotoxy(40,16);	printf("\%s",registroE.client_emp);
      	gotoxy(10,22);	printf("TIPO DE EQUIPO.");
      	gotoxy(40,22);	printf("MOBILIARIO.");
         gotoxy(70,22);	printf("SALARIO.");
      	gotoxy(10,24);	printf("\%s",registroE.t_equipo);
      	gotoxy(40,24);	printf("\%s",registroE.mobi);
         fread(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
         gotoxy(70,24);	printf("\%d",registroP.salario);
         fread(&registroP, sizeof(struct sRegistroP), 1, APlanilla);
      	gotoxy(26,30);	printf("Presione cualquier tecla para continuar...");
      	getch();
         fclose(AEmpleado);
         fclose(APlanilla);
      }
      fread(&registroE, sizeof(struct sRegistroE), 1, AEmpleado);
   }
   if(registroE.cod_emp != BusEmpleado){
   	gotoxy(26,20);printf("No se encontro ningun registro con el ID!");
   	do{
      	gotoxy(26,22); printf("Desea intentarlo de nuevo? SI[S] o NO[N]: "); repet2=toupper(getche()); getch;
      }while(repet2!='S' && repet2!='N');
      if(repet2=='S'){
      	gotoxy(26,24);	printf("Presiona cualquier tecla para continuar...");
      	getch();
         BusquedaEmpleado(AEmpleado);
      }
      else{
      	gotoxy(26,20);	printf("Presiona cualquier tecla para continuar...");
      	return;
      }
   }
}


//******************AUTOR DEL CODIGO**********************************

void Titulo(){
	int i,d;

//*********Para las columnas*********************************

   for(i=4;i<62;i++){
   	gotoxy(i,35);
   	printf("%c",205);

   	gotoxy(i,37);
   	printf("%c",205);
   }

//*********Para las filas************************************

   for(d=36;d<37;d++){
   	gotoxy(4,d);
   	printf("%c",186);

   	gotoxy(62,d);
   	printf("%c",186);
   }
   for(d=7;d<27;d++){
   	gotoxy(105,d);
   	printf("%c",186);

   	gotoxy(107,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(4,35);
   printf("%c",201);

   gotoxy(4,37);
   printf("%c",200);

   gotoxy(62,35);
   printf("%c",187);

   gotoxy(62,37);
   printf("%c",188);

	gotoxy(5,36);	 printf("  ESTUDIANTES DE INGENIERIA EN SISTEMAS GRUPO 1 2020");

   gotoxy(106,8);	    printf("U");
   gotoxy(106,9);	    printf("M");
   gotoxy(106,10);	 printf("G");
   gotoxy(106,13);	 printf("T");
   gotoxy(106,14);	 printf("E");
   gotoxy(106,15);	 printf("R");
   gotoxy(106,16);	 printf("C");
   gotoxy(106,17);	 printf("E");
   gotoxy(106,18);	 printf("R");
   gotoxy(106,21);	 printf("C");
   gotoxy(106,22);	 printf("I");
   gotoxy(106,23);	 printf("C");
   gotoxy(106,24);	 printf("L");
   gotoxy(106,25);	 printf("O");

}

//*****************************Nombre de la universidad*************************************
void Universidad(){

		system("COLOR FC");
		system("mode con: cols=75 lines=38");
      int i,d;

//*********Para las columnas*********************************

   for(i=5;i<70;i++){
   	gotoxy(i,1);
   	printf("%c",205);

   	gotoxy(i,34);
   	printf("%c",205);
   }
//*********Para las filas************************************

   for(d=1;d<34;d++){
   	gotoxy(5,d);
   	printf("%c",186);

   	gotoxy(70,d);
   	printf("%c",186);
   }

//***********Las esquinas*************************************
   gotoxy(5,1);
   printf("%c",201);

   gotoxy(5,34);
   printf("%c",200);

   gotoxy(70,1);
   printf("%c",187);

   gotoxy(70,34);
   printf("%c",188);

		gotoxy(10,3); printf("%c",201);printf("%c",187);printf("-");printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",187);printf("-");printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",187);printf("--");printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);
      gotoxy(10,4); printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",185);printf("%c",204);printf("%c",188);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",185);printf("%c",204);printf("%c",188);printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",187);printf("%c",186);
      gotoxy(10,5); printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",200);printf("%c",188);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("-");printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",188);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("-");printf("%c",186);printf("%c",186);printf("--");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);
      gotoxy(10,6); printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("--");printf("%c",186);printf("%c",200);printf("%c",188);printf("%c",186);printf("-");printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",205);;printf("%c",188);printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("--");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);
      gotoxy(10,7); printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",185);printf("%c",204);printf("%c",187);printf("-");printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",188);printf("-");printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",201);printf("%c",185);printf("%c",204);printf("%c",187);printf("%c",201);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",201);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",186);
      gotoxy(10,8); printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",188);printf("--");printf("%c",200);printf("%c",188);printf("--");printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);

      gotoxy(20,11); printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",187);printf("-");printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);
      gotoxy(20,12); printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",185);printf("%c",204);printf("%c",188);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);
      gotoxy(20,13); printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);
      gotoxy(20,14); printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",188);printf("-");printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);
      gotoxy(20,15); printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",185);printf("%c",204);printf("%c",187);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);
      gotoxy(20,16); printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);

      gotoxy(22,19); printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",187);printf("---");printf("%c",201);printf("%c",187);printf("--");printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);
      gotoxy(22,20); printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("---");printf("%c",186);printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",205);printf("%c",186);
      gotoxy(22,21); printf("%c",186);printf("%c",186);printf("-");printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("---");printf("%c",200);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",188);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("--");printf("%c",201);printf("%c",188);printf("%c",201);printf("%c",188);
      gotoxy(22,22); printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",201);printf("%c",187);printf("-");printf("%c",186);printf("%c",200);printf("%c",188);printf("%c",186);printf("-");printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",188);printf("-");printf("%c",201);printf("%c",188);printf("%c",201);printf("%c",188);printf("-");
      gotoxy(22,23); printf("%c",186);printf("%c",200);printf("%c",202);printf("%c",205);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("-");printf("%c",200);printf("%c",187);printf("%c",201);printf("%c",188);printf("-");printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",188);printf("%c",205);printf("%c",200);printf("%c",205);printf("%c",187);
      gotoxy(22,24); printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("--");printf("%c",200);printf("%c",188);printf("--");printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);

      gotoxy(15,26); printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",187);printf("-");printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",201);printf("%c",187);printf("---");printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",187);
      gotoxy(15,27); printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("---");printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);
      gotoxy(15,28); printf("%c",186);printf("%c",186);printf("-");printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",188);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",201);printf("%c",187);printf("%c",201);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("---");printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);
      gotoxy(15,29); printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("-");printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("--");printf("%c",186);printf("%c",186);printf("--");printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",186);printf("-");printf("%c",201);printf("%c",187);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);
      gotoxy(15,30); printf("%c",186);printf("%c",200);printf("%c",202);printf("%c",205);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("--");printf("%c",186);printf("%c",186);printf("--");printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);printf("%c",186);printf("%c",200);printf("%c",205);printf("%c",188);printf("%c",186);printf("%c",186);printf("%c",201);printf("%c",205);printf("%c",187);printf("%c",186);
      gotoxy(15,31); printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);printf("--");printf("%c",200);printf("%c",188);printf("--");printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);printf("%c",200);printf("%c",205);printf("%c",205);printf("%c",205);printf("%c",188);printf("%c",200);printf("%c",188);printf("-");printf("%c",200);printf("%c",188);
      gotoxy(18,33);  printf("Presione cualquier tecla para continuar....");
      getch();
   }


//********************MENSAJE DE SALIDA*********************************
void Salir(){
	system("color 3E");
	gotoxy(36,16);; printf("El programa ha finalizado! Gracias!!!");
   gotoxy(36,18);  printf("Presione cualquier tecla para salir....");
}

//*******************************NOTA 2:***************************************
//SI LO EJECUTA EN BORLAND DEJARLO COMO ESTA, PERO SI LO EJECUTA EN DEV COLOCAR EL VOID MAIN EN COMENTARIO Y QUITARLE LO DEL COMENTARIO A INT MAIN...**********
/* int main(){ */
void main(){
	PantallaDeCarga();
   Universidad();
	system("mode con: cols=110 lines=38");     //tamaño de la ventana
	caratula();
	bienvenida();
   int opcion,opcion1,opcionTP,opcionB,opcionC,opcionE,opcionV;
   do{
   	MenuPrincipal();
      Titulo();
      gotoxy(26,20);	printf("Elija una opcion:  ");
      scanf("%d",&opcion);
      switch(opcion){
      	case 1:
         	gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
            do{
         		MenuCliente();
               Titulo();
            	gotoxy(26,20);	printf("Elija una opcion: ");
      			scanf("%d",&opcionC);
               switch(opcionC){
               	case 1:
                  	CrearFichero(acliente);
                     break;
                  case 2:
                  	AgregarCliente(acliente);
                     break;
                  case 3:
                  	VerDatosCliente(acliente);
                     break;
                  case 4:
                  	ModCliente(acliente);
                     break;
                  case 5:
                     BoClienteLogica(acliente);
                  	break;
                  case 6:                               //Rompe el ciclo y nos manda el menu principal
                     gotoxy(26,22);	printf("Presione cualquier tecla para continuar...");
                  	break;
                  default:
                  	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
         				gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
               }
            }while(opcionC!=6);
            break;
         case 2:
            gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
         	do{
            	MenuEmpleado();
               Titulo();
               gotoxy(26,20);	printf("Elija una opcion: ");
      			scanf("%d",&opcionE);
               gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
               switch(opcionE){
               	case 1:
                  	CrearFicheroE(aempleado);
                     break;
                  case 2:
                  	AgregarEmpleado(aempleado);
                     break;
                  case 3:
                  	do{
                  		MenuDatosE();
                     	gotoxy(26,20);	printf("Elija una opcion: ");
      						scanf("%d",&opcion1);
                        gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
               			switch(opcion1){
                  			case 1:
                        		DatosPersoEmp(aempleado);    //informacion personal del empleado
                           	break;
                        	case 2:
                        		VerCargoEmpleado(aempleado);
                           	break;
                        	case 3:
                        		VerClientEmpleado(aempleado);
                           	break;
                        	case 4:
                        		VerTipoEquipo(aempleado);
                           	break;
                        	case 5:
                        		VerMobiliario(aempleado);
                           	break;
                           case 6:
                           	VerContraEm(aempleado);
                           	break;
                        	case 7:                        //Rompe el ciclo y nos regresa al menu datos del empleado
                           	gotoxy(26,23); printf("Presione cualquier tecla para continuar...");
                        		break;
                        	default:
                        	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
                     	}
                     }while(opcion1!=7);
                     break;
                  case 4:
                  	ModEmpleado(aempleado);
                     break;
                  case 5:
                  	BoEmpleado(aempleado);
                     break;
                  case 6: 									//Rompe el ciclo y nos manda al menu principal
                     gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
                  	break;
                  default:
                  	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
         				gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
               }
            }while(opcionE!=6);
            break;
         case 3:
            gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
         	do{
         		MenuVenta();
               Titulo();
               gotoxy(26,22);	printf("Elija una opcion: ");
      			scanf("%d",&opcionV);
               switch(opcionV){
               	case 1:
                     CrearFicheroVP(aventa);
                  	break;
                  case 2:
                     gotoxy(26,25);	printf("Presione cualquier tecla para continuar...");
                  	do{
                  		MenuAP();
                        gotoxy(26,18);	printf("Elija una opcion: ");
      						scanf("%d",&opcion);
                        switch(opcion){
                        	case 1:
                              gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
                           	do{
                           		MenuIP();
                                 gotoxy(26,22);	printf("Elija una opcion: ");
      									scanf("%d",&opcion);
                        			switch(opcion){
                                 	case 1:
                                    	IngresarProductosB(aventa);
                                    	break;
                                    case 2:
                                       IngresarProductosH(aventa);
                                    	break;
                                    case 3:
                                       IngresarProductosC(aventa);
                                    	break;
                                    case 4:
                                       IngresarProductosC1(aventa);
                                    	break;
                                    case 5:
                                       IngresarProductosVP(aventa);
                                    	break;
                                    case 6:
                                       IngresarProductosPP(aventa);
                                    	break;
                                    case 7:
                                       IngresarProductosM(aventa);
                                    	break;
                                    case 8:
                                       IngresarProductosS(aventa);
                                    	break;
                                    case 9:
                                       IngresarProductosBP(aventa);
                                    	break;
                                    case 10:                    //Rompe el ciclo y nos manda el menu agreagar producto
                                    	gotoxy(26,28);	printf("Presione cualquier tecla para continuar...");
                                       break;
                                    default:
                                    	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
                                 }
                              }while(opcion!=10);
                           	break;
                           case 2:         //Rompe el ciclo y nos manda al menu venta
                           	gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
                           	break;
                           default:
                           	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
                        }
                     }while(opcion!=2);
                  	break;
                  case 3:
                     gotoxy(26,25);	printf("Presione cualquier tecla para continuar...");
                  	do{
                  		MenuTP();
                        Titulo();
                        gotoxy(26,22);	printf("Elija una opcion: ");
                        	scanf("%d",&opcionTP);
                        	switch(opcionTP){
                             	case 1:
                              	VerProductoB(aventa);
                              	gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                              	getch();
                                 break;
                              case 2:
                              	VerProductoH(aventa);
                              	gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                                 getch();
								 			break;
                              case 3:
                              	VerProductosC(aventa);
                              	gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                              	getch();
                                 break;
                              case 4:
                                 VerProductoC1(aventa);
                                 gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                                 getch();
                                 break;
                              case 5:
                                 VerProductosVP(aventa);
                                 gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                                 getch();
                                 break;
                              case 6:
                                 VerProductoPP(aventa);
                                 gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                                 getch();
                                 break;
                              case 7:
                                 VerProductoM(aventa);
                                 gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                                 getch();
                                 break;
                              case 8:
                                 VerProductoS(aventa);
                                 gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                                 getch();
                              	break;
                              case 9:
                              	VerProductoBP(aventa);
                              	gotoxy(26,30);	printf("Preciona dos veces cualquier tecla para continuar...");
                              	getch();
                                 break;
                              case 10:                    //Rompe el ciclo y nos manda el menu ver producto
                              	gotoxy(26,26);	printf("Presione cualquier tecla para continuar...");
                                 break;
                              default:
                              	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
                           }
                     }while(opcionTP!=10);
                  	break;
                  case 4:
                  	NuevaVenta(aventa);
                  	break;
                  case 5:
                  	VerVenta(aventa);
                  	break;
                  case 6:          //Rompe el ciclo y nos manda al menu principal
                  	gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
                  	break;
                  default:
                  	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
               }
            }while(opcionV!=6);
         	break;
         case 4:
         	Planilla(aplanilla);
            Titulo();
         	break;
         case 5:
            gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
         	do{
            	MenuBusqueda();
               Titulo();
               gotoxy(26,19);	printf("Elija una opcion:  ");
      			scanf("%d",&opcionB);
       			switch(opcionB){
               	case 1:
         		   	BusquedaCliente(acliente);
                     break;
                  case 2:
                  	BusquedaEmpleado(aempleado);
                     break;
                  case 3:           //Rompe el ciclo y regresa al menu principal
                  	gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
                  	break;
                  default:
                  	gotoxy(26,22);	printf("La opcion que ingreso no es valida.");
               }
            }while(opcionB!=3);
            break;
         case 6:                //Rompe el ciclo y sale
				system("cls");
            Salir();
            getch();
         	break;
      	default:
      		gotoxy(26,22); printf("La opcion que ingreso no es valida.");
         	gotoxy(26,23);	printf("Presione cualquier tecla para continuar...");
      }
   }while(opcion!=6);
}
