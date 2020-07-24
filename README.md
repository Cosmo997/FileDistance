# FileDistance

### Relazione Sistemi Operativi Laboratorio Anno 2019-2020

### Sommario

- Descrizione del progetto

- Funzionalità

- Librerie Principali e Relative responsabilità

- Strutture Dati Utilizzate

- Levensthin

- Modularità

### Descrizione del Progetto

Il progetto FileDistance è un'applicazione scritta in c che consente all'utente di calcolare la distanza di edit a uno o più file.

La ​ distanza di edit è una funzione che consente di verificare quanto due stringhe (o
sequenze di byte) siano lontane una dall’altra. Questa distanza viene calcolata sulla base del numero di operazioni necessarie a trasformare una stringa nell’altra. 

Le operazioni sono:

- Aggiungere un carattere/byte;

- Eliminare un carattere/byte;

- Modificare un carattere/byte.

### Funzionalità

Le funzionalità sono 5;

- ./filedistance ​distance file1 file2

Il programma stampa la distanza di edit tra i due file e il tempo impiegato per calcolarla.

- ./filedistance distance file1 file2 output

Il programma stampa la distanza di edit tra i due file, il tempo impegato per calcolarla e scrive sul file output le istruzioni in binario.

- ./filedistance apply file1 filem output

Il programma applica al file1 le modifiche scritte nel filem e le sovrascrive al file output

- ./filedistance search file1 dir

Restituisce in output i file contenuti in ​dir (e nelle sue sottodirectory) che hanno minima distanza da inputfile .​Il path assoluto di ogni file viene presentato in una riga dello standard output.

- ./filedistance searchAll inputfile dir limit

Vengono restituiti in output tutti i file contenuti in dir (e nelle sue sottodirectory) che hanno una distanza da ​inputfile minore o uguale di ​limit. I file vengono presentati nello standard output in ordine crescente secondo il seguente formato:

distanza pathassolutofile

### Librerie

##### file_distance.h

La libreria file_distance.h è il cuore del progetto, la libreria centrale che utilizzando le varie librerie fornisce le informazioni richieste. Al suo interno sono presenti 5 metodi che vanno a richiamare funzioni in file_modifier.h, leven.h e finder.h

##### file_handler.h

La libreria file_handler.h ha come scopo principale quelli di eseguire operazioni su file, i due metodi principali sono changesApply che va a leggere da file le istruzioni dal filem e le applica al file in ingresso, e getStringFromFile che, dato un file, prende il suo contenuto e lo inserisce in una stringa.

##### finder.h

La libreria finder.h si occupa delle operazioni tra le varie cartelle, e applica levensthein ai vari file, inoltre contiene anche la lista concatenata che contiene le informazioni ricavate dai vari file e cartelle.

##### linked_list.h

La libreria linked_list.h ha al suo interno una lista concatenata contenente la posizione, il carattere ed il tipo di istruzione da eseguire.

##### leven.h

La libreria leven.h contiene l'algoritmo di Levensthein che permette di calcolare la distanza di edit. Le due funzioni presenti consentono di trovare la distanza di edit e oltre ad essa anche di scrivere le istruzioni da utilizzare su file.

##### timer.h

La libreria timer.h contiene 3 metodi che consentono di misurare i secondi impiegati per svolgere l'algoritmo.

### Strutture Dati Utilizzate

##### LinkedList

Per memorizzare le istruzioni ho implementato una LinkedList contenente un enum che rappresenta il tipo di istruzione, la posizione dove andrà applicata, il carattere ed il puntatore al nodo successivo.

```c
/**
 * Enum contenente il tipo di istruzione
 */
typedef enum {
    SET,
    ADD,
    DEL,
} IstructionType;

/**
 * Lista concatenata contenete l'istruzione, la posizione e il carattere da utilizzare
 */
typedef struct list{
    IstructionType type;
    unsigned int pos;
    char character;
    struct list *next;
    }LinkedList;

```

##### ScanData

Per il salvataggio dei path e delle relative distanze ho utilizzato un'altra lista concatenata così strutturata:

```c
/**
 * Struct contenente path, distanza e puntatore al nodo successivo della lista.
 */
struct ScanData{
    /**
     * Path del file
     */
    char *path;
    /**
     * distanza del file dal file in input
     */
    int distance;
    /**
     * Punatore all'elemento successivo
     */
    struct ScanData *next;
};
typedef struct ScanData ScanData;
```

### Levensthein

Nella mia implementazione dell'algoritmo di Levenshtein ho utiizzato una due metodi simili che producono una matrice dinamica e la compilano seguendo i parametri dell'algoritmo di Levenshtein inserendo nella casella della matrice il minimo tra i valori presenti nelle tre celle adiacenti alto - diagonale sinistra - sinistra.

Per riempire la matrice ho utilizzato il metodo fillMatrix:

```c
int ** fillMatrix(int **matrix, char *toModify, int nrighe, char *finalResault, int ncolonne)
{
   int costo = 0;
    for ( int i = 1; i < nrighe; i++)
    {
        for ( int j = 1; j < ncolonne; j++)
        {
            if (toModify[i - 1] == finalResault[j - 1])
                costo = 0;
            else
                costo = 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + costo);

        }
    }
    return matrix;
}
```

