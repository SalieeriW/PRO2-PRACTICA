/** @file Prioridad.hh
    @brief Especificación de la clase Prioridad.
*/

#ifndef PRIORIDAD_HH
#define PRIORIDAD_HH

#include "Proceso.hh"

/** @class Prioridad
 *  @brief Esta clase hace referencia a una prioridad, un contenedor de procesos con una etiqueta formado por un string que los une.
*/
class Prioridad {

    // Constructoras

    /** @brief Creadora por defecto
     * 
    * \pre <em>cierto</em>
    * \post El resultado es una prioridad identificado como el parametro id_prioridad sin procesos.
    */
    Prioridad (string id_prioridad);

    // Modificadora

    /** @brief Modificadora que añade un proceso a la prioridad.
    * \pre <em>cierto</em>
    * \post El resultado es la prioridad original con un proceso más (job).
    */
    void alta_proceso_prioridad (const Proceso &job);

    /** @brief Modificadora que actualiza los procesos aceptados y rechazados en una prioridad.
    * \pre aceptados >= 0, rechazados >= 0
    * \post Se ha actualizado la cantidad de procesos aceptados y la cantidad de procesos rechazados.
    */
    void modificar_acceptados_rechazados(int aceptados, int rechazados);

    /** @brief Modificadora que elimina el proceso mas antiguo.
    * \pre Existe al menos un proceso.
    * \post Se ha eliminado el proceso más antiguo del parametro implicito.
    */
    void baja_mas_antiguo();

    // Consultoras

    /** @brief Consultora del proceso mas antiguo.
    * \pre Existe al menos un proceso.
    * \post El resultado es el proceso más antiguo de la prioridad del parametro implicito.
    */
    Proceso consulta_mas_antiguo();

    /** @brief Consultora de procesos aceptados.
    * \pre <em>cierto</em>
    * \post El resultado es la cantidad de procesos aceptados.
    */
    int consultar_aceptados () const;

    /** @brief Consultora de procesos aceptados.
    * \pre <em>cierto</em>
    * \post El resultado es la cantidad de procesos rechazados.
    */
    int consultar_rechazados () const;

    /** @brief Consultora del numero de procesos.
    * \pre <em>cierto</em>
    * \post El resultado es la cantidad de procesos en espera en la prioridad del parametro implicito.
    */
    int tamano () const;

    /** @brief Consultora para saber si la prioridad es vacia.
    * \pre <em>cierto</em>
    * \post El resultado indica si la prioridad es vacia.
    */
    bool vacia () const;

    
    //Escriptura

    /** @brief Operacion de escriptura por defecto.
    * \pre <em>cierto</em>
    * \post Se escribe por el canal de salida los procesos de la prioridad del parametro implicito por orden decreciente de antiguedad y el numero
    * de procesos aceptados y rechazados de esta misma prioridad.
    */
    void imprimir_procesos () const;

};

#endif