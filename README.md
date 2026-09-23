# Kaepi2022 Recovery

チャレンジパッドNeo/Nextで利用できるリカバリーです。

GUIメニューの有効化やadb shellなどを利用できるようにしました。

**対応機種**
* **チャレンジパッドNext**

  TAB-A05-BA1

* **チャレンジパッドNeo**
  
  TAB-A05-BD

---

## 利用できるコマンド等
以下のコマンドはadb shellから利用可能です。

| バイナリ / コマンド | 出典 | 用途 | 備考 |
| --- | --- | --- | --- |
| `recovery` | AOSP系Recovery executable | Recovery UI・update ZIPの導入 | 起動時に自動実行されます。 |
| `adbd` | Android 9 `adbd` | Recovery ADB daemon | RSA認証無効。shellは非root（`uid=2000`）です。 |
| `sh` | mksh（Android 9 / ARM64ビルド） | 対話shell・update-binaryスクリプトの実行 | `META-INF/com/google/android/update-binary` の `#!/sbin/sh` に対応。 |
| `toybox` | Toybox | 基本Unixコマンド群 | コンパイル済みappletはすべて `/sbin/<コマンド名>` から実行可能。 |
| `getprop` | Android property utility | Androidプロパティの取得 | `getprop 名前` または `getprop`。 |
| `setprop` | Android property utility | Androidプロパティの設定 | Recoveryの再起動ラッパーから使用。 |
| `reboot` | Kaepi Recovery wrapper | Androidの `sys.powerctl` 経由で再起動 | `recovery`、`bootloader`、`fastboot`、`sideload`、`poweroff` に対応。非root shellでは `toybox reboot` を使わないでください。 |
| `unzip` | BusyBox | update ZIPの展開・内容確認 | `unzip ZIPファイル`。 |
| `mke2fs_static` | AOSP/e2fsprogs | ext filesystemの作成 | 静的リンク済みARM64バイナリ。 |
| `e2fsdroid_static` | AOSP | ディレクトリツリーからext imageを作成 | 静的リンク済みARM64バイナリ。 |
| `yaju` | Kaepi2022 | インスターエッグ 810 | `yaju --get_yajuaa` |

## Toybox applet

| 分類 | 主な利用可能コマンド |
| --- | --- |
| ファイル・パス操作 | `cat`, `cp`, `mv`, `rm`, `mkdir`, `rmdir`, `ln`, `readlink`, `realpath`, `find`, `stat`, `file`, `touch`, `truncate`, `install`, `chmod`, `chown`, `chgrp`, `ls`, `pwd`, `du`, `df` |
| テキスト・データ処理 | `base64`, `cmp`, `comm`, `cut`, `expand`, `fmt`, `grep`, `head`, `hexedit`, `md5sum`, `od`, `paste`, `patch`, `rev`, `sed`, `seq`, `sha1sum`, `sort`, `split`, `strings`, `tac`, `tail`, `tee`, `uniq`, `wc`, `xxd` |
| mount・ストレージ | `mount`, `umount`, `mountpoint`, `blkid`, `blockdev`, `losetup`, `partprobe`, `fstype`, `fsfreeze`, `mkswap`, `swapon`, `swapoff`, `sync` |
| プロセス操作 | `ps`, `top`, `pgrep`, `pidof`, `pkill`, `kill`, `killall`, `killall5`, `nice`, `renice`, `timeout`, `setsid`, `taskset`, `chrt`, `ionice`, `iorenice`, `uptime` |
| システム診断 | `dmesg`, `free`, `nproc`, `uname`, `hostname`, `id`, `groups`, `lsmod`, `lsusb`, `lspci`, `vmstat`, `sysctl`, `readahead` |
| ネットワーク | `ifconfig`, `netstat`, `nc`, `netcat`, `ftpget`, `ftpput`, `microcom` |
| アーカイブ・変換 | `cpio`, `bunzip2`, `bzcat`, `dos2unix`, `unix2dos`, `uudecode`, `uuencode` |
| その他 | `clear`, `date`, `env`, `printenv`, `printf`, `sleep`, `time`, `which`, `whoami`, `yes` |

`toybox` を引数なしで実行すると、そのimageに収録された正確なapplet一覧を確認できます。

---

## License

Kaepi2022 Recovery の自作部分（ramdisk構成、init設定、ビルドスクリプト、ドキュメント）は、Apache License 2.0 の下で提供します。詳細は [LICENSE](LICENSE) を参照してください。

### Kaepi2022 Recovery FreeKey

`kaepi2022-recovery-freekey/keys/` の鍵素材は、誰でもRecovery用update ZIPを作成・署名・改変できることを目的として公開しています。これらの鍵素材は CC0-1.0 相当として扱います。

この鍵を信頼するRecoveryは、鍵を取得した任意の第三者が署名したupdate ZIPを受け入れます。これは意図した仕様であり、セキュリティ境界ではありません。

### Third-party components

| Component | License |
| --- | --- |
| AOSP Recovery source | Apache License 2.0 |
| Toybox | 0BSD |
| mksh | MirOS Licence |
| BusyBox (`unzip`) | GPL-2.0-only |

BusyBoxを含む配布物には、対応するソースコードおよびGPL-2.0のライセンス文書を添付します。

### Device-vendor components

Benesse/Panasonic/MediaTek等の既存Recovery imageに由来するkernel、Recovery executable、firmware設定、vendorバイナリは、本プロジェクトのApache-2.0ライセンスの対象外です。各ファイルの権利は元の権利者に帰属します。

利用者は、これらのバイナリの使用・改変・再配布について、適用されるライセンスおよび法令を各自で確認してください。


---

## 開発・協力
* [kaepi2022 / MineKura](https://github.com/kaepi2022)
* [butoryu](https://github.com/butoryu1-2881)
