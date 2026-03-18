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

## Umsetzung und Alternativen
Im Folgenden werden einige alternative Umsetzungsmöglichkeiten vorgestellt, die wir uns angeschaut haben. Zudem werden die Gründe genannt, warum wir uns letztendlich für die gewählte Umsetzung entschieden haben.
Wir haben einserseits unser Projekt insbesondere auf Modularität und Wartbarkeit optimiert um Flexibilität und Skalierbarkeit zu gewährleisten. Andererseits lag der Fokus auch auf Lesbarkeit und Robustheit des Codes, um zukünftige Anpassungen zu erleichtern.

### Modularisierung
Zu Beginn des Projekts war ein geringerer Grad der Modularisierung vorgesehen. So stand zur Diskussion, Stats und Simulation zu einem Modul zusammenzufassen oder deren Funktionalität auf main, Parkhaus, Queue und UI aufzuteilen. Dagegen sprach jedoch, dass möglichst wenig Funktionalität in main() untergebracht werden sollte.
Die hohe Modularisierung bietet hingegen den Vorteil, dass einzelne Source-Dateien kompakter und übersichtlicher sind. Dies vereinfacht nicht nur die Arbeitsteilung in kleinere Arbeitspakete, sondern auch die Wartung.

### "Call by Reference" und Funktionsrückgabewerte
Viele der implementierten Funktionen müssen mit einem Pointer als Input aufgerufen werden ("Call by Reference"), da die Operationen direkt auf dem spezifischen Objekt ausgeführt werden müssten (z. B. dem Parkhaus).
Dieses Prinzip haben wir auch in anderen Funktionen eingesetzt, zu Beispiel bei dequeue(). Dort wird ein Pointer auf einen Pointer übergeben, und der Pointer wird dann auf die Adresse des aus der Queue entfernten Cars gesetzt. Die Rückgabe eines Pointers von dequeue wäre hier simpler. 
Im Team haben wir uns aber darauf geeinigt, als Rückgabewert einen Integer als status code festzulegen. Die Rückgabewerte sind somit differenziert (z. B. kann die Funktion zwischen einer leeren Queue ('1') und einem NULL-Pointer ('-1') unterscheiden) und über die verschiedenen Funktionen einheitlich.
Auch bei der run_timestep() Funktion sind die differenzierten Rückgabewerte sichtbar, dies dient dort vor allem der Fehlererekennung.

### Dynamische Allokation
Fast alle Strukturen der Simulation (mit Ausnahme der Queue selbst) werden dynamisch allokiert. Einige davon, wie Parkhaus und Config, hätten wie die Queue statisch in main initialisiert werden können. Dies hätte uns den Aufwand der dynamischen Speicherverwaltung und damit verbundene Probleme erspart.
Wir haben uns jedoch von Anfang an für die dynamische Allokation entschieden, um hinsichtlich der vielen Funktionsübergaben (siehe oben) möglichst viel Handlungsspielraum zu haben. Zudem sollten potenzielle Speicherprobleme von Projektbeginn an vermieden werden.

### Berechnung der finalen Statistiken
In unserer aktuellen Implementierung werden nur die aktuellen Statistiken in einer stats-Struktur gespeichert. Die finalen Statistiken werden erst am Ende der Simulation berechnet, indem alle Simulationsdaten aus der Log-Datei ausgelesen werden.
Eine alternative Option wäre gewesen, die finalen Statistiken (Durchschnitte und Maximalwerte) in jedem Simulationsschritt zu berechnen. Am Ende wäre das Ergebnis dasselbe.
Wir entschieden uns stattdessen für die erstgenannte Implementierung, da die Berechnung somit unabhängig vom Simulationsdurchlauf erfolgt. Dies gewährleistet eine höhere Modularisierung und einfachere Wartbarkeit des Programms. Diese Entscheidung zahlte sich später aus, als wir die Berechnung nachträglich ändern mussten, ohne den Code der eigentlichen Simulation anpassen zu müssen.

### Fortlaufende Car-ID
Jede Car-Struktur benötigt eine eindeutige ID. Da diese nicht zwingend fortlaufend sein muss, wurde erwogen, einfach den Zeitpunkt der Erstellung des Fahrzeugs als ID zu verwenden. Somit hätten wir uns eine globale Variable erspart.
Wir entschieden uns jedoch, eine statische, fortlaufende Variable current_car_id einzuführen. Dieser Ansatz bringt praktisch keinen Mehraufwand mit sich, macht den Code aber lesbarer und würde uns ermöglichen, mehrere Cars pro Zeitschritt zu generieren.

