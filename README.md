# 7sPro キーマップ

HHKB配列でスペースキー分割が魅力的な左右分離型キーボード、7sProのキーマップです。

- Windows/Mac両方で概ね使用感を揃える
- PC側は日本語配列の設定のまま、英語配列のキーを入力できるようにする
- WindowsでUNIXキーバインドのよく使うものを再現する
- ホームポジションからの移動を減らすため、記号・テンキーのレイヤーを作成する

というワガママを実現しています。

## 使用リポジトリのバージョンなど
- qmk/qmk_firmware
  - `tag: 0.12.15`を使用
- koktoh/jtu_custom_keycodes
  - comit `9b164d50e30b02caf95fef78755b18dca9b67d1d` をコピーし、フォルダ内に配置

## 注意
作成した時期が古いため、QMK Firmwareやjtu_custom_keycodeなどのバージョンが古くなっています。  
最新のQMK Firmwareなどを使う場合、このリポジトリのコードではビルドできないのでご注意ください。