/** @file Cluster.hh
    @brief Especificación de la clase Cluster.
*/

#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "Procesador.hh"
#include "Proceso.hh"
/** @class Cluster
 *  @brief Esta clase hace referencia a un Cluster, un conjunto de procesadores (minimo 1) que
 *  realizan procesos y tareas. Permite anadir procesadores al Cluster, compactar la memoria de
 *  un procesador o todos los procesadores del Cluster, dar de alta a procesos (directamente a
 *  un procesador determinado o al procesador más optimo. También permite hacer consultas sobre
 *  l'estado de un procesador, si existe, tiene tareas en ejecución, si tiene procesadores auxiliares y
 *  la memoria disponible. No obstante, dispone de un contador de tiempo, se puede avanzar el tiempo para
 *  terminar los procesos en ejecución. Por último, dispone de operaciones de lectura y escriptura a nivell
 *  de cluster y a nivell de procesador. 
*/
class Cluster {

    public:

    //Constructoras

    /** @brief Creadora por defecto
    * \pre <em>cierto</em>
    * \post El resultado es un Cluster vacio.
    */
    Cluster();

    //Modificadoras

    /** @brief Modificadora que permite añadir (fusionar) un cluster a un otro.
     * \pre Existe el procesador p en el Cluster del parametro implicito y este procesador 
     * no tiene procesadores auxiliaries ni tampoco procesos en ejecución.
     * \post Se ha colocado el Cluster <em>c</em> del parametro en el lugar de <em>p</em>, substituyendo
     * este por la raiz del Cluster del parametro.
    */
    void modificar_cluster (string id_procesador, const Cluster &c); //Requiere metodo privado

    /** @brief Modificadora que compacta la memoria de un procesador.
     * \pre  Existe un procesador con el el identificador como el parametro <em>id_procesador</em>
     *  en el cluster.
     * \post Se han movido todos los procesos de la memoria del procesador <em>id_procesador</em>
     *  al principio, sin dejar huecos ni que se solapen entre procesos.
    */
    void compactar_memoria_procesador(string id_procesador);

    /** @brief Modificadora que compacta las memorias de todos los procesadores del cluster.
     * \pre <em>cierto</em>
     * \post Se han movido todos los procesos de las memorias de los procesadores del cluster
     *  del parametro implici al principio, sin dejar huecos ni solapar-se.
    */
    void compactar_memoria_cluster();

    /** @brief Modificadora que envia un proceso a un procesador determinado. El proceso es
     *  colocado al hueco más ajustado.
     * \pre Existe un procesador con identificador de <em>id_procesador</em> que no tiene previamente
     *  un proceso nombrado igual que <em>job</em>.
     * \post Se ejecuta el proceso <em>job</em> en el procesador <em>id_procesador</em> del
     *  cluster del parametro implicito.
    */
    void alta_proceso_procesador(string id_procesador, const Proceso &job);

    /** @brief Modificadora que elimina un proceso que se esta ejecutando en un procesador del cluster.
     * \pre Existe un procesador con identificador <em>id_procesador</em> y esta ejecutando
     *  un proceso nombrado igual que id_job.
     * \post Se ha eliminado el proceso identificado como <em>id_job</em> que se estaba ejecutando 
     *  en un procesador nombrado <em>id_procesador</em> del cluster del parametro implicito.
    */
    void baja_proceso_procesador(string id_procesador, int id_job); 

    /** @brief Modificadora que envia un proceso a un procesador del cluster, se eligira el
     *  procesador con un hueco en la memoria más ajustado al requerido, en caso de empate,
     *  el que tenga más memoria libre. Si persiste el empate, el que se encuentra mas cerca
     *  del procesador principal. Como ultimo criterio de empate, el procesador que está más
     *  a la izquierda.
     * \pre <em>cierto</em>
     * \post El resultado indica si se ha podido colocar el proceso job en alguno de los
     *  procesadores del cluster del parametro implicito.
    */
    bool alta_proceso(const Proceso &job); 

    /** @brief Modificadora el contador tiempo transcurrido.
     * \pre t >= 0.
     * \post Se ha avanzado <em>t</em> unidades de tiempo.
    */  
    void avanzar_tiempo(int t); 

    //Consultoras

    /** @brief Consultora que indica la existencia de un procesador en el cluster.
     * \pre <em>cierto</em>
     * \post El resultado indica si existe un procesador con identificador <em>id_procesador</em>.
    */  
    bool existe_procesador(string id_procesador) const;

    /** @brief Consultora que indica si un procesador tiene procesador auxiliares.
     * \pre Existe un procesador en el cluster del parametro implicito identificado como
     * <em>id_procesador</em>.
     * \post El resultado indica si el procesador con identificador <em>id_procesador</em>
     *  tiene procesadores auxiliares.
    */  
    bool vacio (string id_procesador) const;

    /** @brief Consultora que indica si un procesador esta ocupado.
     * \pre Existe un procesador en el cluster del parametro implicito identificado como 
     * <em>id_procesador</em>.
     * \post El resultado indica si el procesador con identificador <em>id_procesador</em>
     *  tiene procesos pendientes.
    */  
    bool procesador_ocupado (string id_procesador) const;

    /** @brief Consultora que indica la existencia de un proceso en un procesador del cluster.
     * \pre Existe un procesador en el cluster del parametro implicito identificado como
     * <em>id_procesador</em>.
     * \post El resultado indica si existe un proceso identificado como <em>id_job</em> en
     *  un procesador del cluster del parametro implicito, identificado como <em>id_procesador</em>.
    */  
    bool existe_proceso(string id_procesador, int id_job) const;

    /** @brief Consultora del tamaño del hueco más grande en la memoria de un procesador.
     * \pre El procesador con <em>id_procesador</em> existe en el cluster del parametro implicito.
     * \post El resultado indica el tamano del hueco más grande en el procesador <em>id_procesador</em>
     *  del cluster del parametro implicito.
    */
    int espacio_procesador (string id_procesador) const;

    //Lectura y Escriptura

    /** @brief Operacion de lectura de Cluster.
     * \pre <em>Cierto></em>
     * \post El Cluster del parametro implicito queda inicializado con los procesadores y 
     * sus respectivas memorias.
    */  
    void configurar_cluster (); //requiere metodos en privado.

    /** @brief Operacion de escriptura del Cluster.
     * \pre <em>Cierto</em>
     * \post Se escribe en el canal de salida, para todos los procesadores por orden creciente
     *  de identificador, los procesos que se esta ejecutando, empezando por la primera posición
     *  de memoria en orden creciente los datos de cada proceso.
    */  
    void imprimir_procesador_cluster() const;

    /** @brief Operacion de escriptura del Cluster.
     * \pre <em>Cierto></em>
     * \post Se ha escrito la estructura los procesadores del Cluster del parametro implicito
     *  por el canal de salida.
    */    
    void imprimir_estructura_cluster() const; //Requiere metodo privado.

    /** @brief Operacion de escriptura del procesador.
     * \pre <em>cierto</em>
     * \post Se escribe por orden creciente de primera posición de memoria en el canal de 
     * salida los procesos que se esta ejecutando en el procesador con identificador <em>id_procesador</em>
     * y su posición de memoria, juntamente con los datos de cada proceso.
    */
    void imprimir_procesador(string id_procesador) const;
    
    
    private:

};
#endif