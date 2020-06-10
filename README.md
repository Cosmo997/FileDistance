# FileDistance<br>
Progetto Laboratorio di Sistemi Operativi<br>
Giugno/Luglio 2020<br>
La ​ distanza di edit è una funzione che consente di verificare quanto due stringhe (o
sequenze di byte) siano ​ lontane ​ una dall’altra.<br>
Questa distanza viene calcolata sulla base del numero di operazioni necessarie a trasformare una stringa nell’altra. Le operazioni sono:<br>
● Aggiungere un carattere/byte;<br>
● Eliminare un carattere/byte;<br>
● Modificare un carattere/byte.<br>
Per calcolare la distanza di edit è possibile utilizzare l’algoritmo di ​ Wagner–Fischer.
Il programma ​ filedistance
Occorre realizzare il programma ​ filedistance ​ che implementa le seguenti funzionalità:<br>
1. Calcolo della distanza tra due file:<br> 
​ dati due file ​ f1 e ​ f2 ​ , il programma produce in
output la distanza tra ​ f1 ed ​ f2 ​ . Opzionalmente, il programma potrà anche generare la
minima sequenza di operazioni necessarie per trasformare ​ f1 in ​ f2 ​ . Tale sequenza
viene rappresentata attraverso una sequenza di istruzioni:<br>
a. ADD​ nb ​ : n è un intero senza segno (unsigned int) rappresentato con 4 byte
(byte più significativo all’inizio) mentre ​ b è un singolo byte. Tale operazione
indica che viene aggiunto il byte ​ b n
ella posizione ​ n ​ .<br>
b. DEL​ n : ​ n è un intero senza segno (unsigned int). Tale operazione indica che
viene eliminato il byte​ n
ella posizione ​ n . ​<br>
c. SET​ nb ​ : n è un intero senza segno (unsigned int) rappresentato con 4 byte
mentre ​ b è un singolo byte. Tale operazione indica che valore del byte in
posizione ​ n ​ viene impostato a ​ b.<br>
Queste istruzioni potranno essere salvate in un file per successive elaborazioni. I
valori ADD, DEL e SET vengono salvati in binario con i byte corrispondenti alle
lettere. Inoltre le istruzioni devono apparire in ordine.<br>
2. Applicazione delle modifiche ad un file:<br>
​ dato un file ​ f1 contenente ed un file da
elaborare ed un file ​ m contenente la lista di ​ modifiche da apportare ​ (secondo il
formato descritto sopra) ​ produce in output un file ​ f2 o
ttenuto da ​ f1 ​ applicando le
modifiche indicate in ​ m.<br>
3. Ricerca di file:<br>
​ dato un file ​ f ​ ed una directory ​ d viene restituito l’insieme dei file a
distanza ​ minima ​ da ​ f ​ .Opzioni del programma
Per poter eseguire le funzionalità descritte sopra il programma potrà essere eseguito con le
seguenti opzioni:
Calcolo distanza tra file:<br>
filedistance ​ ​ distance file1 file2<br>
filedistance distance file1 file2 output<br>
Nel primo caso, dove vengono passati come argomenti i due file da confrontare, viene
calcolata la distanza dal file e generato un output della seguente forma:<br>
EDIT DISTANCE: ​ distanza<br>
TIME: ​ tempo di calcolo<br>
Nel secondo caso, invece, verranno salvate nel file ​ output la sequenza delle istruzioni
necessarie per trasformare il primo file nel secondo.<br>
Applicazione delle modifiche:<br>
filedistance apply inputfile filem outputfile<br>
Applica a ​ inputfile l ​ e modifiche contenute nel file ​ filem ​ e salva il risultato nel file ​ outputfile ​ .<br>
Ricerca di file:<br>
filedistance ​ ​ search inputfile dir<br>
Restituisce in output i file contenuti in ​ dir ​ (e nelle sue sottodirectory) che hanno minima
distanza da ​ inputfile . ​ Il path assoluto di ogni file viene presentato in una riga dello ​ standard
output.<br>
filedistance ​ ​ searchall inputfile dir limit<br>
Vengono restituiti in output tutti i file contenuti in dir (e nelle sue sottodirectory) che hanno
una distanza da ​ inputfile ​ minore o uguale di ​ limit ​ (che è un intero). I file vengono presentati
nello standard output in ordine crescente secondo il seguente formato:<br>
distanza pathassolutofileConsegna<br>
Il progetto dovrà essere consegnato nell’archivio ​ NomeCognomeMatricola.zip c ​ ontenente la
singola cartella ​ NomeCognomeMatricola ​ con al suo interno:<br>
● La relazione in pdf che descrive l’implementazione svolta e le strutture dati utilizzate;<br>
● I sorgenti con gli script CMake o Makefile necessari alla compilazione.<br>
Valutazione<br>
La valutazione del progetto verrà effettuata tenendo conto di:<br>
● Qualità del codice e della sua organizzazione;<br>
● Tipologia delle strutture dati utilizzate;<br>
● Coerenza del codice con le specifiche date;<br>
● Capacità del programma di gestire file di dimensioni differenti:<br>
○ Base: fino ad un massimo di 100 byte;<br>
○ Media: fino ad un massimo di 1000 byte;<br>
○ Alta: fino ad un massimo di 10000 byte.<br>
● Qualità della relazione scritta.


FILE prova1 = File che spinge il test verso la parte superiore della tabella
FILE prova2 = File che spinge il test verso la parte sinistra della tabella
FILE prova3 = File di grandi dimensioni
FILE prova4 = File di piccole dimensioni
FILE prova5 = File che testa n add in posizioni diverse