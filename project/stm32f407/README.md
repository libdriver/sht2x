### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. SHT2X

#### 3.1 Command Instruction

1. Show sht2x chip and driver information.

   ```shell
   sht2x (-i | --information)
   ```

2. Show sht2x help.

   ```shell
   sht2x (-h | --help)
   ```

3. Show sht2x pin connections of the current board.

   ```shell
   sht2x (-p | --port)
   ```

4. Run sht2x register test.

   ```shell
   sht2x (-t reg | --test=reg)
   ```

5. Run sht2x read test, num is test times.

   ```shell
   sht2x (-t read | --test=read) [--times=<num>]
   ```


6. Run sht2x read function, num is read times.

   ```shell
   sht2x (-e read | --example=read) [--times=<num>]
   ```

7. Run sht2x sn function.

   ```shell
   sht2x (-e sn | --example=sn)
   ```

#### 3.2 Command Example

```shell
sht2x -i

sht2x: chip is Sensirion SHT2X.
sht2x: manufacturer is Sensirion.
sht2x: interface is IIC.
sht2x: driver version is 1.0.
sht2x: min supply voltage is 2.1V.
sht2x: max supply voltage is 3.6V.
sht2x: max current is 0.33mA.
sht2x: max temperature is 125.0C.
sht2x: min temperature is -50.0C.
```

```shell
sht2x -p

sht2x: SCL connected to GPIOB PIN8.
sht2x: SDA connected to GPIOB PIN9.
```

```shell
sht2x -t reg

sht2x: chip is Sensirion SHT2X.
sht2x: manufacturer is Sensirion.
sht2x: interface is IIC.
sht2x: driver version is 1.0.
sht2x: min supply voltage is 2.1V.
sht2x: max supply voltage is 3.6V.
sht2x: max current is 0.33mA.
sht2x: max temperature is 125.0C.
sht2x: min temperature is -50.0C.
sht2x: start register test.
sht2x: sht2x_set_mode/sht2x_get_mode test.
sht2x: set hold master mode.
sht2x: check mode ok.
sht2x: set no hold master mode.
sht2x: check mode ok.
sht2x: sht2x_set_resolution/sht2x_get_resolution test.
sht2x: set resolution rh 12bit, t 14bit.
sht2x: check resolution ok.
sht2x: set resolution rh 8bit, t 12bit.
sht2x: check resolution ok.
sht2x: set resolution rh 10bit, t 13bit.
sht2x: check resolution ok.
sht2x: set resolution rh 11bit, t 11bit.
sht2x: check resolution ok.
sht2x: sht2x_set_heater/sht2x_get_heater test.
sht2x: enable heater.
sht2x: check heater ok.
sht2x: disable heater.
sht2x: check heater ok.
sht2x: sht2x_set_disable_otp_reload/sht2x_get_disable_otp_reload test.
sht2x: enable disable otp reload.
sht2x: check disable otp reload ok.
sht2x: disable disable otp reload.
sht2x: check disable otp reload ok.
sht2x: sht2x_get_status test.
sht2x: check vdd 2.25v status over.
sht2x: sht2x_get_serial_number test.
sht2x: sn 0x02 0x01 0x88 0x13 0x6B 0x8B 0x80 0x00.
sht2x: sht2x_soft_reset test.
sht2x: soft reset.
sht2x: finish register test.
```

```shell
sht2x -t read --times=3

sht2x: chip is Sensirion SHT2X.
sht2x: manufacturer is Sensirion.
sht2x: interface is IIC.
sht2x: driver version is 1.0.
sht2x: min supply voltage is 2.1V.
sht2x: max supply voltage is 3.6V.
sht2x: max current is 0.33mA.
sht2x: max temperature is 125.0C.
sht2x: min temperature is -50.0C.
sht2x: start read test.
sht2x: set hold master mode.
sht2x: set resolution rh 12bit, t 14bit.
sht2x: temperature is 24.20C.
sht2x: humidity is 34.21%.
sht2x: temperature is 24.21C.
sht2x: humidity is 34.42%.
sht2x: temperature is 24.21C.
sht2x: humidity is 34.59%.
sht2x: set resolution rh 8bit, t 12bit.
sht2x: temperature is 24.17C.
sht2x: humidity is 34.37%.
sht2x: temperature is 24.17C.
sht2x: humidity is 34.37%.
sht2x: temperature is 24.17C.
sht2x: humidity is 34.37%.
sht2x: set resolution rh 10bit, t 13bit.
sht2x: temperature is 24.21C.
sht2x: humidity is 34.79%.
sht2x: temperature is 24.26C.
sht2x: humidity is 34.92%.
sht2x: temperature is 24.30C.
sht2x: humidity is 35.15%.
sht2x: set resolution rh 11bit, t 11bit.
sht2x: temperature is 24.30C.
sht2x: humidity is 35.41%.
sht2x: temperature is 24.39C.
sht2x: humidity is 35.61%.
sht2x: temperature is 24.47C.
sht2x: humidity is 36.01%.
sht2x: set no hold master mode.
sht2x: set resolution rh 12bit, t 14bit.
sht2x: temperature is 24.69C.
sht2x: humidity is 37.53%.
sht2x: temperature is 24.91C.
sht2x: humidity is 39.04%.
sht2x: temperature is 25.19C.
sht2x: humidity is 40.25%.
sht2x: set resolution rh 8bit, t 12bit.
sht2x: temperature is 25.49C.
sht2x: humidity is 40.57%.
sht2x: temperature is 25.66C.
sht2x: humidity is 40.91%.
sht2x: temperature is 25.93C.
sht2x: humidity is 40.91%.
sht2x: set resolution rh 10bit, t 13bit.
sht2x: temperature is 26.18C.
sht2x: humidity is 40.78%.
sht2x: temperature is 26.41C.
sht2x: humidity is 40.33%.
sht2x: temperature is 26.58C.
sht2x: humidity is 39.93%.
sht2x: set resolution rh 11bit, t 11bit.
sht2x: temperature is 26.69C.
sht2x: humidity is 39.47%.
sht2x: temperature is 26.69C.
sht2x: humidity is 38.04%.
sht2x: temperature is 26.69C.
sht2x: humidity is 36.74%.
sht2x: finish read test.
```

```shell
sht2x -e read --times=3

sht2x: 1/3.
sht2x: temperature is 25.57C.
sht2x: humidity is 31.35%.
sht2x: 2/3.
sht2x: temperature is 25.56C.
sht2x: humidity is 31.46%.
sht2x: 3/3.
sht2x: temperature is 25.49C.
sht2x: humidity is 31.54%.
```

```shell
sht2x -e sn

sht2x: sn 0x02 0x01 0x88 0x13 0x6B 0x8B 0x80 0x00.
```

```shell
sht2x -h

Usage:
  sht2x (-i | --information)
  sht2x (-h | --help)
  sht2x (-p | --port)
  sht2x (-t reg | --test=reg)
  sht2x (-t read | --test=read) [--times=<num>]
  sht2x (-e read | --example=read) [--times=<num>]
  sht2x (-e sn | --example=sn)

Options:
  -e <read | sn>, --example=<read | sn>
                        Run the driver example.
  -h, --help            Show the help.
  -i, --information     Show the chip information.
  -p, --port            Display the pin connections of the current board.
  -t <reg | read>, --test=<reg | read>
                        Run the driver test.
      --times=<num>     Set the running times.([default: 3])
```