La differenza tra i due metodi sta nel "tragitto" che levensthein_distance_out va a tracciare per ricostruire le istruzioni di edit che verranno poi applicate al primo file per essere poi trasformato nel secono.

Per la ricerca delle istruzioni ho utilizzato un metodo ricorsivo recFind.

```c
void recFind(int ** matrix, MaxHeap * hp, int riga, int colonna, char * toModify, char * finalResault)
{   
    if (matrix[riga][colonna] != 0)
    {   
        if(riga -1>=  0 && colonna-1>= 0)
        {
        int app = min(matrix[riga][colonna-1],matrix[riga-1][colonna-1],matrix[riga-1][colonna]);
        if(matrix[riga -1 ][colonna - 1] == app)
        {
            // ! SET
            if(matrix[riga][colonna] != matrix[riga-1][colonna-1])
            {
            pushIstruction(hp, SET, colonna-1, finalResault[riga-1]);
                printf("\nSET%d%c",colonna - 1,finalResault[riga-1]);
            }
            recFind(matrix, hp, riga - 1, colonna -1,toModify, finalResault);
        }
        else if (matrix[riga][colonna -1] == app && colonna-1 >= 0)
        {
            // ! ADD
            pushIstruction(hp, ADD, riga-1, finalResault[riga-1]);
            printf("\nADD%d%c",riga-1,finalResault[riga-1]);
            recFind(matrix, hp, riga, colonna-1, toModify, finalResault);
        }
        else if(matrix[riga-1][colonna] == app && riga-1 >= 0)
        {
            // ! DEL
            pushIstruction(hp, DEL, colonna,'-');
            printf("\nDEL%d", colonna);
            recFind(matrix, hp, riga-1, colonna, toModify, finalResault);
        }


        }
        else if (riga - 1 < 0)
        {
            // ! ADD
            pushIstruction(hp, ADD, riga-1, finalResault[riga-1]);
            printf("\nADD%d%c",riga-1,finalResault[riga-1]);
            recFind(matrix, hp, riga, colonna-1, toModify, finalResault);
        }
        else if (colonna - 1 < 0)
        {
            // ! DEL
            pushIstruction(hp, DEL, colonna,'-');
            printf("\nDEL%d", colonna);
            recFind(matrix, hp, riga - 1, colonna, toModify, finalResault);
        }
        else return;
    }
    else return;
}
```

Per ottimizzare il costo computazionale dell'algoritmo di Levensthein ho aggiunto il metodo complexityReduction che si occupa di cancellare le ultime lettere di ogni stringa in caso risultino uguali, sviluppando così una matrice più piccola, con conseguente riduzione dell'uso memoria e di processore.

```c
void complexityReduction(char *stringa1, char *stringa2)
{
    if(stringa1[strlen(stringa1)-1] == stringa2[strlen(stringa2)-1])
    {
        stringa1[strlen(stringa1)-1] = 0;
        stringa2[strlen(stringa2)-1] = 0;
        complexityReduction(stringa1, stringa2);
    }
    else return;
}
```

### Modularità

Il programma è basato su 3 moduli fondamentali utilizzati dalla libreria "file_distance.h".

Il primo modulo è "leven.h", una libreri a che consente di applicare l'algoritmo di Leven in due modi: il primo genera solamente una matrice e la va a riempire in modo tale da ottenere la distanza di edit delle due stringhe, mentre il secondo consente anche di avere la sequenza di istruzioni necessarie per trasformare il primo file nel secondo.

Il secondo modulo è "file_modifier.h", una libreria che raggruppa tutte le operazioni che si andranno ad eseguire nei file.

Il terzo modulo è "finder.h", questa libreria si occupa di gestire l'applicazione dei vari metodi di leven sulla directory corrente e le sue sottodirectory, salvando le informazioni ricevute dai vari leven in una lista concatenata.

### Fonti

[Direcory]([C program to list all files in a directory recursively - Codeforwin](https://codeforwin.org/2018/03/c-program-to-list-all-files-in-a-directory-recursively.html))

[AddCharacter]([c - How to append a char at a defined position - Stack Overflow](https://stackoverflow.com/questions/54632455/how-to-append-a-char-at-a-defined-position))

[ReadString]([How to read the content of a file to a string in C? - Stack Overflow](https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c))

[BubbleSort]([C Program for Bubble Sort on Linked List - GeeksforGeeks](https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/#:~:text=of%20the%20array-,C%20Program%20for%20Bubble%20Sort%20on%20Linked%20List,sort%20it%20using%20bubble%20sort.&text=struct%20Node%20*start%20%3D%20NULL%3B,from%20the%20array%20arr%5B%5D.))

[Timer]([windows - How do I measure time in C? - Stack Overflow](https://stackoverflow.com/questions/3557221/how-do-i-measure-time-in-c))

[Base per EditPath]([python - Minimum Edit Distance Reconstruction - Stack Overflow](https://stackoverflow.com/questions/10638597/minimum-edit-distance-reconstruction))