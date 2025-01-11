recdvb 

本プログラムは、dogeel/recdvb (https://github.com/dogeel/recdvb) の
フォークで、その目的はチャンネル情報の更新です。

変更点は次のものです。

 * チャンネル情報の定義部分を別ファイルとし、
   別ツール( https://github.com/kaikoma-soft/mkChConvTable )
   で生成したチャンネル情報のファイルを取り込み易くする。
 * チャンネル情報を最新のものにする。(2021/04/30)
 * コンパイル時の警告を無くす。
 * 文字コードを UTF-8 に統一

fork 直後からの変更履歴
 * 2021/06/01 ディズニーch の移動  BS03_2 → BS23_0
 * 2022/03/09 BSに 下記の 3局追加
           BSよしもと     BS23_1
           BSJapanext     BS23_2
           BS松竹東急     BS23_3

* 2024/06/08 
           NHKBSプレミアム   -> NHK に変更
           スターチャンネル1 -> スターチャンネル に変更
           スターチャンネル2 -> 停波により削除
           スターチャンネル3 -> 停波により削除
           など

* 2024/10/09
           NHKBSプレミアム   -> 停波により削除
           ＢＳ釣りビジョン  -> BS11_1 から BS3_2
           ＢＳアニマックス  -> BS13_2 から BS3_1

* 2024/11/11
            放送大学テレビ -> BS11_2 から BS13_2

* 2025/01/11
            BSJapanext(BS23_2) -> BS10(BS15_3)
            スターチャンネル   -> BS10スターch(BS15_1)


インストール方法は次の通りです。

  % mkdir /tmp/recdvb
  % cd /tmp/recdvb
  % git clone https://github.com/kaikoma-soft/recdvb .
  % ./autogen.sh
  % ./configure --enable-b25
  % make
  % sudo make install 
  % make maintainer-clean


以下はオリジナルの README
------------------------------------------------------
当フォークは、recpt1のDVBインターフェイスへの完全対応を目的としています。
コマンド指定体系は、recpt1との互換をほぼ保っておりますのでフロントエンド側の変更は最小限に抑えれます。


[recpt1からの変更点と備考]
・"--device"が廃止され変わりにDVBデバイスを指定する"--dev n"を追加
  DVBデバイス自動選択機能があるので"--device"と同様に"--dev"を特に指定する必要はありません。

・DVBデバイスの自動指定はデバイスを昇順で利用していきます。
  任意の順番に変更したい場合は、pt1_dev.hを編集して下さい。

・BS/CSチャンネル指定にTSID(10進数または16進数)による指定法を追加されました。
  これによりチャンネル指定方法は、BSは3通りCSは2通りになります。

  例）HNK BS1
  サービスIDによる指定法(BSのみ・放送局再編成があると使えなくなる場合あり)
  $ recdvb --sid 101 101 10 a.ts

  トランスポンダーNoによる指定法
  $ recdvb --sid 101 BS15_0 10 a.ts

  TSIDによる指定法
  $ recdvb --sid 101 0x40f1 10 a.ts

・LNB給電まわりの仕様がPT1キャラクターデバイスと違います。
  PC電源投入時にLNB給電が自動で開始されません。(未確認)
  "--lnb"の挙動が変わります。録画時に給電指示をした場合は、終了時にLNB給電を停止します。
  恒久的に遷移させたい場合は、以下の様にデバイスとLNB電圧の2つだけを指定してください。

  $ recdvb --dev 0 --lnb 15

・"--sid"オプションに "caption"(字幕),"data"(データ放送),"other"(その他)が追加されます。
  これらは、初期状態では無効化されています。
  無指定時にはこれらのストリームが出力されないので混乱を避けるためです。
  有効化する場合は、下記のようにビルド時に環境変数"EXTRA_SID=1"を渡してください。

  $ EXTRA_SID=1 make


===== 注意 =====
本プログラムはVer1.2.0のフォークです。Ver1.3.0とは別物なのであしからず。


version 1.2.1.1 (2016/06/12)
・DVBデバイス自動時にDVBデバイスで受信できない放送波のチャンネルを指定した場合の不具合を修正

version 1.2.1.0 (2016/03/26)
・BS/CSとCATVおよびLNB給電に対応
  BonDriverProxy_LinuxのBonDriver_DVB.cppを参考にしてtune処理などを修正
・チャンネル指定体系とその処理をrecpt1のものに差し戻し新たにTSIDが扱えるように拡張
・デバイス指定の自動化
  recpt1ではpt1_dev.hの編集が必要な場合があったが recdvbでは/dev/dvb/adapter*を検索するのでメンテナンスフリーとなった
・tssplitter_lite.cを最新と思われるものに更新
・tssplitter_liteをコマンド化
・recdvbctrlをrecpt1ctrlにリネーム
・checksignalをchkdvbsignalにリネーム
