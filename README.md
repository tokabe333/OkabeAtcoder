# 作ったものを適当に置く場所

### Languages
- C++
- C#
- Ruby
- Dart (使わない)

<br>

## C#のソースコード1枚で実行とデバッグができるやつ
C#のプロジェクトを作らなくてもソースコード1枚だけで実行できるやーつ<br>
binとかDebugとかのコンパイル系のファイルとかを吐き出さない<br>
.sln とか .csproj とかもいらない<br>
_csharp_template.csx のMainを書き換えればOK<br>
launch.json と合わせてデバッグ実行もできる(変数の状態も確認できる)<br>

<br>

## 環境構築

### Editor Config
- [VSCodeにEditorConfigプラグインを導入してコードフォーマットを統一する](https://www.asobou.co.jp/blog/web/editorconfig)
- [VSCodeでC#のブロック{}前後の改行の設定を変更する2023](https://aquasoftware.net/blog/?p=1975)
- Omnisharp.jsonはコード整形には機能しない
- .editorconfigを編集する (VSCode 拡張機能)


### dotnet script
プロジェクトを作らなくてもソースコード1枚で実行できる<br>
VSCodeではインテリセンスが機能しない(2024/12/47)<br>
→OmniSharpの機能でインテリセンスが効くっぽい

#### 参考サイト
- [dotnet-scriptを使ってC#でも書き捨てプログラムを](https://oucc.org/blog/articles/908/)
- [C# Scripting with dotnet-script in VScode - Intellisense and suggestions not working](https://www.reddit.com/r/csharp/comments/195y1ag/c_scripting_with_dotnetscript_in_vscode/)

#### 手順
- .NETをインストール(最初から入っている場合も多い)
- ```dotnet tool install -g dotnet-script```
- VSCode → Preferences → Dotnet > Server: Use Omnisharp をON
- ```dotnet script init``` (初回のみ)

#### 実行
- ```dotnet script <ファイル名>```

#### 提出
一番下の行の ```Kyopuro.Main()``` を消す<br>
(通常のC#ではMain()がエントリーポイントになってるのでOK)
