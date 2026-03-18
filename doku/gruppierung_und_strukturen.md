### Zusammenfassung und Gruppierung der notwendigen Funktionen und Strukturen

### Funktionalitätsgruppen:
##### Globale Variable
* current_timestep
  
##### Simulationsfunktionen
* Zusammenführung der Einzelnen Car- und Parkhausbezogenen Funktionen, um einen Simulationsschritt auszuführen
  
##### Queue Warteschlange (dynamischer Speicher!):
* Enqueue
* Dequeue
* Ist Leer?
  
##### User-Interface:
* Eingabe der Einstellungen (auf gültige Eingaben überprüfen!)
  - Anzahl von Stellplätzen
  - Maximale Parkdauer
  - Simulationsdauer (wie viele Zeitschritte)
  - Ankunftswahrscheinlichkeit neuer Fahrzeuge in %
  - Zufalls-Seed

* Ausgabe der Statistiken

* Schreiben der Statistiken in txt Datei

### Strukturen
##### Struct Car:
* id (unique)
* Einfahrtszeit
* Wartezeit in der Queue (durchlaufene Zyklen ab Ankunft bis Einfahrt)
* verbleibende Parkdauer (wird beim Einfahren zugewiesen und jeden Zyklus reduziert)

##### Struct Parkhaus:
* Array von pointern auf Cars der Größe \[Anzahl von Parkplätzen]
* Anzahl an Stellplätzen
* Anzahl der besetzten Stellplätze

##### Struct Config:
* Space count
* max parking duration
* Sim Dauer
* Ankunftswahrscheinlichkeit
* seed

##### Struct Stats:
* Aktuelle Auslastung Parkhaus (% und absolut)
* Aktuell wartende Autos
* durchschn. Wartezeit in der Schlange (Durchschnitt der aktuellen Elemente der Queue)
* maximale Wartezeit in der Schlange aktuell
* Stress Score

### Ablauf des Programms
##### Operationen vor Simulation:
* Textdatei (für Statistik-Log) öffnen
* Simulationsparameter abfragen
* Parameter in Textdatei schreiben
* Queue initialisieren
* Parkhaus generieren

##### Operationen je Zeitschritt (Simulation):

* Autos, dessen verbleibende Parkdauer 0 ist, entfernen
* Auto aus Warteschleife in Parkhaus überführen wenn Platz ist
* Neues Auto generieren
  - Queue vorhanden -> in Queue einreihen (hinten dran)
  - else if Parkhaus voll -> in Queue einreihen (pos.1)
  - else -> einparken

* Statistiken berechnen, ausgeben und in Textdatei schreiben

##### Operationen nach Simulation:

* finale Statistik ausgeben
* Textdatei schließen
* allokierten Speicher freigeben
* return 0
