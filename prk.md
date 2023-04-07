# PRK Firmwareの使い方
## ファームウェアの書き込み
最新版のPRKファームウェアのzipファイルをダウンロードして書き込んでください。
 - [Releases・picoruby/prk_firmware](https://github.com/picoruby/prk_firmware/releases)  

出現したPRK Firmwareドライブにこちらのkeymap.rbをドラッグアンドドロップするとRaspberry Pi Picoをキーボードとして使えるようになります。 
 - [keymap.rb](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.1/keymap.rb)  


### キーのカスタマイズ
PRK Firmwareドライブのkeymap.rbを開きます。  

~~~
kbd.add_layer :default, %i[
  KC_A  KC_B  KC_C  KC_D
  KC_E  KC_F  KC_G  KC_H
  KC_I  KC_J  KC_K  KC_L
  KC_M  KC_N  KC_O  KC_P
  KC_Q  KC_R  KC_S  KC_T
]
~~~
ここのKC_*を書き換えてキーを設定します。  
- キーコード（PRK Firmware Wiki） https://github.com/picoruby/prk_firmware/wiki/Keycodes_ja  

上書き保存をするとその場で変更が反映されます。  

### ロータリーエンコーダー
~~~
encoder_1 = RotaryEncoder.new(27, 28)
encoder_1.clockwise do
  kbd.send_key :KC_1
end
encoder_1.counterclockwise do
  kbd.send_key :KC_2
end
kbd.append encoder_1
~~~
kbd.send_keyのKC_*を変更すると該当のロータリーエンコーダーのキーが変更されます。  
ロータリーエンコーダーはUSB差込側から順に1～5が割り振られています。  

### レイヤーの追加
~~~
kbd.add_layer :lower, %i[
  KC_NO  KC_NO  KC_NO  KC_NO
  KC_NO  KC_NO  KC_NO  KC_NO
  KC_NO  KC_NO  KC_NO  KC_NO
  KC_NO  KC_NO  KC_NO  KC_NO
  KC_NO  KC_NO  KC_NO  KC_NO
]
~~~
レイヤーの名前を変更したキーマップを追加するとレイヤーが増えます。  
レイヤーの名前をキーコードとして使うとそのままレイヤー変更キーとして使えます。  
  
好きな名前のキーコード名を設定し（例では0_LOW）、長押しでレイヤーを変更するキーにすることもできます。  
~~~
kbd.define_mode_key :0_LOW, [ :KC_KP_0, :lower, 150, 150 ]
~~~

### 同時押しのキーコード
~~~
kbd.define_composite_key :UNDO,  %i(KC_Z KC_LCTL)
~~~
例えばCtrl＋Zであればこのように定義します。  

### 文字列を入力するキーコード
~~~
kbd.define_mode_key :TEST, [ Proc.new { kbd.macro "aaaa" }, :KC_NO, 300, nil ]
~~~  

### VIA/Remap対応
- [サンプルのkeymap.rb](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.18/keymap.rb)
- [prk-conf.txt（PRK Firmwareドライブに入れてください）](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.18/keymap.rb)
  
  
その他にもいろいろな機能があるのでPRK Firmwareのwikiをご覧ください。
- https://github.com/picoruby/prk_firmware/wiki/Tutorial_ja
