#include "istruction_data.h"

struct istructionData
{
    /**
     * Tipo di istruzione da apportare: ADD, SET o DEL
     */
    IstructionType istruction;
    /**
     * Unsigned int che indica la posizione in cui verrà apportata la modifica
     */
    unsigned int position;
    /**
     * Parametro utilizzato solamente nei metodi ADD e SET, che indica il nuovo valore che avrà la lettera nella posizione position
     */
    char letter;
};