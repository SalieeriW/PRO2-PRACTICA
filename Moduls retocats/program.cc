/** @mainpage
 * 
 *  El programa principal se encuentra en el program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar Procesador, donde el conjunto de ellos da lugar
    a otro modulo llamado Cluster. Por otro lado tenemos una Area_de_Espera, donde
    habrá Proceso, un nuevo modulo que se define como la tarea que realiza los Clusters,
    cada procesos estará contenido en una Prioridad, el conjunto de procesos. El conjunto de
    Prioridades forma la area de espera.
 */

/** @file program.cc
    @brief Programa princial.

    Suponemos que los datos leídos son siempre correctos, en caso contrario, se imprimirá
    un mensaje de error internamente por la funciones principales de cada clase. Para acceder
     a las opciones disponibles usaremos comandos.
*/

#include "Cluster.hh"
#include "Proceso.hh"
#include "Area_de_Espera.hh"

int main () {

    Cluster c1;
    c1.configurar_cluster();

    Area_de_Espera ae;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string id_prioridad;
        cin >> id_prioridad;
        ae.alta_prioridad(id_prioridad);
    }

    string command;
    cin >> command;
    while (command != "fin") {

        if (command == "cc") {
            c1.configurar_cluster();
        }
        else if (command == "mc"){
            string id_procesador;
            cin >> id_procesador;

            Cluster c2;
            c2.configurar_cluster();
            
            c1.modificar_cluster(id_procesador,c2);
        }
        else if (command == "ap"){
            string id_prioridad;
            cin >> id_prioridad;

            ae.alta_prioridad(id_prioridad);
        }
        else if (command == "bp"){
            string id_prioridad;
            cin >> id_prioridad;

            ae.baja_prioridad(id_prioridad);
        }
        else if (command == "ape"){
            Proceso job;
            job.leer();

            string id_prioridad;
            cin >> id_prioridad;

            ae.alta_proceso_espera(id_prioridad, job);
        }
        else if (command == "app"){
            string id_procesador;
            cin >> id_procesador;

            Proceso job;
            job.leer();

            c1.alta_proceso_procesador(id_procesador, job);
        }
        else if (command == "bpp"){
            string id_procesador;
            cin >> id_procesador;

            int id_job;
            cin >> id_job;

            c1.baja_proceso_procesador(id_procesador, id_job);
        }
        else if (command == "epc"){
            int n;
            cin >> n;
            ae.enviar_procesos_cluster(n,c1);
        }
        else if (command == "at"){
            int t;
            cin >> t;

            c1.avanzar_tiempo(t);
        }
        else if (command == "ipri"){
            string id_prioridad;
            cin >> id_prioridad;

            ae.imprimir_prioridad(id_prioridad);
        }
        else if (command == "iae"){
            ae.imprimir_area_espera();
        }
        else if (command == "ipro"){
            string id_procesador;
            cin >> id_procesador;

            c1.imprimir_procesador(id_procesador);
        }
        else if (command == "ipc"){
            c1.imprimir_procesador_cluster();
        }
        else if (command == "iec"){
            c1.imprimir_estructura_cluster();
        }
        else if (command == "cmp"){
            string id_procesador;
            cin >> id_procesador;

            c1.compactar_memoria_procesador(id_procesador);
        }
        else if (command == "cmc"){
            c1.compactar_memoria_cluster();
        }
        cin >> command;
    }
}