## Zusammenarbeit

### Schwierigkeiten und Herausforderungen
#### Arbeitsverteilung
Die Arbeitsverteilung war für unser Team eine Herausforderung, da das Bearbeiten von Aufgaben bei verschiedenen Teammitgliedern unterschiedlich gut funktioniert hat.
Bei der Bearbeitung der Aufgaben durch ein Teammitglied kam es häufiger zu Verzögerungen und Mängeln, sodass einerseits sehr detaillierte Code-Reviews der anderen Teammitglieder nötig waren, andererseits (durch die Verzögerung) Aufgaben umverteilt werden mussten, um eine rechtzeitige Abgabe zu ermöglichen.
Am Ende führte das zu einer starken Ungleichverteilung des Umfangs der Arbeit unter den Teammitgliedern, was am großen Unterschied in der Anzahl von Commits und Pull Requests zwischen den Teammitgliedern sichtbar wird.
Uns ist rückblickend dadurch klar geworden, dass wir Verantwortlichkeiten im Projekt nicht klar genug definiert haben und auch für den Umgang mit überschrittenen Deadlines keine konkrete Vorgehensweise im Voraus festgelegt hatten.
#### Reviewen von Pull-Requests
Die Möglichkeit, Feedback und Verbesserungsvorschläge einzubringen, wurde von den Teammitgliedern ebenfalls unterschiedlich stark genutzt. Teilweise kam es zu einem regen Austausch mit konstruktiven Verbesserungsvorschlägen („Request Changes“ mit Kommentaren bei Pull Requests), aber teilweise auch zu geringerer Beteiligung und Reviews ohne Kommentare.
Dies führte dazu, dass die Last der Qualitätssicherung ebenfalls ungleich verteilt war.

### Was gelungen ist
#### Task-Management
Als Task-Manager nutzten wir, wie vorgegeben, die in GitHub bereitgestellten Funktionen (Erstellen von Issues und Kanban-Board). Dieses Management wurde auch das gesamte Projekt über gut gepflegt. So konnte jedes Teammitglied jederzeit den Fortschritt der anderen und auch den Fortschritt des Gesamtprojekts nachverfolgen. Außerdem wurde hierdurch die Koordination der Aufgaben erleichtert, da jeder Issues erstellen und sich Issues zuordnen (assignen) konnte.
#### Qualitätssicherung
Wie schon oben teilweise angesprochen, wurden Pull Requests stets von den anderen Teammitgliedern reviewed, bevor diese in den Main-Branch gemerged wurden. Hier kam es oftmals zur Erkennung von Fehlern im Code, sodass diese sofort vom Ersteller des Pull Requests angepasst/korrigiert wurden und ein Mergen von fehlerhaftem Code in den meisten Fällen frühzeitig verhindert werden konnte.
Neben der Korrektur von Fehlern wurden dadurch immer wieder auch Vorschläge zur Optimierung der einzelnen Funktionalitäten sowie der Struktur des Gesamtprojekts eingebracht und anschließend auch realisiert.
Auch dass zum Zusammenfügen der Module und für den fehlerfreien Durchlauf der Unit-Tests nur sehr wenige Änderungen (insgesamt an 2–3 Stellen im Programm) nötig waren, zeigt die für unsere Verhältnisse hohe Qualität des Quellcodes (war überwiegend frei von Fehlern).
#### Austausch von Wissen
Die detaillierten Code-Reviews haben auch dazu geführt, dass wir den Code der anderen gesehen und verstanden haben. Immer wieder konnten durch den gegenseitigen Austausch das eigene Wissen und die Methodik beim Schreiben von Quellcode optimiert werden.
#### Einheitlichkeit
Wir haben uns bereits im Vorfeld über die Coding-Konventionen, den Aufbau der Funktions-Header, die Benennung von Funktionen und die Rückgabewerte von Funktionen geeinigt. Diese Abmachungen wurden auch stets eingehalten, was zur Übersichtlichkeit des Projekts und zum guten Zusammenspiel der Module beigetragen hat.
#### Merge-Konflikte
Durch die eigenständige Bearbeitung von Issues und Modulen konnten Merge-Konflikte durch Pull-Requests zum Zusammentragen der Arbeiten fast vollständig vermieden werden.




















