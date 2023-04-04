/** @file Procesador.hh
    @brief Especificación de la clase Procesador.
*/

#ifndef PROCESADOR_HH
#define PROCESADOR_HH

#include "Proceso.hh"
#include <vector>

/** @class Procesador
    @brief Clase de procesador, hace referencia al procesador. Permite crear un procesador acompanado con su identificador. Permite realizar operaciones con los
    procesadores.
*/
class Procesador {
    private:

    public:
    //Constructoras

    /** @brief Creadora por defecto
     * Se crea un procesador vacio.
     * \pre <em>cierto</em>
     * \post El resultado es un procesador vacio.
    */
    Procesador();

    //Modificadoras

    /** @brief Modificadora anade un proceso al procesador del parametro implicito.
     * \pre Hay memoria suficiente para que el proceso quepa.
     * \post El resultado si se ha podido anadir el proceso en el procesador, si se ha podido, el procesador original tendrá un nuevo proceso job en la posición de memoria donde quede más ajustado.
    */
    bool alta_proceso_procesador (const Proceso &job);

    /** @brief Modificadora elimina un proceso al procesador del parametro implicito.
     * \pre Existe un proceso identificado como el parametro id_job en procesador del parametro implicito. 
     * \post Se ha eliminado el proceso con id_job del procesador del parametro implicito.
    */
    void baja_proceso_procesador (int id_job);

    /** @brief Modificadora que compacta la memoria del procesador del parametro implicito.
     * \pre <em>cierto</em>
     * \post Se han colocado todos los procesos al principio de la memoria, sin dejar huecos ni solaparse entre ellos.
    */
    void compactar_memoria_procesador ();

    /** @brief Modificadora que avanza t unidades de tiempo del procesador del parametro implicito.
     * \pre t >= 0
     * \post Se ha añadido t unidades de tiempo al procesador del parametro implicito.
    */
    void avanzar_tiempo_procesador (int t);
    
    //Lectura y escriptura
     /** @brief Operacion de lectura del procesador.
     * \pre Hay en el canal de entrada el identificador del procesador y el tamano de memoria de este.
     * \post El procesador del parametro implicito pasa a tener el identificador y tamano especificado.
    */
    void configurar_procesador ();

    /** @brief Operacion de escriptura de los procesos.
     * \pre <em>cierto</em>
     * \post Se escribe el identificador del procesador seguidos de los procesos, que se estan ejecutando con sus datos por orden creciente de primera posición de memoria, en el canal de salida.
    */
    void imprimir_procesos() const;


};
#endif