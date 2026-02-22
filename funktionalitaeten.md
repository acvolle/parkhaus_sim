Zusammenfassung und Gruppierung der notwendigen Funktionen und Strukturen

Funktionalitätsgruppen:

User-Interface:
-	Eingabe der Einstellungen
-	Ausgabe der Statistiken

Parkhaus:
-	Array aus Fahrzeugen
-	Auto einfügen
-	Anzahl der geparkten Autos zurückgeben
-	Ist noch Platz frei?
-	Aktualisieren (Autos, dessen verbleibende Parkdauer 0 ist, entfernen)

Operationen:
-	Neues Auto generieren, in die Queue einordnen
-	Auto aus Warteschleife in Parkhaus überführen wenn Platz ist
-	Statistiken sammeln
-	Struct Auto?

Queue Warteschlange (dynamischer Speicher!):
-	Enqueue
-	Dequeue
-	Ist Leer?

Auto einparken: zufallszahl generieren

Ablauf:
User Abfragen
Struct Parkhaus erzeugen
Beginn for loop:
- Autos überprüfen, wenn nötig ausparken
- Zufallszahl: wenn nötig auto generieren
- Auto einparken (in parkhaus ODER in queue)
