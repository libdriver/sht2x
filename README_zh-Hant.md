[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT2X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht2x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHT2x嵌入在3×3×1.1 mm³可回流焊雙扁平無引線（DFN）封裝中，提供經校準的線性感測器訊號，並以數位I²C格式輸出。 SHT2x濕度感測器系列將電容式濕度感測器、帶隙溫度感測器和專用類比和數位積體電路——都集成在一個CMOSens ®  晶片上，使得感測器具有良好的精度，長期穩定性和超低功耗。 每一個感測器都經過單獨校準和測試。 感測器表面有印製的批號，晶片內部帶有存儲的電子識別碼，可以通過軟件命令讀取。 此外，SHT2x濕度感測器的分辯率可以通過命令改變（RH/T為8/12比特至12/14比特），感測器帶有的校驗和有助於提高通信的可靠性。 憑藉這一系列特性及其被證明的可靠性和長期穩定性，SHT2x濕度感測器系列提供了卓越的性價比。 用戶可使用EK-H4和EK-H5評估套件感測器的效能。

LibDriver SHT2X是LibDriver推出的SHT2X全功能驅動程序，提供溫濕度讀取和序號讀取功能等功能並且它符合MISRA標準。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver SHT2X的源文件。

/interface目錄包含了LibDriver SHT2X與平台無關的IIC總線模板。

/test目錄包含了LibDriver SHT2X驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver SHT2X編程範例。

/doc目錄包含了LibDriver SHT2X離線文檔。

/datasheet目錄包含了SHT2X數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的IIC總線模板，完成指定平台的IIC總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

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

### 文檔

在線文檔: [https://www.libdriver.com/docs/sht2x/index.html](https://www.libdriver.com/docs/sht2x/index.html)。

離線文檔: /doc/html/index.html。

### 貢獻

請參攷CONTRIBUTING.md。

### 版權

版權 (c) 2015 - 現在 LibDriver 版權所有

MIT 許可證（MIT）

特此免費授予任何獲得本軟件副本和相關文檔文件（下稱“軟件”）的人不受限制地處置該軟件的權利，包括不受限制地使用、複製、修改、合併、發布、分發、轉授許可和/或出售該軟件副本，以及再授權被配發了本軟件的人如上的權利，須在下列條件下：

上述版權聲明和本許可聲明應包含在該軟件的所有副本或實質成分中。

本軟件是“如此”提供的，沒有任何形式的明示或暗示的保證，包括但不限於對適銷性、特定用途的適用性和不侵權的保證。在任何情況下，作者或版權持有人都不對任何索賠、損害或其他責任負責，無論這些追責來自合同、侵權或其它行為中，還是產生於、源於或有關於本軟件以及本軟件的使用或其它處置。

### 聯繫我們

請聯繫lishifenging@outlook.com。