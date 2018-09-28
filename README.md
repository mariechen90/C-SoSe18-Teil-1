# C-SoSe18-Teil-1
Teil 1/MP | C++ | SoSe 2018

Ziel der Semesterarbeit ist es ein Programm zu schreiben, welches aus zweierlei Datensätzen eine XML-Instanz generieren kann.
Außerdem soll es möglich sein, die Datensätze nach Schlagwörtern zu durchsuchen. 

Es wurden teilweise Folien aus den Seminarsitzungen verwendet.

### Thema:
Die XML-Datei **herolist.xml** enthält eine Reihe von Informationen über Helden aus der Serie *One Punch Man* (JP 2015, Madhouse). 
In der Textdatei **herolist.txt** befinden sich zusätzliche Informationen wie ID, Einsatzbereich/Wohnort des jeweiligen Helden und der aktuelle Listenplatz innerhalb des zugewiesenen Helden-Rankings (Rankings werden mit den Buchstaben S, A, B und C betitelt, wobei S den höchsten Rang darstellt).  

![Saitama & Genos](https://dw9to29mmj727.cloudfront.net/properties/2016/527-SeriesThumb_OPM_400x320.jpg)

### Funktionalität:
Programm über **main.cpp** starten und Anweisungen auf dem Bildschirm befolgen.
Für das Einlesen der beiden Dateien müssen die **vollständigen bzw. absoluten Pfade** eingegeben werden, z.B.: *C:\Users\User\Desktop\CPP\xyz.xml*.

Mit der Funktion **search();** lässt sich die XML-Instanz durchsuchen und liefert ggf. eine Trefferliste. Es kann nach *name, heroID und classification* gesucht werden. Wobei bei der letzteren Kategorie die Zeichen S, A, B und C zulässig sind und eine Trefferliste aller Helden mit der jeweiligen Klasse/Rang des Helden liefern.

Bei der Funktion **convert();** muss ebenfalls der vollständige Pfad mitsamt Dateinamen festgelegt werden. Es wird eine neue XML-Datei erstellt, die die Informationen aus der ursprünglichen XML-Instanz **herolist.xml** und der Textdatei **herolist.txt** zusammenfasst.
