# lista della spesa
Elaborato per esame di laboratorio di programmazione
- in data 13/11/2025 sono state aggiunte le prime classi
Observer.h e Subject.h

- in data 13/11/2025 sono state poi aggiunte anche le
classi:
1) DataDiScadenza.h, utilizzata per tenere traccia 
della data in cui un oggetto scade, con con uso di eccezioni
in caso di data non valida. 
2) Oggetto.h e Oggetto.cpp che creano  l'oggetto che può 
essere inserito in una lista della spesa e acquistato, con
nome, quantità acquistata, categoria dell'oggetto e data
di scadenza.
- in data 13/11/2025 sono state aggiunte altre due classi:
1) Lista.h e Lista.cpp che creano una lista della spesa e doce
si definiscono i metodi per aggiungere e rimuovere oggetti,
aggiornare la quantità che si vuole acquistare per quell'oggetto,
e metodi per ottenere informazioni sulla lista, ad esempio
il numero di oggetti che ci sono e quanti devono essere 
ancora acquistati.
2) Inoltre è stata modificata la classe Oggetto.h con l'aggiunta
di un costruttore di default che risulta necessario nell'uso
della std::map per aggiungere l'oggetto alla lista.
