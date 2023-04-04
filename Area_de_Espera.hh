/** @file Area_de_Espera.hh
    @brief Especificación de la clase Area de Espera.
*/

#ifndef AREA_DE_ESPERA_HH
#define AREA_DE_ESPERA_HH

#include "Prioridad.hh"

/** @class Area_de_Espera
 *  @brief Hace referencia a la area de espera de los procesos.
 *  Contiene procesos que se quieren tratar en el cluster classificados por prioridad.
 *  Puede usarse para crear o destruir una prioridad e insertar un nuevo proceso a la espera.
 * 
*/
class Area_de_Espera {

    public:

    // Constructoras

    /** @brief Creadora por defecto
     * Se ejecuta automáticamente al declarar una nueva area de espera.
     * \pre <em>cierto</em>
     * \post El resultado es una area de espera sin ningúna prioridad ni proceso.
    */
    Area_de_Espera();

    // Modificadoras

    /** @brief Modificadora que anade una nueva prioridad a la area de espera del parametro implicito.
     * \pre <em>cierto</em>
     * \post Se ha añadido una nueva prioridad identificado como id_prior a la area de espera del parametro implicito.
    */
    void alta_prioridad (string id_prioridad);

    /** @brief Modificadora que elimina una prioridad en la area de espera del parametro implicito.
     * \pre Existe una prioridad identificada como el parametro id_prioridad en la area de espera del parametro implicito. En caso que exista,
     * no puede tener procesos pendientes en ella.
     * \post Se ha eliminado la prioridad identificada como id_prior a la area de espera del parametro implicito.
    */
    void baja_prioridad (string id_prioridad);

    /** @brief Modificadora que anade un proceso a una prioridad de la area de espera del parametro implicito.
     * \pre Existe una prioridad con el identificador del parametro id_prioridad. No existe previamente un proceso
     *  con el mismo identificador en dicha prioridad.
     * \post Se ha anadido un proceso a una prioridad identificado como id_prioridad que pertenece a la area de espera del parametro implicito.
    */
    void alta_proceso_espera(string id_prioridad, const Proceso &job);

    /** @brief Modificadora que modifica la prioridad iessima de la area de espera del parametro implicito.
     * \pre Existe un numero i de prioridades en la area de espera del parametro implicito.
     * \post Se ha substituido la iesima prioridad inicial de la area de espera del parametro implicito por la prioridad del parametro.
    */
    void modificar_iessimo(int i, const Prioridad &prioridad);

    // Consultoras
    
    /** @brief Consultora de la iesima prioridad.
     * \pre Existe un numero i de prioridades en la area de espera del parametro implicito.
     * \post El resultado es la prioridad iesima de la area de espera del parametro implicito.
    */
    Prioridad consultar_iessimo(int i) const;

    //Lectura y Escriptura
    
    /** @brief Operacion de escriptura de una prioridad.
     * \pre Existe una prioridad identificada como id_prioridad en la area de esoera del parametro implicito.
     * \post Se han escrito los procesos pendientes de dicha prioridad por orden decreciente de antiguedad desde su ultima alta y 
     * el numero de procesos enviados al cluster, juntamente con el numero de procesos rechazado por el cluster.
    */
    void imprimir_prioridad(string id_prioridad) const;

    /** @brief Operacion de escriptura de la area de espera.
     * \pre <em>cierto</em>
     * \post Se han escrito los procesos pendientes de todas las prioridad de la area de espera del parametro implicito por orden
     *  decreciente de antiguedad desde su ultima alta y el numero de procesos enviados al cluster de cada prioridad, juntamente con
     *  el numero de procesos rechazado por el cluster.
     * 
    */
    void imprimir_area_espera() const;



    private:

};


#endif