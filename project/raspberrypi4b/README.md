### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(sht2x REQUIRED)
```

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
./sht2x -i

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
./sht2x -p

sht2x: SCL connected to GPIO3(BCM).
sht2x: SDA connected to GPIO2(BCM).
```

```shell
./sht2x -t reg

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
./sht2x -t read --times=3

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
sht2x: temperature is 25.57C.
sht2x: humidity is 31.42%.
sht2x: temperature is 25.57C.
sht2x: humidity is 31.42%.
sht2x: temperature is 25.53C.
sht2x: humidity is 31.46%.
sht2x: set resolution rh 8bit, t 12bit.
sht2x: temperature is 25.49C.
sht2x: humidity is 30.82%.
sht2x: temperature is 25.49C.
sht2x: humidity is 30.82%.
sht2x: temperature is 25.45C.
sht2x: humidity is 30.82%.
sht2x: set resolution rh 10bit, t 13bit.
sht2x: temperature is 25.45C.
sht2x: humidity is 31.49%.
sht2x: temperature is 25.45C.
sht2x: humidity is 31.65%.
sht2x: temperature is 25.43C.
sht2x: humidity is 31.77%.
sht2x: set resolution rh 11bit, t 11bit.
sht2x: temperature is 25.40C.
sht2x: humidity is 31.88%.
sht2x: temperature is 25.40C.
sht2x: humidity is 31.96%.
sht2x: temperature is 25.40C.
sht2x: humidity is 32.04%.
sht2x: set no hold master mode.
sht2x: set resolution rh 12bit, t 14bit.
sht2x: temperature is 25.39C.
sht2x: humidity is 32.13%.
sht2x: temperature is 25.38C.
sht2x: humidity is 32.13%.
sht2x: temperature is 25.37C.
sht2x: humidity is 32.22%.
sht2x: set resolution rh 8bit, t 12bit.
sht2x: temperature is 25.36C.
sht2x: humidity is 32.03%.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.03%.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.03%.
sht2x: set resolution rh 10bit, t 13bit.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.24%.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.24%.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.09%.
sht2x: set resolution rh 11bit, t 11bit.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.12%.
sht2x: temperature is 25.32C.
sht2x: humidity is 32.04%.
sht2x: temperature is 25.23C.
sht2x: humidity is 31.96%.
sht2x: finish read test.
```

```shell
./sht2x -e read --times=3

sht2x: 1/3.
sht2x: temperature is 24.84C.
sht2x: humidity is 32.97%.
sht2x: 2/3.
sht2x: temperature is 24.83C.
sht2x: humidity is 33.05%.
sht2x: 3/3.
sht2x: temperature is 24.84C.
sht2x: humidity is 32.97%.
```

```shell
./sht2x -e sn

sht2x: sn 0x02 0x01 0x88 0x13 0x6B 0x8B 0x80 0x00.
```

```shell
./sht2x -h

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
