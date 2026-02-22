### Zusammenfassung und Gruppierung der notwendigen Funktionen und Strukturen

### Funktionalitätsgruppen:

##### User-Interface:

* Eingabe der Einstellungen (auf gültige Eingaben überprüfen!)

&nbsp;	Anzahl von Stellplätzen

&nbsp;	Maximale Parkdauer

&nbsp;	Simulationsdauer (Zeitschritte)

&nbsp;	Ankunftswahrscheinlichkeit neuer Fahrzeuge in %

&nbsp;	Zufalls-Seed für reproduzierbare Simulationen

* Ausgabe der Statistiken

##### Struct Car:

 	id (unique)

 	Wartezeit in der Queue (durchlaufene Zyklen ab Ankunft bis Einfahrt)

 	verbleibende Parkdauer (wird beim Einfahren zugewiesen und jeden Zyklus reduziert)

##### Struct Parkhaus:

* Array von Cars

##### Queue Warteschlange (dynamischer Speicher!):

* Enqueue
* Dequeue
* Ist Leer?

##### Operationen:

* Auto einfügen
* Anzahl der geparkten Autos zurückgeben
* Ist noch Platz frei?
* Aktualisieren (Autos, dessen verbleibende Parkdauer 0 ist, entfernen)
* Neues Auto generieren, in die Queue einordnen
* Auto aus Warteschleife in Parkhaus überführen wenn Platz ist
* Statistiken sammeln
