# 作ったものを適当に置く場所

### Languages
- C++
- C#
- Ruby
- Dart (使わない)

<br>

## 環境構築

### Editor Config
- [VSCodeにEditorConfigプラグインを導入してコードフォーマットを統一する](https://www.asobou.co.jp/blog/web/editorconfig)
- [VSCodeでC#のブロック{}前後の改行の設定を変更する2023](https://aquasoftware.net/blog/?p=1975)
- Omnisharp.jsonは動かない
- .editorconfigを編集する (VSCode 拡張機能)


### C# Script
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
- ```dotnet script <ファイル名>```