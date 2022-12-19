# Shotgun チェリーパイ Build Manual（[日本語](https://github.com/Taro-Hayashi/Shotgun-CherryPie/blob/main/README.md)）
- [Contents](#Contens)
- [Preparation](#Preparation)
- [Soldering](#Soldering)
- [Assembling](#Assembling)
- [Customise](#Customise)

## Contents
![](img/IMG_4355C.jpg)  
||Name|Quamtities| |
|-|-|-|-|
|1|Mainboard|1|
|2|Top plate|1||
|3|Bottom plate|1||
|4|Middle plate #1|1||
|5|Middle plate #2|1||
|6|Middle plate #3|1||
|7|Short screws|4|4mm|
|8|Long screws|4|8mm|
|9|Spacers|4|8mm|
|10|Diodes|20|1N4148|
|11|Tactile switch|1||
|12|Hotswap sockets|20||
|13|Rubber feet|4||
|-|Pin header|1||

### Additional required
|Name|Quantities|||
|-|-|-|-|
|Raspberry Pi Pico|1||[Yushakobo](https://shop.yushakobo.jp/en/products/raspberry-pi-pico)|
|Switches|11 - 20|Cherry MX|[Yushakobo](https://shop.yushakobo.jp/en/collections/all-switches/cherry-mx-%E4%BA%92%E6%8F%9B-%E3%82%B9%E3%82%A4%E3%83%83%E3%83%81)|
|Keycaps|11 - 20|Cherry MX|[Yushakobo](https://shop.yushakobo.jp/en/collections/keycaps/cherry-mx-%E4%BA%92%E6%8F%9B-%E3%82%AD%E3%83%BC%E3%82%AD%E3%83%A3%E3%83%83%E3%83%97)|
|Micro-USB Cable|1||[Yushakobo](https://shop.yushakobo.jp/en/products/usb-cable-micro-b-0-8m)|

### Optional
|Name|Quantities|||
|-|-|-|-|
|Conthrough|2|[Usage](https://github.com/Taro-Hayashi/Shotgun-CherryPie/blob/main/conthrough2_EN.md)|[Yushakobo](https://shop.yushakobo.jp/en/products/31?_pos=1&_sid=ca92edae3&_ss=r&variant=40815837610145)|
|Stabilizer||2U, PCB mounted|[Yushakobo](https://shop.yushakobo.jp/en/collections/all-keyboard-parts/Stabilizer)|
|Rotary encoders||EC11/EC12||
|knobs||Outer diameter up to 19mm||
|SK6812MINI-E|28||[Yushakobo](https://shop.yushakobo.jp/en/products/sk6812mini-e-10)|

## Preparation
### Determine key layout  
This kit has a variety of layouts to choose from.  
![](img/layout.jpg)   
  

In this manual, we use rotary encoder and 2 2U keys.  
![](img/test.jpg)    
![](img/IMG_4358.jpg)   

### Write firmware
Download uf2 file.
 - [tarohayashi_shotgun_cp_via.uf2](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.18.13/tarohayashi_shotgun_cp_via.uf2)  

Connect the Raspberry Pi Pico to the PC while holding down the BOOTSEL button, it will be recognized as a USB memory device called RPI-RP2.    
![](img/IMG_4361.jpg)   
![](img/rpi.jpg)   
Writing the uf2 file, it will automatically reboot.

Detouch the USB cable.

## Soldering

### LED
If use LED, install first.  
 - [LED Installation](led_EN.md)  

### Diodes and tactile switch

Install the diodes from D1 to D20.
![](img/IMG_4392.jpg)   
Diodes have a direction.  
  
Bend the legs parallel to the diode to prevent interference with the key switch later.  
![](img/IMG_4395.jpg)   
  
Solder and cut the legs.  
![](img/IMG_4396.jpg)   
  
Solder Tactile Switches.   
![](img/IMG_4397.jpg)   

### Hotswap sockets
Apply a thin layer of solder beforehand.  
![](img/IMG_4401.jpg)    
Solder sockets.  
![](img/IMG_4405.jpg)     

Be careful to keep the socket close to the board at the blue frame.  
![](img/IMG_4407.jpg)   

### Rotary encoder  
![](img/IMG_4410.jpg)     
![](img/IMG_4412.jpg)   

### Raspberry Pi Pico
Stand the pin header on the back side of the board.  
![](img/IMG_6041.JPEG)   
Place and soloder the Raspberry Pi Pico. 
![](img/IMG_6042.JPEG)   
Cut and solder the surface legs.  
![](img/IMG_6044.JPEG)   

### Testing
Plug in the Raspberry Pi Pico and connect it to PC.  
![](img/IMG_4414s.jpg)   
   
## Assembling
### Stabilizers
![](img/IMG_4416.jpg)  
![](img/IMG_4420.jpg)    
![](img/IMG_4426.jpg)   

Cut off the corners of the stabilizer because it would interfere with the acrylic.    
![](img/IMG_4434.jpg)   
  

### Plates
Place the top plate on the main board.  
![](img/IMG_4437.jpg)  
  
Install Switches.
![](img/IMG_4438.jpg)  
![](img/IMG_4440.jpg)  

Attach spacers with short screws.  
![](img/IMG_6346.jpg)  

Place thicker middle plate #1 and thiner middle plate #2 on it.  
![](img/IMG_6349.jpg)   

Put the middle plate #3.   
![](img/IMG_4451.jpg)  

Fasten the back plate with long screws and put the rubber feet.  
![](img/IMG_4454.jpg)  

Install the Keycaps.
![](img/IMG_4460.jpg)  

Then connect to PC.

## Customise  

Access Remap.  
- Remap https://remap-keys.app/

Select the blue button on the left to proceed.  
![](img/remap1.png)  

After Drag-and-Drop the keys, press the flash button in the upper right corner.  
![](img/remap3.png)  

## Misc
### Codes
 - https://github.com/Taro-Hayashi/qmk_firmware/tree/tarohayashi/keyboards/tarohayashi/shotgun_cp  

### JSON for Remap/VIA
 - [shotgun_cp.json](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.8/shotgun_cp.json)

### Plates data
 - [shotgun_cp_plates.zip](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.8/shotgun_cp_plates.zip)  

### Thanks
Used foostan's footprint.  
https://github.com/foostan/kbd/  
https://github.com/foostan/kbd/blob/master/LICENSE  

Used Yoichiro's footprint.  
https://github.com/yoichiro/yoichiro-kbd  
https://github.com/yoichiro/yoichiro-kbd/blob/main/LICENSE 

Sekigon's qmk firmware branch  
https://github.com/sekigon-gonnoc/qmk_firmware/tree/rp2040

PRK Firmware  
https://github.com/picoruby/prk_firmware/

- BOOTH: https://tarohayashi.booth.pm/items/3430753
- Yushakobo: https://shop.yushakobo.jp/en/products/3415

