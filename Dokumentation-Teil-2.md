# Dokumentation: Parkhaus-Simulation

## Vorgehensweise
### Vorarbeit
Nach Erhalt des ersten Teils der Aufgabenstellung wurde zunächst ein GitHub-Projekt erstellt und herausgearbeitet, welche Funktionen notwendig waren und wie sie funktionieren sollten.
Nachdem dies geklärt war, wurden im Kanban-Board die Tasks erstellt und bei Bedarf Änderungen eingetragen.
Welche Tasks wer übernommen hat, regelte sich über das Kanban-Board, wobei man sich die Tasks selbst zuteilen konnte.
Nachdem die grundlegenden Fragen geklärt waren – etwa welche Funktionen oder Statistiken benötigt wurden – und ein Repository auf Basis der Vorgaben mit den dazugehörigen Header-Dateien erstellt worden war, begann der Prozess des Pseudocode-Schreibens.

### Struktur
Es wurde beschlossen, das Projekt in die Module Car, Parking, Queue, Stats, UI, Simulation und main aufzuteilen. Diese Module stellen die grundlegenden Funktionen dar, die aufeinander aufbauen.
Car bildet dabei den Grundstein, da es Autos (car structs) definiert, generiert und löscht.
Darauf aufbauend definiert Parking das Parkhaus, dessen Erstellung, die Speicherung der Autos und dessen Löschung.
Queue nutzt ebenfalls car und speichert die Autos als Nodes in einer Liste, falls das Parkhaus voll ist.
Stats verwendet Queue, um eine Liste der Statistiken zu erstellen.
Simulation nutzt diese drei Module sowie die Nutzerinputs, um die eigentliche Simulation durchzuführen.
Die Nutzerinputs werden wiederum über UI abgefragt. Alle diese Funktionen werden in main aufgerufen.

### Code (src-Dateien)
Der Codierungsprozess führte diese Arbeitsweise fort (inklusive Kommentare zur Klärung). Es wurden Tasks erstellt, die wieder selbst zugeteilt werden konnten. Der Status wurde dabei im Kanban-Board festgehalten.
Für jede Task wurde ein eigener Branch erstellt.
Die jeweils anderen beiden Mitglieder kontrollierten, ob der hinzugefügte Code korrekt war. Bei Problemen wurden Kommentare mit Änderungswünschen abgegeben. Falls sich Mängel im Code zeigten, wurde eine neue Task erstellt, die die Probleme benannte.

### Tests
Die Tests wurden, wie vorgegeben, mit assert durchgeführt. Dabei wurden alle Funktionen der jeweiligen src-C-Dateien überprüft – und zwar, ob sie die korrekten Ausgaben für die korrekten Eingaben lieferten. Diese Tests sollten ebenfalls kommentiert sein, um zu erkennen, welche Szenarien getestet wurden.
Statische Funktionen wurden getestet, indem für sie nicht-statische Funkttionswrapper erstellt wurden.

### Main
Der Zusammenschluss der einzelnen Elemente und der Test in Main bildeten den letzten Teil der Codierungsarbeit. Dabei zeigten sich noch einmal verbleibende Fehler oder Unstimmigkeiten innerhalb des Codes und der Header-Dateien, die korrigiert wurden.

## 






