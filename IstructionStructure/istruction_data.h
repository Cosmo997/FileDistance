#ifndef struct_h
#define struct_h

/**
 * Sotto-Struttura contenente le informazioni delle istruzioni che saranno utilizzate per apportare modifiche al file.
 */
struct istructionDataNode
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

/**
 * Enum contenente il tipo di modifica da apportare.
 */
typedef enum {ADD, DEL, SET} IstructionType;

typedef struct istructionDataNode IstructionDataNode;

#endif