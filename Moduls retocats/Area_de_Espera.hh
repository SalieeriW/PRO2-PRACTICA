/** @file Area_de_Espera.hh
    @brief Especificación de la clase Area de Espera.
*/

#ifndef AREA_DE_ESPERA_HH
#define AREA_DE_ESPERA_HH

#include "Cluster.hh"
#include "Prioridad.hh"
#include "Proceso.hh"    

/** @class Area_de_Espera
 *  @brief Hace referencia a la area de espera de los procesos.
 *  Contiene procesos que se quieren tratar en el cluster classificados por prioridad.
 *  Puede usarse para crear o destruir una prioridad, poner un proceso en espera, dar de
 *  alta a procesos al cluster, consultar la existencia de prioridades y procesos, consultar
 *  si una prioridad tiene tareas pendientes y dispone de operaciones d'escriptura para una
 *  o todas las prioridades.
 * 
*/
class Area_de_Espera {

    public:

    // Constructoras

    /** @brief Creadora por defecto.
     * Se ejecuta automáticamente al declarar una nueva area de espera.
     * \pre <em>cierto</em>
     * \post El resultado es una area de espera sin ningúna prioridad ni proceso.
    */
    Area_de_Espera();

    // Modificadoras

    /** @brief Modificadora que anade una nueva prioridad a una area de espera.
     * \pre <em>cierto</em>
     * \post Se ha añadido una nueva prioridad identificado como <em>id_prioridad</em> a la 
     * area de espera del parametro implicito.
    */
    void alta_prioridad(string id_prioridad);

    /** @brief Modificadora que elimina una prioridad en una area de espera.
     * \pre Existe una prioridad identificada como el parametro <em>id_prioridad</em> en 
     * la area de espera del parametro implicito. En caso que exista, no puede tener procesos 
     * pendientes en ella.
     * \post Se ha eliminado la prioridad identificada como <em>id_prioridad</em> a la area de
     *  espera del parametro implicito.
    */
    void baja_prioridad(string id_prioridad);

    /** @brief Modificadora que anade un proceso a una prioridad de la area de espera.
     * \pre Existe una prioridad con el identificador del parametro <em>id_prioridad</em>.
     *  No existe previamente un proceso con el mismo identificador en dicha prioridad.
     * \post Se ha anadido un proceso a una prioridad identificado como <em>id_prioridad</em>
     *  que pertenece a la area de espera del parametro implicito.
    */
    void alta_proceso_espera(string id_prioridad, const Proceso &job);

    /** @brief Modificadora que envia n procesos (eligidos tienendo en cuenta el orden de 
     * prioridad. En una prioridad, los más antiguos) de una area de espera a un cluster.
     * Si no hay espacio, entonces el proceso es rechazado y devuelto a la area de espera original.
     * \pre n >= 0.
     * \post Se han enviado los n procesos de la area de espera del parametro implicito a 
     * los procesadores del cluster del parametro <em>c</em> y se ha actualizado en la area
     *  de espera el numero de procesos acceptados y rechazados en las prioridades correspondentes.
    */
    void enviar_procesos_cluster(int n, Cluster &c); 

    //Lectura y Escriptura
    
    /** @brief Operacion de escriptura de una prioridad.
     * \pre Existe una prioridad identificada como <em>id_prioridad</em> en la area de espera
     *  del parametro implicito.
     * \post Se han escrito los procesos pendientes de dicha prioridad por orden decreciente
     *  de antiguedad desde su ultima alta y el numero de procesos enviados al cluster, juntamente
     *  con el numero de procesos rechazado por el cluster.
    */
    void imprimir_prioridad(string id_prioridad) const;

    /** @brief Operacion de escriptura de la area de espera.
     * \pre <em>cierto</em>
     * \post Se han escrito los procesos pendientes de todas las prioridad de la area de espera
     *  del parametro implicito por orden decreciente de antiguedad desde su ultima alta y 
     *  el numero de procesos enviados al cluster de cada prioridad, juntamente con el numero
     *  de procesos rechazado por el cluster.
    */
    void imprimir_area_espera() const;


    private:

};


#endif