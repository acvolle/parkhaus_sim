### Alternative Überlegungen zur Umsetzung

Im folgenden werden einige alternative Umsetzungsmöglichkeiten, die wir uns angeschaut haben, vorgestellt und die Gründe genannt, wieso wir uns letztendlich für die verwendete Umsetzung entschieden haben

#### Modularisierung
Zu Beginn das Projekts war ein geringerer Grad der Modularisierung vorgesehen, beispielsweise stand im Raum stats und simulation zu einem Modul zusammenzufassen oder deren Funktionalität auf Main, Parkhaus, Queue und UI aufzuteilen. Dagegen sprach aber, das so wenig wie möglich Funktionalität in main() untergebracht werden sollte. Die hohe Modularisierung beitet hingegen den Vorteil, dass einzelne Source-Dateien kompakter und übersichtlicher sind, was allein schon die Arbeitsteilung in kleinere Arbeitspakete und die Wartung vereinfacht.

Bei den „Call by Reference“-Funktionen mussten Funktionen oft mit einem Pointer aufgerufen werden, da die Operationen wirklich auf dem spezifischen Objekt ausgeführt werden mussten (z. B. dem Parkhaus). Dies haben wir so viel wie möglich eingesetzt, etwa bei dequeue(), bei dem ein Pointer auf einen Pointer übergeben wird und der Pointer dann auf die Adresse des aus der Queue entfernten Cars gesetzt wird. In der Gruppe wurde diskutiert, dass die einfache Rückgabe des Pointers einfacher und simpler wäre, ABER sorgt diese Lösung dafür, dass ein Status-Code int als Rückgabewert dient – für einheitlichere Rückgabewerte und besseres Error-Handling (auch für Rückgabewert 1, wenn die Queue leer ist).

Parkhaus und Config (vielleicht auch Stats?) hätten so gelöst werden können, dass sie nicht dynamisch allokiert werden. Wir haben von Beginn an entschieden, die Strukturen dynamisch zu allokieren, um hinsichtlich der vielen Funktionsübergaben möglichst viel Handlungsspielraum bei der Implementierung zu haben und das Auftreten zukünftiger Probleme hinsichtlich des Speichers von Projektbeginn an zu unterbinden.
