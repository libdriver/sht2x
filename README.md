[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT2X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht2x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

Embedded in a reflow solderable dual-flat no-leads (DFN) package of 3 × 3 × 1.1 mm³, the SHT2x provides calibrated, linearized sensor signals in digital, I²C format. The SHT2x humidity sensor series contains a capacitive-type humidity sensor, a band-gap temperature sensor, and specialized analog and digital integrated circuits – all on a single CMOSens® chip. This yields superior sensor performance in terms of accuracy and stability as well as minimal power consumption. Every sensor is individually calibrated and tested. Lot identification is printed on the sensor and an electronic identification code is stored on the chip – which can be read out on command. Furthermore, the resolution of the SHT2x humidity sensor can be changed on command (8/12 bit up to 12/14 bit for RH/T) and a checksum helps to improve communication reliability. With this set of features and its proven reliability and long-term stability, the SHT2x humidity sensor series offers an outstanding price-performance ratio. To test a humidity sensor from the SHT2x series, two evaluation kits, EK-H4 and EK-H5, are available.

LibDriver SHT2X is a full-featured driver of SHT2X launched by LibDriver.It provides functions of temperature and humidity reading and serial number reading. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver SHT2X source files.

/interface includes LibDriver SHT2X IIC platform independent template.

/test includes LibDriver SHT2X driver test code and this code can test the chip necessary function simply.

/example includes LibDriver SHT2X sample code.

/doc includes LibDriver SHT2X offline document.

/datasheet includes SHT2X datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface IIC platform independent template and finish your platform IIC driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

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

### Document

Online documents: [https://www.libdriver.com/docs/sht2x/index.html](https://www.libdriver.com/docs/sht2x/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.