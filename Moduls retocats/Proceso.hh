/** @file Proceso.hh
    @brief Especificación de la clase Proceso.
*/

#ifndef PROCESO_HH
#define PROCESO_HH

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Proceso
    @brief Clase de proceso, hace referencia a tareas que tienen un identificador, memoria
    requierida y tiempo de ejecución. Dispone de operaciones para consultar cada datos de
    un proceso. Permite leer y escribir los datos de cada proceso.
*/
class Proceso {

    public:

    //Constructoras

    /** @brief Creadora por defecto.
    * \pre <em>cierto</em>
    * \post El resultado es un proceso vacio, sin datos especificados.
    */
    Proceso();

    //Modificadora

    /** @brief Modificadora que actualiza el estado del proceso.
    * \pre <em>t_procesador</em> >= 0
    * \post El resultado indica si el proceso ha terminado.
    */
    bool actualizar_proceso(int t_procesador);

    //Consultoras

    /** @brief Consultora del identificador de un proceso.
     * \pre El proceso del parametro implicito tiene un identificador especificado.
     * \post El resultado es el identificador del proceso del parametro implicito.
    */
    int consultar_id () const;

    /** @brief Consultora de tiempo de ejecución de un proceso.
     * \pre El proceso del parametro implicito tiene tiempo de ejecución especificado.
     * \post El resultado es el tiempo de ejecucion del proceso del parametro implicito.
    */
    int consultar_tiempo () const;

    /** @brief Consultora de tamano de un proceso.
     * \pre El proceso del parametro implicito tiene memoria requierida especificado.
     * \post El resultado es la memoria requerida del proceso del parametro implicito.
    */
    int consultar_tamano () const;

    //Lectura y escriptura

    /** @brief Operacion de lectura de un proceso.
     * \pre Hay en el canal de entrada el identificador del proceso, memoria que ocupa y 
     *  el tiempo de ejecucion.
     * \post El proceso del parametro implicito pasa a tener los datos especificados.
    */
    void leer();

    /** @brief Operacion de escriptura de un proceso.
     * \pre <em>cierto</em>
     * \post Se escribe por el canal de salida el identificador, memoria y el tiempo de 
     * ejecución del proceso del parametro implicito.
    */
    void imprimir() const;


    private:
    
};

#endif