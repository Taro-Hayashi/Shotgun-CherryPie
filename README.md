# Shotgun チェリーパイ ビルドガイド

## キット内容
![]()
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
|スタビライザー|必要数|無くても動きます|[遊舎工房様販売ページ](https://shop.yushakobo.jp/collections/all-keyboard-parts/Stabilizer)|
|Micro USB ケーブル|1||[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/usb-cable-micro-b-0-8m)|

### オプション
|部品名|数|||
|-|-|-|-|
|ロータリーエンコーダ|～5|EC11/EC12||
|ノブ|～5|直径19mmまで||
|SK6812MINI-E|12、もしくは28|12個で裏面のみ、28個で両面になります。|[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/sk6812mini-e-10)|
|1N4148W|13|表面実装タイプのダイオード|[遊舎工房様販売ページ](https://shop.yushakobo.jp/products/a0800di-02-100)|


### 必要な工具
|工具名| |
|-|-|
|はんだごて||
|はんだごて置き場||
|鉛入りはんだ||
|精密ドライバー||
|ニッパー等ダイオードの足を切れるもの|金属用でない場合刃こぼれします。|

### あると便利な工具（★は特におすすめです）
|工具名||
|-|-|
|耐熱シリコンマット||
|斜めに切ったタイプのこて先|★|
|温度調節可能なはんだごて|300度-350度前後|
|フラックス|★|
|ピンセット||
|テスター||
|フラックスリムーバー|★|
|マスキングテープ||
|はんだ吸い取り線||
|はんだ吸い取り器||

## 組み立て
### レイアウトの決め方  
RemapのKEYMAPのページにアクセスしてください。  
 - aaaa

Layout Optionsの項目をオンオフすることでレイアウトを変更することができます。   
切り替えてどのようなキーパッドにするか決めましょう。  
このビルドガイドではロータリーエンコーダーを1つ、2Uキーを二つ使ったテンキーにします。

### ファームウェアの書き込み
最新版のPRKファームウェアとこちらのkeymap.rbをダウンロードしてください。  
 - pico ruby / prk firmware vvreleases  
 - [keymap.rb]()  

Raspberry Pi Picoを、BOOTSELボタン押しながらUSBケーブルでPCと接続すると、RI-RPというUSBメモリとして認識されます。
持つときは基板の表面ではなく辺を持ってください。
uf2ファイルを書き込むと、自動的に再起動して代わりにPRK Firmwareというドライブとして認識されます。  
そのドライブにkeymap.rbをドラッグアンドドロップするとRaspberry Pi Picoをキーボードとして使えるようになります。  

### はんだ付け
はんだ付けのやり方は動画で見るとわかりやすいです。  
パーツは思ったより壊れないので落ち着いて作業すると失敗しにくいです。  
 - ホームセンターのDCMさんの解説動画(58秒～) https://www.youtube.com/watch?v=JFQg_ObITYE&t=58s  
  
LEDを取り付ける場合は最初にはんだ付けします。  
 - [LEDの取り付け方](led.md)  

後からでも可能ですがホットスワップソケットにこてが当たり溶かしてしまう可能性があります。  
  
#### Raspberry Pi Picoのはんだ付け

まずはRaspberry Pi Picoにコンスルーをはんだ付けします。  
コンスルーを基板裏に立てます。窓が高く、同じ方向を向くようにします。  
!  
  
立てたコンスルーにRaspberry Pi Picoを乗せたらはんだ付けします。  
!  
LEDを取り付けた場合は一度PCと繋いですべてが発光するかを確認してください。  
できるだけ垂直に力を加えてRaspberry Pi Picoを抜きます。  

#### ダイオード、リセットスイッチのはんだ付け

D1~D20まで取り付けます。  
足を曲げて裏から差し込みます。
!  
ダイオードには向きがあります。三角形の先の棒と黒線を合わせましょう。  
  
表で更に足を曲げて抜けないようにします。  
!  
ダイオードと並行に曲げるとあとでキースイッチに干渉しにくいです。 
  
はんだ付けをして足を切ります。  
!  
  
  
リセットスイッチを裏から差し込み表ではんだ付けします。  
!

#### リセットスイッチのはんだ付け
#### ソケットのはんだ付け
#### ロータリーエンコーダーのはんだ付け
### 動作確認
### プレートの取り付け
### キーマップのカスタマイズ



## その他
### その他の対応ファームウェアについて
#### QMKファームウェア
こちらのuf2ファイルをインストールしてください。
- [shotgun_cp_via.uf2]()
QMKは公式にはRaspberry Pi Picoには対応していません。使用しているQMKファームウェアはせきごん様が独自にRP2040への対応を実現したものです。  
基本的な機能は実装済みのものを配布していますが、ご自分でコンパイルをしたい場合はこちらのページを参考にしてください。  
 - [RP2040対応のQMK(非公式)を動かす](https://scrapbox.io/self-made-kbds-ja/RP2040%E5%AF%BE%E5%BF%9C%E3%81%AEQMK(%E9%9D%9E%E5%85%AC%E5%BC%8F)%E3%82%92%E5%8B%95%E3%81%8B%E3%81%99)
 - ファームウェアのコード

QMKファームウェアを使うとRemapでブラウザからキーマップを変更することができます。
Google ChromeかMicrosoft Edgeでアクセスしてください。
 - Remap

#### KMKファームウェア
キーボードとして使えることは確認済みですが、私の理解が及ばないためLEDやロータリーエンコーダーの使いかたがよくわからず解説が書けませんでした。

#### ZMKファームウェア
まだ試せていません。

### プレートのデータ
 - shotgun_cp_plates.zip  

発注先のルールに沿ってデータを修正してください。  

### 謝辞
foostan様のフットプリントを流用、改変して使わせていただきました。  
https://github.com/foostan/kbd/  
https://github.com/foostan/kbd/blob/master/LICENSE  

yoichiro様のフットプリントを流用、改変して使わせていただきました。  
https://github.com/yoichiro/yoichiro-kbd 
https://github.com/yoichiro/yoichiro-kbd/blob/main/LICENSE 

せきごん様のRP2040ブランチ。  
https://github.com/sekigon-gonnoc/qmk_firmware/tree/rp2040

hasumikin様がPRK Firmwareでロータリーエンコーダーを複数個使用できるようにしてくださいました。  
https://github.com/picoruby/prk_firmware/

### 販売ページ
- BOOTH: https://tarohayashi.booth.pm/items/3430753

