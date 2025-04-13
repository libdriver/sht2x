[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT2X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht2x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

3 × 3 × 1.1mm³ 크기의 리플로우 솔더링 가능한 듀얼 플랫 무연(DFN) 패키지에 내장된 SHT2x는 디지털 I²C 형식으로 보정 및 선형화된 센서 신호를 제공합니다. SHT2x 습도 센서 시리즈는 정전용량형 습도 센서, 밴드갭 온도 센서, 그리고 특수 아날로그 및 디지털 집적 회로를 단일 CMOSens® 칩에 통합했습니다. 이를 통해 정확도와 안정성 측면에서 탁월한 센서 성능과 최소 전력 소비를 제공합니다. 모든 센서는 개별적으로 보정 및 테스트됩니다. 로트 식별 정보는 센서에 인쇄되고 전자 식별 코드는 칩에 저장되어 명령에 따라 판독할 수 있습니다. 또한, SHT2x 습도 센서의 분해능은 명령에 따라 변경할 수 있으며(RH/T의 경우 8/12비트에서 최대 12/14비트까지), 체크섬 기능은 통신 안정성을 향상시킵니다. 이러한 기능 세트와 검증된 신뢰성 및 장기 안정성을 바탕으로 SHT2x 습도 센서 시리즈는 탁월한 가격 대비 성능을 제공합니다. SHT2x 시리즈의 습도 센서를 테스트하기 위해 EK-H4와 EK-H5의 두 가지 평가 키트가 제공됩니다.

LibDriver SHT2X는 LibDriver에서 출시한 SHT2X의 전체 기능 드라이버입니다. 온도 및 습도 읽기 및 일련 번호 읽기 기능을 제공합니다. LibDriver는 MISRA를 준수합니다.

### 콘텐츠

  - [설명](#설명)
  - [설치](#설치)
  - [사용](#사용)
    - [example basic](#example-basic)
  - [문서](#문서)
  - [기고](#기고)
  - [저작권](#저작권)
  - [문의하기](#문의하기)

### 설명

/src 디렉토리에는 LibDriver SHT2X의 소스 파일이 포함되어 있습니다.

/interface 디렉토리에는 LibDriver SHT2X용 플랫폼 독립적인 IIC버스 템플릿이 포함되어 있습니다.

/test 디렉토리에는 LibDriver SHT2X드라이버 테스트 프로그램이 포함되어 있어 칩의 필요한 기능을 간단히 테스트할 수 있습니다.

/example 디렉토리에는 LibDriver SHT2X프로그래밍 예제가 포함되어 있습니다.

/doc 디렉토리에는 LibDriver SHT2X오프라인 문서가 포함되어 있습니다.

/datasheet 디렉토리에는 SHT2X데이터시트가 있습니다.

/project 디렉토리에는 일반적으로 사용되는 Linux 및 마이크로컨트롤러 개발 보드의 프로젝트 샘플이 포함되어 있습니다. 모든 프로젝트는 디버깅 방법으로 셸 스크립트를 사용하며, 자세한 내용은 각 프로젝트의 README.md를 참조하십시오.

/misra 에는 LibDriver misra 코드 검색 결과가 포함됩니다.

### 설치

/interface 디렉토리에서 플랫폼 독립적인IIC 버스 템플릿을 참조하여 지정된 플랫폼에 대한 IIC버스 드라이버를 완성하십시오.

/src 디렉터리, 플랫폼용 인터페이스 드라이버 및 자체 드라이버를 프로젝트에 추가합니다. 기본 예제 드라이버를 사용하려면 /example 디렉터리를 프로젝트에 추가합니다.

### 사용

/example 디렉터리의 예제를 참조하여 자신만의 드라이버를 완성할 수 있습니다. 기본 프로그래밍 예제를 사용하려는 경우 사용 방법은 다음과 같습니다.

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

### 문서

온라인 문서: [https://www.libdriver.com/docs/sht2x/index.html](https://www.libdriver.com/docs/sht2x/index.html).

오프라인 문서: /doc/html/index.html.

### 기고

CONTRIBUTING.md 를 참조하십시오.

### 저작권

저작권 (c) 2015 - 지금 LibDriver 판권 소유

MIT 라이선스(MIT)

이 소프트웨어 및 관련 문서 파일("소프트웨어")의 사본을 얻은 모든 사람은 이에 따라 무제한 사용, 복제, 수정, 통합, 출판, 배포, 2차 라이선스를 포함하여 소프트웨어를 처분할 수 있는 권리가 부여됩니다. 소프트웨어의 사본에 대한 라이선스 및/또는 판매, 그리고 소프트웨어가 위와 같이 배포된 사람의 권리에 대한 2차 라이선스는 다음 조건에 따릅니다.

위의 저작권 표시 및 이 허가 표시는 이 소프트웨어의 모든 사본 또는 내용에 포함됩니다.

이 소프트웨어는 상품성, 특정 목적에의 적합성 및 비침해에 대한 보증을 포함하되 이에 국한되지 않는 어떠한 종류의 명시적 또는 묵시적 보증 없이 "있는 그대로" 제공됩니다. 어떤 경우에도 저자 또는 저작권 소유자는 계약, 불법 행위 또는 기타 방식에 관계없이 소프트웨어 및 기타 소프트웨어 사용으로 인해 발생하거나 이와 관련하여 발생하는 청구, 손해 또는 기타 책임에 대해 책임을 지지 않습니다.

### 문의하기

연락주세요lishifenging@outlook.com.