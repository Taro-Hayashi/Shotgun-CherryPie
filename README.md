# Shotgun チェリーパイ ビルドガイド
- [キット内容](#キット内容)
- [準備](#準備)
- [はんだ付け](#はんだ付け)
- [組み立て](#組み立て)
- [キーマップの変更](#キーマップの変更)
- [その他](#その他)

## キット内容
![](img/IMG_4355.jpg)  
||部品名|数| |
|-|-|-|-|
|1|メインボード|1|白・PCB|
|2|トッププレート|1||
|3|ボトムプレート|1||
|4|ミドルプレート1|1|透明アクリル、5mm|
|5|ミドルプレート2|1|3mm|
|6|ミドルプレート3|1|3mm|
|7|ネジ（短）|4|M2、4mm|
|8|ネジ（長）|4|8mm|
|9|スペーサー|4|8mm|
|10|ダイオード|20|1N4148|
|11|リセットスイッチ|1||
|12|Cherry MX ホットスワップソケット|20||
|13|ゴム足|4||

### キット以外に必要なもの
|部品名|数|||
|-|-|-|-|
|Raspberry Pi Pico|1||[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/raspberry-pi-pico)|
|コンスルー 20ピン（高さ2.5mm）|2|2本必要なのでご注意ください|[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/31?variant=40815840067745)|
|キースイッチ|～20|Cherry MX互換のもの|[遊舎工房様販売ページ](https://shop.yushakobo.jp/collections/all-switches/cherry-mx-%E4%BA%92%E6%8F%9B-%E3%82%B9%E3%82%A4%E3%83%83%E3%83%81)|
|キーキャップ|～20|Cherry MX互換のもの|[遊舎工房様販売ページ](https://shop.yushakobo.jp/collections/keycaps/cherry-mx-%E4%BA%92%E6%8F%9B-%E3%82%AD%E3%83%BC%E3%82%AD%E3%83%A3%E3%83%83%E3%83%97)|
|Micro USB ケーブル|1||[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/usb-cable-micro-b-0-8m)|

### オプション
|部品名|数|||
|-|-|-|-|
|2Uスタビライザー|必要数|PCBマウントのもの|[遊舎工房様販売ページ](https://shop.yushakobo.jp/collections/all-keyboard-parts/Stabilizer)|
|ロータリーエンコーダ|～5|EC11/EC12/ロープロファイル||
|ノブ|～5|直径19mmまで||
|SK6812MINI-E|12、もしくは28|12個で裏面のみ、28個で両面になります。|[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/sk6812mini-e-10)|
|1N4148W|13|表面実装タイプのダイオード|[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/a0800di-02-100)|


### 必要な工具
|工具名| |
|-|-|
|はんだごて||
|はんだごて置き場||
|鉛入りはんだ||
|ピンセット||
|精密ドライバー||
|ニッパー等ダイオードの足を切れるもの|金属用でない場合刃こぼれします。|

### あると便利な工具（★は特におすすめです）
|工具名||
|-|-|
|耐熱シリコンマット||
|斜めに切ったタイプのこて先|★|
|温度調節可能なはんだごて|300度-350度前後|
|フラックス|★|
|テスター||
|フラックスリムーバー|★|
|マスキングテープ||
|はんだ吸い取り線||
|はんだ吸い取り器||

## 準備
### レイアウトを決める  
このキットはいろいろなレイアウトから選んでお使いいただけます。  
![](img/layout.jpg)   
色のついているところが交換可能になっています。  
  
このビルドガイドではロータリーエンコーダーを1つ、幅が2倍（2U）のキーを二つ使ったテンキーにします。  
![](img/test.jpg)   
キット、その他必要なものに追加でロータリーエンコーダーとノブを一つずつ、スタビライザーを2つ用意しました。  
![](img/IMG_4358.jpg)   

### ファームウェアの書き込み
最新版のPRKファームウェアのzipファイルをダウンロード、解凍します。
 - [Releases・picoruby/prk_firmware](https://github.com/picoruby/prk_firmware/releases)  

Assetsをクリックすると出てきます。
![](img/zip.jpg) 

Raspberry Pi Picoを、BOOTSELボタン押しながらUSBケーブルでPCと接続すると、RPI-RP2というUSBメモリとして認識されます。  
![](img/IMG_4361.jpg)   
![](img/rpi.jpg)   
そこに解凍したuf2ファイルを書き込むと、自動的に再起動して代わりにPRK Firmwareというドライブとして認識されます。  
![](img/prd.jpg)   
そのドライブにこちらのkeymap.rbをドラッグアンドドロップするとRaspberry Pi Picoをキーボードとして使えるようになります。 
 - [keymap.rb](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.1/keymap.rb)  

書き込みが終わったら一旦USBケーブルは外します。  

## はんだ付け
はんだ付けのやり方は動画で見るとわかりやすいです。  
パーツは思ったより壊れないので落ち着いて作業すると失敗しにくいです。  
 - ホームセンターのDCMさんの解説動画(58秒～) https://www.youtube.com/watch?v=JFQg_ObITYE&t=58s  
  
### Raspberry Pi Picoのはんだ付け

まずはRaspberry Pi Picoにコンスルーをはんだ付けします。  
コンスルーを基板裏に立てます。窓が高く、同じ方向を向くようにします。  
![](img/IMG_4383.jpg)   
  
![](img/IMG_4385.jpg)   
立てたコンスルーにRaspberry Pi Picoを乗せたらはんだ付けします。    
![](img/IMG_4386.jpg)   
できるだけ垂直に力を加えてRaspberry Pi Picoを抜きます。  

### LEDのはんだ付け
LEDを取り付ける場合はメインボードに最初にはんだ付けします。  
 - [LEDの取り付け方](led.md)  

後からでも可能ですがホットスワップソケットにこてが当たり溶かしてしまう可能性があります。  

### ダイオード、リセットスイッチのはんだ付け

D1~D20まで取り付けます。  
足を曲げて裏から差し込みます。  
![](img/IMG_4392.jpg)   
ダイオードには向きがあります。三角形の先の棒と黒線を合わせましょう。  
  
表で更に足を曲げて抜けないようにします。  
![](img/IMG_4395.jpg)   
ダイオードと並行に曲げるとあとでキースイッチに干渉しにくいです。 
  
はんだ付けをして足を切ります。  
![](img/IMG_4396.jpg)   
  
  
リセットスイッチを裏から差し込み表ではんだ付けします。  
![](img/IMG_4397.jpg)   

### ソケットのはんだ付け
使うソケットの足に予備はんだをします。あらかじめ薄くはんだを乗せます。  
![](img/IMG_4401.jpg)    
ソケットを置いたらピンセットで押さえつけながらはんだを注いでいきます。入り組んでいて表面積が多いので多めに必要になります。  
![](img/IMG_4405.jpg)     

裏から見ると左右逆になっているのでソケットの位置に注意しましょう。  
![](img/IMG_4407.jpg)   

### ロータリーエンコーダーのはんだ付け
足を折らないようにホールに通します。  
![](img/IMG_4410.jpg)   
クリップの部分ははんだ付けしなくて大丈夫です。  
![](img/IMG_4412.jpg)   

### 動作確認
Raspberry Pi Picoを差し込んでUSBケーブルを繋ぎます。  
  
![](img/IMG_4414s.jpg)   
ソケットをピンセットで短絡したり、スイッチを挿して押したりしてキーが入力されるか調べます。  
  
問題がなければはんだ付けは終了です。お疲れ様でした。  
Raspberry Pi Picoを取り外して次の工程に進みましょう。  
  
## 組み立て
### スタビライザーの組み立てと取り付け
スタビライザーがあると2Uのキーの押下が安定します。無くても使えるのでお好みでお使いください。  
  
小さい方のパーツの穴が二つ開いている側を、大きいパーツの穴が開いている方向に合わせて組み合わせます。  
![](img/IMG_4416.jpg)  
金属の棒を下の穴に差し込みツメにパチっと音がするまで押し込んで完成です。
![](img/IMG_4420.jpg)    
  
商品によっては防音シートがついています。  
![](img/IMG_4427.jpg)  
角にスタビライザーを付けるとケースと干渉するためニッパーで切り落としています。  
![](img/IMG_4434.jpg)  
両側がツメになっているタイプとねじ止めをするタイプがあります。  
![](img/IMG_4435.jpg)  
ねじ止めだとキーキャップを抜くときに一緒にスタビライザーが抜けてしまうのを防げます。  
  
基板の大きい方の穴にツメをひっかけながら取り付けます。  
![](img/IMG_4426.jpg)  

### プレートの取り付け
アクリルから保護フィルムをはがします。割れやすいパーツもあるので気をつけてください。  

基板にトッププレートを乗せます。裏表、上下左右に気を付けましょう。  
![](img/IMG_4437.jpg)  

隅のキースイッチから差し込んで、トッププレートにツメを咬ませます。  
![](img/IMG_4438.jpg)  

全てのスイッチを取り付けました。  
![](img/IMG_4440.jpg)  
トッププレートは浮いていますが、スイッチのツメに引っかかっているため安定しているはずです。  

裏返して4隅にスペーサーを、ネジ（短）で取り付けます。  
![](img/IMG_4447.jpg)  

ミドルプレート1（5mm、穴が長方形に近い）、ミドルプレート2（3mm、穴が少し狭い）の順にスペーサーに通します。  
![](img/IMG_4448.jpg)  

Raspberry Pi Picoをピンを曲げないように取り付けてミドルプレート3を乗せます。  
![](img/IMG_4451.jpg)  

バックプレートをネジ（長）で組付けてゴム足を4隅に貼ります。  
![](img/IMG_4454.jpg)  

キーキャップを乗せたら組み立ては終わりです。
![](img/IMG_4460.jpg)  

早速USBケーブルでPCと接続しましょう。

## キーマップのカスタマイズ
ビルドガイドと同じレイアウトにするのであればこちらをそのまままお使いください。  
同様のテンキーとして使う場合もひな形にすると手間を省けると思います。
 - [keymap.rb](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.8/keymap.rb)

### キーコードの変更
PRK Firmwareドライブのkeymap.rbを開きます。  
上書き保存をするとその場で変更が反映されます。  

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
  
キーコードはこちらに載せていますので参考にしてください（バージョンによって違う可能性があります）。  
- https://github.com/Taro-Hayashi/PRKFirmware0.9.7Keycode  

### ロータリーエンコーダーのキーコード
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
kbd.define_mode_key :UNDO,   [ %i(KC_Z KC_LCTL), :nil, 150, 150 ]
~~~
例えばCtrl＋Zであればこのように定義します。  

### 文字列を入力するキーコード
~~~
kbd.define_mode_key :TEST, [ Proc.new { kbd.macro "aaaa" }, :KC_NO, 300, nil ]
~~~
あっているかわかりませんがこう定義するとaaaaが入力されました。  
00キーの場合上の同時押しの方が早かったのでそちらを使っています。  
  
キーの設定が終わったら完成です！

## その他
### 他の対応ファームウェアについて
#### QMKファームウェア
こちらのuf2ファイルをインストールしてください。
- [shotgun_cp_via.uf2](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.8/shotgun_cp_via.uf2)

QMKは公式にはRaspberry Pi Picoには対応していません。使用しているQMKファームウェアはせきごん様が独自にRP2040への対応を実現したものです。  
基本的な機能は実装済みのものを配布していますが、ご自分でコンパイルをしたい場合はこちらのページを参考にしてください。  
 - [RP2040対応のQMK(非公式)を動かす](https://scrapbox.io/self-made-kbds-ja/RP2040%E5%AF%BE%E5%BF%9C%E3%81%AEQMK(%E9%9D%9E%E5%85%AC%E5%BC%8F)%E3%82%92%E5%8B%95%E3%81%8B%E3%81%99)
 - [ファームウェアのコード](https://github.com/Taro-Hayashi/Shotgun-CherryPie/tree/main/qmk/keyboards/shotgun_cp)

Remap/VIAを使ってGUIでキーを入れ替えることができます。
 - [shotgun_cp.json](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.8/shotgun_cp.json)

#### KMKファームウェア
キーボードとして使えることは確認済みですが、私の理解が及ばないためLEDやロータリーエンコーダーの使いかたがよくわからず解説が書けませんでした。

#### ZMKファームウェア
まだ試せていません。

### プレートのデータ
 - [shotgun_cp_plates.zip](https://github.com/Taro-Hayashi/Shotgun-CherryPie/releases/download/0.9.8/shotgun_cp_plates.zip)  

発注先のルールに沿ってデータを修正してください。  

### 謝辞
foostan様のフットプリントを流用、改変して使わせていただきました。  
https://github.com/foostan/kbd/  
https://github.com/foostan/kbd/blob/master/LICENSE  

yoichiro様のフットプリントを流用、改変して使わせていただきました。  
https://github.com/yoichiro/yoichiro-kbd  
https://github.com/yoichiro/yoichiro-kbd/blob/main/LICENSE 

せきごん様がGPIO15を使っている場合でも正常に動くようにしてくださいました。 
https://github.com/sekigon-gonnoc/qmk_firmware/tree/rp2040

hasumikin様がPRK Firmwareでロータリーエンコーダーを複数個使用できるようにして、ロータリーエンコーダーの感度も上げてくださいました。  
https://github.com/picoruby/prk_firmware/

### 販売ページ
- BOOTH: https://tarohayashi.booth.pm/items/3430753

