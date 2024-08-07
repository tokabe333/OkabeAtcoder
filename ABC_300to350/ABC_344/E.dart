import "dart:io";
import "dart:math";
import "dart:collection";

typedef bi = BigInt;
typedef vi = List<int>;
typedef vd = List<double>;
typedef vb = List<bool>;
typedef pii = (int, int);
typedef pdd = (double, double);
typedef mii = Map<int, int>;
typedef mid = Map<int, double>;
typedef mis = Map<int, String>;
typedef msi = Map<String, int>;
typedef msd = Map<String, double>;
typedef hmii = HashMap<int, int>;
typedef hmid = HashMap<int, double>;
typedef hmis = HashMap<int, String>;
typedef hmssi = HashMap<String, int>;
typedef hmssd = HashMap<String, double>;
typedef si = Set<int>;
typedef sd = Set<double>;

// 1次元配列の出力
void printlist(List list) {
  for (int i = 0; i < list.length; ++i) {
    stdout.write("${list[i]} ");
  }
  stdout.write("\n");
} // end of func

// 2次元配列の出力
void printllist(List list) {
  for (int i = 0; i < list.length; ++i) {
    for (int j = 0; j < list[i].length; ++j) {
      stdout.write("${list[i][j]} ");
    }
    stdout.write("\n");
  }
} // end of func

/// 1行読み込み(readlinesyncはString?になるので)
String readline() {
  return stdin.readLineSync()!;
} // end of func

/// 数字を1つ読み込み
int readint() {
  return int.parse(readline());
}

/// 数字を読み込んで配列にして返す
List readints() {
  return readline().split(" ").map((yaju) => int.parse(yaju)).toList();
}

/// flush無しの出力
void writeln(Object obj) {
  stdout.write("${obj}\n");
} // end of func

/// 要素数を指定した配列の初期化
listgen(num, {init = null}) => List.generate(num, (_) => init);

/// 要素数を指定した2次元配列の初期化
llistgen(height, width, {init = null}) => List.generate(height, (_) => List.generate(width, (__) => init));

void main() {
  int n = readint();
  var arr = readints();
  arr.insert(0, 0);
  arr.add(-1);

  final next = hmii();
  final prev = hmii();
  for (int i = 0; i < arr.length - 1; ++i) {
    prev[arr[i + 1]] = arr[i];
    next[arr[i]] = arr[i + 1];
  }

  int q = readint();
  int hoge, x, y;
  for (int qqq = 0; qqq < q; ++qqq) {
    final line = readints();
    if (line[0] == 1) {
      x = line[1];
      y = line[2];
      final tugi = next[x]!;
      next[x] = y;
      prev[y] = x;
      next[y] = tugi;
      prev[tugi] = y;
    } else {
      x = line[1];
      prev[next[x]!] = prev[x]!;
      next[prev[x]!] = next[x]!;
      prev.remove(x);
      next.remove(x);
    }
  }

  final ans = [];
  hoge = next[0]!;
  while (hoge != -1) {
    // stdout.write("${hoge} ");
    ans.add(hoge);
    hoge = next[hoge]!;
  }
  print(ans.join(" "));

  return;
} // end of main
