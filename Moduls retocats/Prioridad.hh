/** @file Prioridad.hh
    @brief Especificación de la clase Prioridad.
*/

#ifndef PRIORIDAD_HH
#define PRIORIDAD_HH

#include "Proceso.hh"

/** @class Prioridad
 *  @brief Esta clase hace referencia a una prioridad, un contenedor de procesos con una 
 *  etiqueta formado por un string. Dispone de un conjunto de operaciones que permite anadir
 *  y eliminar procesos de una prioridad. Permite consultar el proceso mas antiguo, el numero
 *  de procesos acceptados y rechazados, el numero de procesos pendientes, si existe un proceso
 *  concreto. Por ultimo dispone de una operacion de escriptura que imprime todos los procesos
 * de una prioridad.
*/
class Prioridad {

    public:

    // Constructoras

    /** @brief Creadora por defecto
     * 
    * \pre <em>cierto</em>
    * \post El resultado es una prioridad identificado como el parametro <em>id_prioridad</em>
    *  sin procesos.
    */
    Prioridad (string id_prioridad);

    // Modificadora

    /** @brief Modificadora que anade un proceso a la prioridad.
    * \pre <em>cierto</em>
    * \post El resultado es la prioridad original con un proceso nuevo <em>job</em>.
    */
    void alta_proceso_prioridad (const Proceso &job);

    /** @brief Modificadora que actualiza los procesos aceptados y rechazados en una prioridad.
    * \pre <em>aceptados</em> >= 0, <em>rechazados</em> >= 0
    * \post Se ha actualizado la cantidad de procesos aceptados y la cantidad de procesos rechazados.
    */
    void modificar_acceptados_rechazados(int aceptados, int rechazados);

    /** @brief Modificadora que elimina el proceso mas antiguo.
    * \pre Existe al menos un proceso en la prioridad del parametro implicito.
    * \post Se ha eliminado el proceso más antiguo de la prioridad parametro implicito.
    */
    void baja_mas_antiguo();

    // Consultoras

    /** @brief Consultora del proceso mas antiguo de una prioridad.
    * \pre Existe al menos un proceso en la prioridad del parametro implicito.
    * \post El resultado es el proceso más antiguo de la prioridad del parametro implicito.
    */
    Proceso consulta_mas_antiguo();

    /** @brief Consultora de procesos aceptados.
    * \pre <em>cierto</em>
    * \post El resultado es la cantidad de procesos aceptados de la prioridad del parametro
    * implicito.
    */
    int consultar_aceptados () const;

    /** @brief Consultora de procesos rechazados de una prioridad
    * \pre <em>cierto</em>
    * \post El resultado es la cantidad de procesos rechazados de la prioridad del parametro
    * implicito.
    */
    int consultar_rechazados () const;

    /** @brief Consultora del numero de procesos de una prioridad.
    * \pre <em>cierto</em>
    * \post El resultado es la cantidad de procesos en espera en la prioridad del parametro implicito.
    */
    int tamano () const;

    /** @brief Consultora de existencia de un proceso.
     * \pre <em>cierto</em>
     * \post El resultado indica si existe un proceso con identificador <em>id_proceso</em>
     *  en la prioridad del parametro implicito.
    */
    bool existe_proceso (string id_proceso) const;

    //Escriptura

    /** @brief Operacion de escriptura de una prioridad.
    * \pre <em>cierto</em>
    * \post Se escribe por el canal de salida los procesos de la prioridad del parametro 
    * implicito por orden decreciente de antiguedad y el numero de procesos aceptados y 
    * rechazados de esta misma prioridad.
    */
    void imprimir_procesos () const;


    private:

};

#endif