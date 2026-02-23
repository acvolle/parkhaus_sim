### Zusammenfassung und Gruppierung der notwendigen Funktionen und Strukturen

### Funktionalitätsgruppen:

##### User-Interface:

* Eingabe der Einstellungen (auf gültige Eingaben überprüfen!)

 	Anzahl von Stellplätzen

 	Maximale Parkdauer

 	Simulationsdauer (wie viele Zeitschritte)

 	Ankunftswahrscheinlichkeit neuer Fahrzeuge in %

 	Zufalls-Seed

* Ausgabe der Statistiken

##### Struct Car:

 	id (unique)

 	Wartezeit in der Queue (durchlaufene Zyklen ab Ankunft bis Einfahrt)

 	verbleibende Parkdauer (wird beim Einfahren zugewiesen und jeden Zyklus reduziert)

##### Struct Parkhaus:

* Array von Cars der Größe \[Anzahl von Parkplätzen]

##### Queue Warteschlange (dynamischer Speicher!):

* Enqueue
* Dequeue
* Ist Leer?

##### Operationen vor Simulation:

* Textdatei (für Statistik-Log) öffnen
* Simulationsparameter abfragen
* Parameter in Textdatei schreiben
* Queue initialisieren
* Parkhaus generieren

##### Operationen je Zeitschritt:

* Autos, dessen verbleibende Parkdauer 0 ist, entfernen
* Auto aus Warteschleife in Parkhaus überführen wenn Platz ist
* Neues Auto generieren

&nbsp;	Queue vorhanden -> in Queue einreihen (hinten dran)

&nbsp;	else if Parkhaus voll -> in Queue einreihen (pos.1)

&nbsp;	else -> einparken

* Statistiken berechnen, ausgeben und in Textdatei schreiben

##### Operationen nach Simulation:

* (finale Statistik ausgeben ?)
* Textdatei schließen
* allokierten Speicher freigeben
* return 0
