### Alternative Überlegungen zur Umsetzung

Im folgenden werden einige alternative Umsetzungsmöglichkeiten, die wir uns angeschaut haben, vorgestellt und die Gründe genannt, wieso wir uns letztendlich für die verwendete Umsetzung entschieden haben

#### Modularisierung
Zu Beginn das Projekts war ein geringerer Grad der Modularisierung vorgesehen, beispielsweise stand im Raum stats und simulation zu einem Modul zusammenzufassen oder deren Funktionalität auf Main, Parkhaus, Queue und UI aufzuteilen. Dagegen sprach aber, das so wenig wie möglich Funktionalität in main() untergebracht werden sollte. Die hohe Modularisierung beitet hingegen den Vorteil, dass einzelne Source-Dateien kompakter und übersichtlicher sind, was allein schon die Arbeitsteilung in kleinere Arbeitspakete und die Wartung vereinfacht.

#### "Call by Reference" und FUnktionsrückgabewerte
Viele der implementierten Funktionen müssen mit einem Pointer als input aufgerufen werden ("call by reference"), da die Operationen wirklich auf dem spezifischen Objekt ausgeführt werden mussten (z. B. dem Parkhaus). Dieses Prinzip haben wir aber auch so viel wie sinnvoll auch in anderen Funktionen eingesetzt, etwa bei dequeue(), bei dem ein Pointer auf einen Pointer übergeben wird und der Pointer dann auf die Adresse des aus der Queue entfernten Cars gesetzt wird. In der Gruppe wurde haben wir darüber diskutiert, ob die einfache Rückgabe des Pointers einfacher und simpler wäre, diese Lösung sorgt aber dafür, dass ein Status-Code int als Rückgabewert dient - somit haben wir einheitlichere und differenzierbare Rückgabewerte (die Funktion kann zwischen leerer Queue '1' und NULL-Pointer '-1' unterscheiden).

#### Dynamische Allokation
Fast alle Strukturen der Simulation (mit Ausnahme der Queue) werden dynamisch allokiert. Manche davon, z.B. Parkhaus und Config, hätten so gelöst werden können, dass sie nicht dynamisch allokiert werden müssten, sondern in main initialiert würden wie die Queue. Dies hätte uns den Aufwand der dynamischen Speicherverwaltung (sowie damit hereingehende Probleme) erspart. Wir haben uns aber von Beginn an entschieden, diese Strukturen dynamisch zu allokieren, um vor allem hinsichtlich der vielen Funktionsübergaben (siehe oben), möglichst viel Handlungsspielraum bei der Implementierung zu haben und das Auftreten zukünftiger Probleme hinsichtlich des Speichers von Projektbeginn an zu unterbinden.

#### Berechnung der finalen Statistiken
In unserer aktuellen Implementierung werden nur die aktuellen Statistiken in einer stats struct gespeichert. Die finalen Statistiken werden erst am Ende der Simulation berechnet, indem alle Simulationsdaten aus der log-Datei wieder ausgelesen werden. Eine andere Option wäre gewesen, in jedem Simulationsschritt die finalen Statistiken (Durchschnitte und Maximalwerte) zu berechnen, am Ende ergibt sich dann dasselbe Ergebnis. Wir haben uns stattdessen für die am Anfang erwähnte Implementierung entschieden, da diese Berechnung somit unabhängig vom Simulationsdurchlauf geschieht. Damit wird eine höhere Modularisierung (und somit eine einfachere Wartbarkeit des Programms) gewährleistet. DIes hat sich später ausgezahlt, da wir im nachhinein diese Berechnung abändern mussten und dabei nichts am Programmcode der eigentlichen Simulation ändern mussten.

#### Fortlaufende Car ID
Jeder struct Car braucht eine eindeutige ID. Da diese nicht zwangsläufig fortlaufend sein muss, wurde erwägt, einfach den Zeitpunkt des Erstellens des Fahrzeugs als ID zu nehmen. Somit hätten wir uns eine globale Variable erspart. Wir haben uns aber entschieden eine statische, fortlaufende Variable current_car_id einzuführen. Dies hat praktisch keinen Mehraufwand gebracht und macht den Code lesbarer.

