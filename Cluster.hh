/** @file Cluster.hh
    @brief Especificación de la clase Cluster.
*/

#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "Procesador.hh"
#include "Area_de_Espera.hh"

/** @class Cluster
 *  @brief Esta clase hace referencia a un Cluster un conjunto de procesadores (minimo 1) que
 *  realizan procesos y tareas. Dispone de un contador de tiempo y permite operar con los procesadores: asignar tareas (procesos) a partir de la area de espera o inserta de forma directa a un
 *  procesador del Cluster o bien compactar la memoria de estos.
*/
class Cluster {

    private:

    public:

    //Constructoras
    /** @brief Creadora por defecto
    * \pre <em>cierto</em>
    * \post El resultado es un Cluster vacio.
    */
    Cluster();


    //Modificadoras

    /** @brief Modificadora que permite fusionar dos clusters.
     * \pre Existe el procesador p en el parametro implicito y este no tiene procesadores auxiliaries ni tampoco procesos en ejecución.
     * \post Se ha colocado el Cluster del parametro en el lugar de p, substituyendo este por la raiz del Cluster del parametro.
    */
    void modificar_cluster (string id_procesador, const Cluster &c); //Requiere metodo privado

    /** @brief Modificadora que compacta la memoria de un procesador.
     * \pre  Existe un procesador con el el identifacador como el parametro id_procesador en el cluster.
     * \post Se han movido todos los procesos de la memoria del procesador al principio, sin dejar huecos ni que se solapen entre procesos.
    */
    void compactar_memoria_procesador(string id_procesador);

    /** @brief Modificadora que compacta las memorias de todos los procesadores del cluster.
     * \pre <em>cierto</em>
     * \post Se han movido todos los procesos de las memorias de los procesadores del cluster del parametro implici al principio, sin dejar huecos ni solapar-se.
    */
    void compactar_memoria_cluster();

    /** @brief Modificadora que envia n procesos (eligidos tienendo en cuenta el orden de prioridad, y los más antiguos) de una area de espera a los procesadores del cluster del parametro implicito.
     *  Si no hay espacio, entonces el proceso es rechazado y devuelto a la area de espera original.
     * \pre n >= 0.
     * \post Se han enviado los n procesos de la area de espera a los procesadores del cluster del parametro implicito y se ha actualizado en la area de espera el numero de procesos acceptados y rechazados en las
     * prioridades correspondentes.
    */
    void enviar_procesos_cluster(int n, Area_de_Espera &ae); // Require metodo para consultar prioridades en ae, modificaciones en el ae los numeros.

    /** @brief Modificadora que envia un proceso especificado en el parametro job a un procesador identificado como id_procesador del parametro. El proceso es colocado al hueco más ajustado y ocupa la memoria que se especifica en job.
     * \pre Existe un procesador con identificador de id_procesador que no tiene previamente un proceso nombrado igual que job (proceso del parametro).
     * \post Se ejecuta el proceso job en el procesador id_procesador del cluster del parametro implicito.
    */
    void alta_proceso_procesador(string id_procesador, const Proceso &job);

    /** @brief Modificadora que elimina un proceso con identificador id_job que se esta ejecutando en un procesador identificado como id_procesador del cluster.
     * \pre Existe un procesador con identificador de id_procesador y esta ejecutando un proceso nombrado igual que id_job.
     * \post Se ha eliminado el proceso identificado como id_job que se estaba ejecutando en un procesador nombrado id_procesador del cluster del parametro implicito.
    */
    void baja_proceso_procesador(string id_procesador, int id_job); 

    /** @brief Modificadora el contador tiempo transcurrido.
     * \pre t >= 0.
     * \post Se ha avanzado t unidades de tiempo.
    */  
    void avanzar_tiempo(int t); 


    //Lectura y Escriptura

    /** @brief Operacion de lectura de Cluster.
     * \pre <em>Cierto></em>
     * \post El Cluster del parametro implicito queda inicializado con los procesadores y sus respectivas memorias.
    */  
    void configurar_cluster (); //requiere metodos en privado.

    /** @brief Operacion de escriptura del Cluster.
     * \pre <em>Cierto</em>
     * \post Se escribe para todos los procesadores en orden creciente de identificador en el canal de salida, los procesos que se esta ejecutando en el procesador con identificador id_procesador y 
     * su posición de memoria en orden creciente de primera posición de memoria, juntamente con los datos de cada proceso.
    */  
    void imprimir_procesador_cluster() const;

    /** @brief Operacion de escriptura del Cluster.
     * \pre <em>Cierto></em>
     * \post Se ha escrito la estructura los procesadores del Cluster por el canal.
    */    
    void imprimir_estructura_cluster() const; //Requiere metodo privado.

    /** @brief Operacion de escriptura del procesador.
     * \pre <em>cierto</em>
     * \post Se escribe por orden creciente de primera posición de memoria en el canal de salida los procesos que se esta ejecutando en el procesador con identificador id_procesador y 
     * su posición de memoria, juntamente con los datos de cada proceso.
    */
    void imprimir_procesador(string id_procesador) const;
    
};
#endif