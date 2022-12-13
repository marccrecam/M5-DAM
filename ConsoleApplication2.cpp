// ConsoleApplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <MMSystem.h>

using namespace std;


//Atributos del enemigo1
int enemylive = 1000;
int enemydamage;
string Enemyname = "Malo";
bool enemyIsAlive = true;
//sonidos


//Atributos del heroe
string heroname;
int herodamage;
int heroHP = 5000;
bool heroIsAlive = true;
int escoger;

//Atributos del enemigo2
int villanolive = 1000;
int villanodamage;
string Villanoname = "Malisimo";
bool villanoIsAlive = true;

//ataques especiales 
int espada = 350;
int golpe = 250;
int magia = 500;
int usos = 2;
int ataque;

void gameStart() {
    cout << "El enemigo " << Enemyname << " y el villano " << Villanoname << " acaban de aparecer y tienen " << enemylive << " y " << villanolive << " de vida respectivamente.\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroname;
    cout << "El nombre del heroe es " << heroname << "\n\n";
}

int chooseEnemy() {
    escoger = 0;     
    cout << "A que enemigo quieres atacar? [1/2]\n";
    cin >> escoger;
    while(escoger != 1 && escoger != 2)
        if (escoger == 1 || escoger == 2) {
            return escoger;
        }    
         else if (escoger != 1 && escoger != 2) {
            cout << "Acabas de atacar al aire no hay tantos enemigos \n";
            cout << "A que enemigo quieres atacar? [1/2]\n";
            cin >> escoger;
         }   
}

void chooseattack() {
    cout << "\nQue ataque quieres hacer?\n"
        "Espada [1]\n" "Golpe [2]\n" "Magia[3] Te quedan " << usos << " ataques restantes\n";
    cin >> ataque;
    if (enemyIsAlive) {    
        if (escoger == 1) {
            if (ataque == 1) {
                enemylive = enemylive - espada;
            }
            else if (ataque == 2) {
                enemylive = enemylive - golpe;
            }
            else if (ataque == 3) {
                if (usos != 0) {
                    enemylive = enemylive - magia;
                    usos -= 1;
                }
                else {
                    cout << "No te quedan mas ataques de magia restantes\n";
                }
            }
            else {
               cout<<"Acabas de perder tu oportunidad de atacar\n";
            }
        
    

            if (enemylive <= 0) {
                enemylive = 0;
                enemyIsAlive = false;
                cout << "Has derrotado al enemigo\n";

            }
            cout << "\nAl enemigo malo le quedan " << enemylive << " de vida y al villano malisimo le quedan " << villanolive << " de vida.\n\n";
        }
    }
    else {
        cout << "\nYa has matado al enemigo, no puedes seguir atacando\n";
    }
    if (villanoIsAlive) {    
        if (escoger == 2) {
            if (ataque == 1) {
                villanolive = villanolive - espada;
            }
            else if (ataque == 2) {
                villanolive = villanolive - golpe;
            }
            else if (ataque == 3 && usos != 0) {
                if (ataque == 3) {
                    villanolive = villanolive - magia;
                    usos -= 1;
                }
                else {
                    cout << "No te quedan mas ataques de magia restantes\n";
                }
            }
            else {
                cout << "Acabas de perder tu oportunidad de atacar\n";
            }

            if (villanolive <= 0) {
                villanolive = 0;
                villanoIsAlive = false;
                cout << "Has derrotado al villano\n";
            }
            cout << "\nAl enemigo malo le quedan " << enemylive << " de vida y al villano malisimo le quedan " << villanolive << " de vida.\n\n";
        } 
    }
    else {
        cout << "\nYa has matado al villano, no puedes seguir atacando\n";
    }
}

bool enemysAttack() {
    enemydamage = rand() % 999 + 30;
    villanodamage = rand() % 999 + 30;
    if (enemyIsAlive && villanoIsAlive) {
        heroHP = heroHP - (enemydamage + villanodamage);
        if (heroHP <= 0) {
            heroHP = 0;
        }
        cout << "El enemigo y el villano te han hecho " << enemydamage + villanodamage << " puntos de ataque y te quedan " << heroHP << " puntos de vida.\n\n\n";
    }
    else if (enemyIsAlive == true && villanoIsAlive == false) {
        heroHP = heroHP - enemydamage;
        if (heroHP <= 0) {
            heroHP = 0;
        }
        cout << "El enemigo te ha hecho " << enemydamage << " puntos de ataque y te quedan " << heroHP << " puntos de vida.\n\n\n";
    }
    else if (enemyIsAlive == false && villanoIsAlive == true) {
        heroHP = heroHP - villanodamage;
        if (heroHP <= 0) {
            heroHP = 0;
        }
        cout << "El villano te ha hecho " << villanodamage << " puntos de ataque y te quedan " << heroHP << " puntos de vida.\n\n\n";
    }
    else if (enemyIsAlive == false && villanoIsAlive == false) {
        cout << "Has ganado el combate!!!\n";
    }
    if (heroHP <= 0) {
        return false;
        cout << "El heroe ha sido derrotado\n";
    }
}

int main()
{
    srand(time(NULL));

    gameStart();

    while ((enemyIsAlive || villanoIsAlive) && heroIsAlive) {
       chooseEnemy();
       chooseattack();
        

       enemydamage = rand() % 999 + 30;
       villanodamage = rand() % 999 + 30;

       heroIsAlive = enemysAttack();

        }

    }



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
