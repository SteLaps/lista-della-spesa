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
ancora acquistati; inoltre la Lista lavora come Concrete
Subject nel pattern Observer.
2) Inoltre è stata modificata la classe Oggetto.h con l'aggiunta
di un costruttore di default che risulta necessario nell'uso
della std::map per aggiungere l'oggetto alla lista.
- in data 14/11/2025 sono state aggiunte due nuove classi:
1) Utente.h e Utente.cpp che identificano un utente che può
creare una lista della spesa e ci può aggiungere e rimuovere 
oggetti; inoltre l'Utente lavora come Concrete Observer
nel pattern Observer.
- in data 16/11/2025 è stato corretto un errore presente nella 
classe DataDiScadenza.h che non faceva andare in modo corretto 
lo unit test sulla creazione di un oggetto; il fatto era che
nella classe non erano state inizializzate le variabili private,
cosa che ha portato a fornire dei numeri casuali una volta
lanciato il debug sul test per la creazione di un oggetto.
Inoltre, è stata modificata la data nella condizione per
poter considerare validi anche oggetti acquistati e creati
nel 2025; il file testOggetto.cpp sarà terminato per il
prossimo commit.
- in data 16/11/2025 è stata completato il file testOggetto.cpp
che testa i vari metodi del file Oggetto; ogni test è stato eseguito
dopo la sua creazione e tutto hanno dato esito positivo.
- in data 18/11/2025 sono state apportete alcune modifiche al codice
nei file Oggetto.h, Oggetto.cpp e testOggetto.cpp dove alcune categorie
di oggetti acquistabili sono state cambiate per via del mancante
senso logico che la data di scadenza avrebbe avuto per questi categorie
di oggetti. Inoltre, è stata aggiunta un nuovo file, testLista.cpp, che
fornisce i test per le varie operzioni possibili su una lista; ogni test,
dopo essere stato implementato, è stato eseguito e ognuno è andato a buon
fine.