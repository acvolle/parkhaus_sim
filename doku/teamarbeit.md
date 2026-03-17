## Schwierigkeiten und Herausforderungen bei der Zusammenarbeit
### Arbeitsverteilung
Die Arbeitsverteilung war für unser Team eine Herausforderung, da die Aufgaben von
unterschiedlichen Teammitgliedern unterschiedlich gut funktioniert hat.
Bei der Bearbeitung der Aufgaben durch ein Teammitglied kam es häufiger zu 
Verzögerungen und Mängeln, sodass einerseits sehr detaillierte Code-Reviews der anderen
Teammitglieder nötig waren, aber auch (durch die Verzögerung) Aufgaben umverteilt werden
mussten, um eine rechtzeitige Abgabe möglich zu machen. 
Am Ende führte das zu einer starken Ungleichverteilung des Umfangs der Arbeit unter den
Teammitgliedern, was an dem großen Unterschied der Anzahl von Commits und Pull Requests
zwischen den Teammitgliedern sichtbar wird.
Uns ist rückblickend dadurch klar geworden, dass wir Verantwortlichkeiten im Projekt nicht
klar genug definiert haben und auch für den Umgang mit überschrittenen Deadlines keine
konkrete Vorgehensweise im Voraus festgelet hatten.

### Reviewen von Pull-Requests
Die Möglichkeit, Feedback und Verbesserungsvorschläge mit einzubringen, wurde von den 
Teammitgliedern ebenfalls unterschiedlich stark genutzt. Teilweise kam es zu einem
regen Austausch mit konstruktiven Verbesserungsvorschlägen ("Request Changes" mit Kommentaren
bei Pull Requests), aber teilweise auch zu geringer Beteiligung und Reviews ohne Kommentare. 
Dies führte dazu, dass die Last der Qualitätssicherung ebenfalls ungleich verteilt war.

## Was im Team einfach gefallen bzw. gut gelungen ist
### Task-Management
Als Task Manager nutzten wir wie vorgegeben die in Github bereitgestellten Funktionen
(Erstellen von Issues und Kanban Board). Dieses Management wurde auch das gesamte
Projekt über gut gepflegt. So konnte jedes Teammitglied jederzeit den Fortschritt der Anderen
und auch den Fortschritt des Gesamtprojekts nachverfolgen. Außerdem wurde hierdurch
die Koordination der Aufgaben erleichtert, da jeder Issues erstellen und sich 
Issues zuordnen (assignen) konnte.

### Qualitätssicherung
Wie schon oben z.T. angesprochen, wurden Pull Requests stets von den anderen Teammitgliedern
reviewed, bevor diese auf den Main Branch gemerged wurden. Hier kam es oftmals zur 
Erkennung von Fehlern im Code, sodass diese sofort vom Pull-Request-Steller angepasst/korrigiert
wurden und ein Mergen von fehlerhaftem Code in den meisten Fällen frühzeitig verhindert
werden konnte. Neben der Korrektur von Fehlern wurden dadurch immer wieder auch Vorschläge
zur Optimierung der einzelnen Funktionalitäten sowie der Struktur des Gesamtprojekts
mit eingebracht und anschließend auch realisiert.
Auch dass zum Zusammenfügen der Module und fehlerfreien Durchlauf der Unit-Tests nur sehr
wenige Änderungen (insgesamt an 2-3 Stellen im Programm) nötig waren, zeigt die für unsere
Standards hohe Qualität des Quellcodes (war überwiegend frei von Fehlern).

### Austausch von Wissen
Die detaillierten Code-Reviews haben auch dazu geführt, dass wir den Code des Anderen gesehen
und verstanden haben. Immer wieder konnten durch gegenseitigen Austausch das eingene Wissen
und die Methodik beim Schreiben von Quellcode optimiert werden.

### Einheitlichkeit
Wir haben uns bereits im Vorfeld über die Coding-Konventionen, Aufbau der Funktions-Header, 
Benennung von Funktionen und Rückgabewerte von Funktionen festgelegt. Diese Abmachungen 
wurden auch stets eingehalten, was zur Übersichtlichkeit vom Projekt und zum guten
Zusammenspiel der Module beigetragen hat.

### Merge-Konflikte
Durch die eigenständige Bearbeitung von Issues und Modulen, konnten Merge-Konflikte durch
Pull-Requests zum Zusammentragen der Arbeiten fast vollständig vermieden werden.
