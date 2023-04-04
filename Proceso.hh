/** @file Proceso.hh
    @brief Especificación de la clase Proceso.
*/

#ifndef PROCESO_HH
#define PROCESO_HH

#include <iostream>
using namespace std;

/** @class Proceso
    @brief Clase de proceso, hace referencia a tareas que tienen un identificador, memoria requierida y tiempo de ejecución.
*/
class Proceso {
    private:
    public:
    //Constructoras

    /** @brief Creadora por defecto
    * \pre <em>cierto</em>
    * \post El resultado es un proceso con el identificador, memoria y tiempo de ejecución correspondiente.
    */
    Proceso();

    //Consultoras
    /** @brief Consultora de tiempo de ejecución.
     * \pre El proceso del parametro implicito tiene tiempo de ejecución especificado.
     * \post El resultado es el tiempo de ejecucion del proceso del parametro implicito.
    */
    int consultar_tiempo () const;


    //Lectura y escriptura
    /** @brief Operacion de lectura.
     * \pre Hay en el canal de entrada el identificador del proceso, memoria que ocupa y el tiempo de ejecucion.
     * \post El proceso del parametro implicito pasa a tener los datos especificados.
    */
    void leer();

    /** @brief Operacion de escriptura.
     * \pre <em>cierto</em>
     * \post Se escribe por el canal de salida el identificador, memoria i el tiempo de ejecución del proceso del parametro implicito.
    */
    void imprimir() const;
    
};

#endif