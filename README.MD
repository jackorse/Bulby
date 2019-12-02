# BULBY

### Progetto per OpenDay 2018

Il progetto consiste in una **lampada smart** che può essere comandata da un **display touch** e da un'**applicazione mobile**.

![Bulby](/docs/Spiegazione.jpg)

**L'applicazione** (realizzata con AppInventor) consente di:
* Conoscere in tempo reale lo stato della luce
* Accendere e spegnere la luce
* Cambiare il colore
* Cambiare l'intensità
* Attivare profili predefiniti
* Utilizzare dei comandi vocali per controllare la luce


Dal **display touch** è possibile:
* Conoscere in tempo reale lo stato della luce
* Accendere e spegnere la luce
* Cambiare il colore
* Cambiare l'intensità


Per il progetto è stato utilizato:
* Arduino Mega
* Display touch Elegoo 2.8'
* Modulo Bluetooth hc-05
* Led a infrarossi
* Luce comandata a infrarossi


![Bulby](/docs/Cartellone.jpg)

Dettagli tecnici:
* Il led IR è collegato ad Arduino sul pin 46 attraverso una resistenza
* Il modulo bluetooth comunica attraverso la Serial1 e il pin "state" è collegato al pin 31 di arduino

