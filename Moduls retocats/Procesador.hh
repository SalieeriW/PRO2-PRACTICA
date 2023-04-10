/** @file Procesador.hh
    @brief Especificación de la clase Procesador.
*/

#ifndef PROCESADOR_HH
#define PROCESADOR_HH

#include "Proceso.hh"

/** @class Procesador
    @brief Clase de procesador, hace referencia a un procesador que puede ejercutar procesos.
    Dispone de operaciones para anadir o eliminar un proceso al procesador, compactar la memoria
    de un procesador, avanzar el reloj de un procesador. Tambíen permite hacer consultas sobre si
    un procesador está ocupado, la memoria disponible y la existencia de un proceso. Por ultimo,
    tiene operaciones de lectura y escriptura para leer los datos de un procesador y escribir
    los procesos de estos.
*/
class Procesador {

    public:

    //Constructoras

    /** @brief Creadora por defecto
     * Se crea un procesador vacio.
     * \pre <em>cierto</em>
     * \post El resultado es un procesador vacio.
    */
    Procesador();

    //Modificadoras

    /** @brief Modificadora que anade un proceso a un procesador.
     * \pre Hay memoria suficiente para que el proceso quepa.
     * \post El resultado indica si se ha podido anadir el proceso en el procesador, si se
     *  ha podido, el procesador original tendrá un nuevo proceso <em>job</em> en la posición
     *  de memoria donde quede más ajustado.
    */
    bool alta_proceso_procesador (const Proceso &job);

    /** @brief Modificadora que elimina un proceso de un procesador.
     * \pre Existe un proceso identificado como el parametro <em>id_job</em> en procesador
     *  del parametro implicito. 
     * \post Se ha eliminado el proceso con <em>id_job</em> del procesador del parametro implicito.
    */
    void baja_proceso_procesador (int id_job);

    /** @brief Modificadora que compacta la memoria de un procesador. 
     * \pre <em>cierto</em>
     * \post Se han colocado todos los procesos del procesador del parametro implicito al 
     * principio de la memoria, sin dejar huecos, ni solaparse entre ellos.
    */
    void compactar_memoria_procesador ();

    /** @brief Modificadora que avanza <em>t</em> unidades de tiempo del procesador del 
     * parametro implicito.
     * \pre t >= 0
     * \post Se ha añadido t unidades de tiempo al procesador del parametro implicito.
    */
    void avanzar_tiempo_procesador (int t);

    //Consultora

    /** @brief Consultora que indica si un procesador tiene procesos en ejecucion.
     * \pre <em>cierto</em>
     * \post El resultado indica si el procesador del parametro implicito tiene procesos 
     * en ejecucion
    */
    bool ocupado() const;

    /** @brief Consultora de existencia de un proceso en un procesador.
     * \pre <em>cierto</em>
     * \post El resultado indica si existe un proceso identificado como <em>id_proceso</em>
     *  en el procesador del parametro implicito.
    */
    bool existe_proceso(string id_proceso) const;

    /** @brief Consultora del tamaño del hueco más grande en la memoria de un procesador.
     * \pre <em>cierto</em>
     * \post El resultado indica el tamano del hueco más grande en el procesador del 
     * parametro implicito.
    */
    int max_espacio_actual() const;
    
    //Lectura y escriptura

    /** @brief Operacion de lectura del procesador.
     * \pre Hay en el canal de entrada el identificador del procesador y el tamano de memoria de este.
     * \post El procesador del parametro implicito pasa a tener el identificador y tamano especificado.
    */
    void configurar_procesador ();

    /** @brief Operacion de escriptura de los procesos.
     * \pre <em>cierto</em>
     * \post Se escribe por el canal de salida el identificador del procesador, seguidos de
     *  los procesos que se estan ejecutando con sus datos por orden creciente, empezando por
     *  la primera posición de memoria.
    */
    void imprimir_procesos() const;


    private:

};
#endif