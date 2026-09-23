# Kaepi Recovery FreeKey

これは、デフォルトのKaepi2022 Recoveryを利用する人がリカバリー更新用zipファイルを自由に作成、署名、当リカバリーで実行するために公開しているAndroidリカバリー／OTA署名キーです。
この鍵を利用している更新用ファイルは基本的に実行できてしまうのでプロジェクトで利用する場合はこれらの鍵を変更することをお勧めします。

## ファイル

- `keys/kaepi_recovery_freekey.pk8` — Android `signapk` PKCS#8 private key.
- `keys/kaepi_recovery_freekey.x509.pem` — public X.509 certificate for
  `signapk` and release verification.
- `keys/kaepi_recovery_freekey.pem` — conventional PEM private-key form.
- `keys/kaepi_recovery_freekey.x509.der` — DER form of the public certificate.
- `keys/recovery.keys` — AOSP Recovery `/res/keys` text generated from the
  certificate (SHA-256: `6AD17633CE7A0AF3947091CF9527250CC02D0F7AB351460A932D3C5379CA06A1`).

## zipの署名方法

```text
java -jar signapk.jar \
  keys/kaepi_recovery_freekey.x509.pem \
  keys/kaepi_recovery_freekey.pk8 \
  input-unsigned.zip output-signed.zip
```

リカバリーが特定の公開鍵で署名されたアップデート用zipファイルを受け入れるようにするには、
その公開鍵をリカバリイメージ内の `/res/keys`（信頼された鍵のセット）に含める必要があります。
