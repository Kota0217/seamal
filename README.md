# seamal
水中用マイクロロボット開発用リポジトリ


## リンク集
### マイコン関係
* [データシート](https://akizukidenshi.com/download/ds/st/stm32f303x6_st32f303x8.pdf) (ピン配置はp.29)
* [タイマー割り込みについて](https://mia-0032.hatenablog.jp/entry/mbed-os-events-library)
* 開発環境はMbed Studio 
  * mbed os 6.3.0で動作確認を行う (2021/07/27 石関)


## 作業記録

### 2021/07/27 (火)　石関記録
* EventQueueのcall_everyで割り込み処理を行うコードを書いたが、割り込みとmainのwhile(1)が同時に実行されない
  * dispatchをwhileより前に置くと、割り込み処理だけ回る
  * dispatchをwhileより後に置くと、whileだけ回る

### 2021/07/26 (月)　石関記録
* stm32f303k8を入手し、変換基板にはんだ付けした
* stm32f030 nucleo64を使ってプログラムを書き込んだ
  * 開発環境　Mbed Studio
  * Lチカを行うプログラムを書き込んだ
* 動作を確認した
* デバッガーのTX,RXのピンをf303k8に接続したら、UART通信ができた


### 2021/07/25 (日)　石関記録
* Arudiono IDE上でボードマネージャーからstmのライブラリをインストールした


