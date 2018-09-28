# C-SoSe18-Teil-1
Teil 1/MP | C++ | SoSe 2018

Ziel der Semesterarbeit ist es ein Programm zu schreiben, welches aus zweierlei Datensätzen eine XML-Instanz generieren kann.
Außerdem soll es möglich sein, die Datensätze nach Schlagwörtern zu durchsuchen. 

Es wurden teilweise Folien aus den Seminarsitzungen verwendet.

Die XML-Datei **herolist.xml** enthält eine Reihe von Informationen über Helden aus der Serie *One Punch Man* (JP 2015, Madhouse). 
In der Text-Datei **herolist.txt** finden sich zusätzliche Informationen wie ID, Einsatzbereich/Wohnort des jeweiligen Helden und den aktuellen Listenplatz innerhalb des zugewiesenen Helden-Rankings (S, A, B, C).  

Für das Einlesen der beiden Dateien müssen die **vollständigen bzw. absoluten Pfade** eingegeben werden, z.B.: *C:\Users\User\Desktop\CPP\xyz.xml*.
Bei der Funktion **convert();** muss ebenfalls der vollständige Pfad mitsamt Dateinamen festgelegt werden.
Mit der Funktion **search();** lässt sich die XML-Instanz durchsuchen und liefert ggf. eine Trefferliste.
