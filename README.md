# INL-ADD
### Embedded Event Logger
## Vad programmet gör
Detta program simulerar ett enkelt inbyggt IoT-system som hanterar händelser från sensorer.
Systemet:
- genererar slumpmässiga sensorhändelser (temperatur, knapp, rörelse)
- placerar dem i en kö (EventQueue)
- bearbetar dem i en event-loop (EventLoop)
- sparar dem i en logg (EventLog)
- aktiverar eller avaktiverar larm baserat på temperaturer (AlarmSet)
- låter användaren sortera och söka i loggen

## Programmet styrs med kommandon via terminalen, t.ex.:
    tick 20
    print
    Insertion Sort
    find 3
    alarms
    set-threshold 40

### Filstruktur och vad varje fil gör

# Event.h / Event.cpp
Definierar datastrukturen Event och funktionen nextTimestamp() som genererar tidsstämplar.

# EventLog.h / EventLog.cpp
En dynamisk array för att lagra händelser:
  - append() lägger till en händelse
  - get() hämtar
  - set() ändrar
- växer automatiskt när den blir full

# EventQueue.h / EventQueue.cpp
En cirkulär kö för inkommande händelser:
  - enqueue() lägger in
  - dequeue() tar ut
  - isFull() / isEmpty() kontrollerar status

# EventGenerator.h
Genererar slumpmässiga händelser med korrekta värden, sensor-ID och typ.

# EventLoop.h / EventLoop.cpp
Systemets “hjärna”.
Varje tick() gör:
    1. skapa händelse
    2. lägga den i kön
    3. ta ut en händelse från kön
    4. lagra i loggen
    5. uppdatera larmsystemet

# AlarmSet.h / AlarmSet.cpp
Hanterar temperaturbaserade larm:
  - lägger till sensorer som överskrider tröskeln
  - tar bort sensorer som går under den
  - skriver ut aktiva larm

# InsertionSort.h
Sorterar EventLog efter timestamp med insättningssortering.

# Search.h
Söker efter och skriver ut händelser från ett visst sensor-ID.

# main.cpp
Innehåller kommandoloopen:
    - tar emot användarkommandon
    - kör event-loopen
    - skriver ut logg
    - söker
    - sorterar
    - visar larm
