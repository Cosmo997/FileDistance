#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_distance.h"

void help(void);


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        help();
    }
    if (strcasecmp(argv[1], "distance") == 0)
    {
        if (argc == 3)
        {
            help();
        }
        if (argc == 4)
        {
            distance(argv[2], argv[3]);
             
        }
        if (argc == 5)
        {
            distanceOutput(argv[2], argv[3], argv[4]);
        }
    }
    else if (strcasecmp(argv[1], "apply") == 0)
    {
        apply(argv[2], argv[3], argv[4]);
    }
    else if (strcasecmp(argv[1], "search") == 0)
    {
        search(argv[2], argv[3]);
        
    }
    else if (strcasecmp(argv[1], "searchAll") == 0)
    {
        searchAll(argv[2], argv[3], atoi(argv[4]));
    }
    else
    {
        help();
    }
}
void help()
{
    printf("\n\nLISTA COMANDI DISPONIBILI:\n\nfiledistance distance <file1> <file2>:\n\n\tRestituisce la distanza di Edit tra <file1> e <file2>.\n\nfiledistance distance <file1> <file2> <output>:\n\n\tRestituisce la distanza di Edit tra <file1> e <file2>, \n\tsalva nel file ​<output> la sequenza delle istruzioni\n\tnecessarie per trasformare il primo file nel secondo.\n\nfiledistance apply <inputfile> <filem> <outputfile>:\n\n\tApplica a <inputfile> le modifiche contenute in <filem>\n\te salva il risultato in <outputfile>\n\nfiledistance ​search <inputfile> <dir>:\n\n\tRestituisce in output i file contenuti in <​dir>(e nelle \n\tsue sottodirectory) che hanno minimadistanza da \n\t<inputfile>.Il path assoluto di ogni file viene \n\tpresentato in una riga dello ​standard output.\n\nfiledistance ​searchall <inputfile> <dir> limit:\n\n\tVengono restituiti in output tutti i file contenuti in \n\tdir (e nelle sue sottodirectory) che hanno una distanza \n\tda ​ inputfile ​ minore o uguale di ​ limit ​ (che è un \n\tintero). I file vengono presentati nello standard \n\toutput in ordine crescente secondo il seguente formato:\n\n\tdistanza <pathassolutofile>\n\n");
}
