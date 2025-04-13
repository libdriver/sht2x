[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT2X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht2x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHT2x嵌入在3 × 3 × 1.1 mm³可回流焊双扁平无引线（DFN）封装中，提供经校准的线性传感器信号,并以数字I²C格式输出。SHT2x湿度传感器系列将电容式湿度传感器、带隙温度传感器和专用模拟和数字集成电路——都集成在一个CMOSens® 芯片上,使得传感器具有良好的精度,长期稳定性和超低功耗。每一个传感器都经过单独校准和测试。传感器表面有印制的批号,芯片内部带有存储的电子识别码,可以通过软件命令读取。此外，SHT2x湿度传感器的分辨率可以通过命令改变（RH/T为8/12位至12/14位），传感器带有的校验和有助于提高通信的可靠性。凭借这一系列特性及其被证明的可靠性和长期稳定性，SHT2x湿度传感器系列提供了卓越的性价比。用户可使用EK-H4和EK-H5评估套件传感器的性能。

LibDriver SHT2X是LibDriver推出的SHT2X全功能驱动程序，提供温湿度读取和序列号读取功能等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver SHT2X的源文件。

/interface目录包含了LibDriver SHT2X与平台无关的IIC总线模板。

/test目录包含了LibDriver SHT2X驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver SHT2X编程范例。

/doc目录包含了LibDriver SHT2X离线文档。

/datasheet目录包含了SHT2X数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC总线模板，完成指定平台的IIC总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

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

### 文档

在线文档: [https://www.libdriver.com/docs/sht2x/index.html](https://www.libdriver.com/docs/sht2x/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。