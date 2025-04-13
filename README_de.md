[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT2X
[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht2x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Eingebettet in ein reflowlötbares Dual-Flat-no-Leads(DFN)-Gehäuse mit einer Grösse von 3 × 3 × 1.1 mm³ liefert der SHT2x-Feuchtesensor vollständig kalibrierte, linearisierte Sensorsignale digital per I²C-Schnittstelle. Der Feuchtesensor SHT2x besteht aus einem kapazitiven Feuchtesensor, einem Bandlückentemperatursensor und einer speziellen analogen und digitalen integrierten Schaltung – alles auf einem einzigen CMOSens®-Chip. Dies ermöglicht eine überragende Performance in Sachen Genauigkeit, Stabilität und geringem Energieverbrauch. Jeder Sensor wird individuell kalibriert und getestet. Die Losnummer ist auf den Sensor gedruckt, und ein elektronischer Identifikationscode wird auf dem Chip gespeichert und kann auf Befehl ausgelesen werden. Zudem kann die Auflösung des Feuchtesensors SHT2x mit einem Befehl verändert werden (8/12 bit bis zu 12/14 bit für RH/T), und eine Prüfsumme dient zur Verbesserung der Kommunikationszuverlässigkeit. Mit diesen einzigartigen Eigenschaften sowie der nachgewiesenen Zuverlässigkeit und Langzeitstabilität ist der Feuchtesensor SHT2x ein sicherer Wert. Um den Feuchtesensor SHT2x zu testen, stehen zwei Evaluationskits (EK-H4 und EK-H5) zur Verfügung.

LibDriver SHT2X ist der von LibDriver eingeführte Vollfunktionstreiber von SHT2X. Er bietet Funktionen zum Lesen von Temperatur und Luftfeuchtigkeit sowie zum Lesen von Seriennummern. LibDriver ist MISRA-kompatibel.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver SHT2X-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver SHT2X IIC.

/test enthält den Testcode des LibDriver SHT2X-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver SHT2X-Beispielcode.

/doc enthält das LibDriver SHT2X-Offlinedokument.

/Datenblatt enthält SHT2X-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

#### example basic

```C
#include "driver_sht2x_basic.h"

uint8_t res;
uint8_t sn[8];
uint32_t i;
float temperature;
float humidity;

/* basic init */
res = sht2x_basic_init();
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    sht2x_interface_delay_ms(1000);

    /* read data */
    res = sht2x_basic_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)sht2x_basic_deinit();

        return 1;
    }

    /* output */
    sht2x_interface_debug_print("sht2x: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)3);
    sht2x_interface_debug_print("sht2x: temperature is %0.2fC.\n", temperature);
    sht2x_interface_debug_print("sht2x: humidity is %0.2f%%.\n", humidity);
    
    ...
}

...
    
/* get serial number */
res = sht2x_basic_get_serial_number(sn);
if (res != 0)
{
    sht2x_basic_deinit();

    return 1;
}
sht2x_interface_debug_print("sht2x: sn 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X.\n", 
                            sn[0], sn[1], sn[2], sn[3], sn[4], sn[5], sn[6], sn[7]);

...
    
/* basic deinit */
(void)sht2x_basic_deinit();

return 0;
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/sht2x/index.html](https://www.libdriver.com/docs/sht2x/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.